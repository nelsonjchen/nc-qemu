#!/bin/bash

set -ex

# Link DLLS for copying
if [ "$MSYS2_ARCH" = "x86_64" ]; 
then
  mkdir -p dll/w64
  ln -sfn /mingw64/bin/libbz2-1.dll dll/w64/libbz2-1.dll
  ln -sfn /mingw64/bin/libcairo-2.dll dll/w64/libcairo-2.dll
  ln -sfn /mingw64/bin/libgdk-3-0.dll dll/w64/libgdk-3-0.dll
  ln -sfn /mingw64/bin/libgdk_pixbuf-2.0-0.dll dll/w64/libgdk_pixbuf-2.0-0.dll
elif [ "$MSYS2_ARCH" = "i686" ];
 then
  mkdir -p dll/w32
  ln -sfn /mingw32/bin/libbz2-1.dll dll/w32/libbz2-1.dll
  ln -sfn /mingw32/bin/libcairo-2.dll dll/w32/libcairo-2.dll
  ln -sfn /mingw32/bin/libgdk-3-0.dll dll/w32/libgdk-3-0.dll
  ln -sfn /mingw32/bin/libgdk_pixbuf-2.0-0.dll dll/w32/libgdk_pixbuf-2.0-0.dll
fi 

# Stack protector disabled for windows to work around crashing issue
# https://www.mail-archive.com/qemu-devel@nongnu.org/msg556517.html
./configure \
  --enable-gtk \
  --enable-sdl \
  --target-list=x86_64-softmmu \
  --prefix=out \
  --disable-stack-protector \
  --disable-werror

make -j 2

file x86_64-softmmu/qemu-system-x86_64.exe

x86_64-softmmu/qemu-system-x86_64.exe --version

make install
