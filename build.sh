#!/bin/bash

rm -rf cmake
mkdir -p cmake
cd cmake ;
cmake ..
make -j6

