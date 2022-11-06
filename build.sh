#!/bin/sh

rm -rf build && mkdir build

cmake -S . -B build -DDEBUG=on

make -C build
