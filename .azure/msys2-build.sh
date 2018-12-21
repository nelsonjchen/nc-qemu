#!/bin/bash

set -ex

./configure \
  --enable-gtk \
  --enable-sdl \
  --target-list=x86_64-softmmu \
  --disable-stack-protector \
  --disable-werror

make -j 2

file x86_64-softmmu/qemu-system-x86_64.exe

x86_64-softmmu/qemu-system-x86_64.exe --version
