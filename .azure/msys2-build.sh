#!/bin/bash

set -ex

# Write to an out directory
mkdir -p out

# Link DLLS for copying
if [ "$MSYS2_ARCH" = "x86_64" ]; 
then
  mkdir -p dll/w64
  ln -sfn /mingw64/bin/libbz2-1.dll dll/w64/libbz2-1.dll
  ln -sfn /mingw64/bin/libcairo-2.dll dll/w64/libcairo-2.dll
  ln -sfn /mingw64/bin/libgdk-3-0.dll dll/w64/libgdk-3-0.dll
  ln -sfn /mingw64/bin/libgdk_pixbuf-2.0-0.dll dll/w64/libgdk_pixbuf-2.0-0.dll
  ln -sfn /mingw64/bin/libglib-2.0-0.dll dll/w64/libglib-2.0-0.dll
  # WHPX is only supported on 64 bit Windows.
  WINSDK="/c/Program Files (x86)/Windows Kits/10"
  WINSDKVER=10.0.17134.0
  cp "$WINSDK/Include/$WINSDKVER/um/"WinHv* /mingw64/include
  cp "$WINSDK/Lib/$WINSDKVER/um/x64/"WinHv* /mingw64/lib
  cp dll/w64/*.dll out/
elif [ "$MSYS2_ARCH" = "i686" ];
 then
  mkdir -p dll/w32
  ln -sfn /mingw32/bin/libbz2-1.dll dll/w32/libbz2-1.dll
  ln -sfn /mingw32/bin/libcairo-2.dll dll/w32/libcairo-2.dll
  ln -sfn /mingw32/bin/libgdk-3-0.dll dll/w32/libgdk-3-0.dll
  ln -sfn /mingw32/bin/libgdk_pixbuf-2.0-0.dll dll/w32/libgdk_pixbuf-2.0-0.dll
  ln -sfn /mingw32/bin/libglib-2.0-0.dll dll/w32/libglib-2.0-0.dll
  cp dll/w32/*.dll out/
fi 

CONFIGURE_ARGS=()
CONFIGURE_ARGS+=(--enable-gtk)
CONFIGURE_ARGS+=(--enable-sdl)
CONFIGURE_ARGS+=(--target-list=x86_64-softmmu)
# WHPX is only supported on 64 bit Windows.
if [ "$MSYS2_ARCH" = "x86_64" ]; then
  CONFIGURE_ARGS+=(--enable-whpx)
fi
# Stack protector disabled for windows to work around crashing issue
# https://www.mail-archive.com/qemu-devel@nongnu.org/msg556517.html
CONFIGURE_ARGS+=(--disable-stack-protector)
# Write to Out
CONFIGURE_ARGS+=(--prefix=out)
# Per https://qemu.weilnetz.de/doc/BUILD.txt's guidance.
CONFIGURE_ARGS+=(--disable-werror)

./configure "${CONFIGURE_ARGS[@]}"

MAKE_JOB_COUNT="${NUMBER_OF_PROCESSORS:-2}"

make -j "$MAKE_JOB_COUNT"

file x86_64-softmmu/qemu-system-x86_64.exe

x86_64-softmmu/qemu-system-x86_64.exe --version

cp x86_64-softmmu/qemu-system-x86_64.exe out/
cp x86_64-softmmu/qemu-system-x86_64w.exe out/

make install
