#!/bin/bash

set -ex

export MSYS2_FC_CACHE_SKIP=1

pacman --noconfirm -Suy

pacman --noconfirm -S --needed \
    base-devel \
    git \
    mingw-w64-"$MSYS2_ARCH"-glib2 \
    mingw-w64-"$MSYS2_ARCH"-toolchain \
    mingw-w64-"$MSYS2_ARCH"-gtk3 \
    mingw-w64-"$MSYS2_ARCH"-SDL2 \
    python