 #!/bin/bash

set -e

./configure \
  --enable-gtk \
  --enable-sdl \
  --target-list=x86_64-softmmu \
  --disable-werror

make -j 2

file x86_64-softmmu/qemu-system-x86_64.exe
