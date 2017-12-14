#!/bin/bash


cd ./build/

echo "now current directory is ./build/n"

cmake .. -DCMAKE_INSTALL_PREFIX=../ && make && make install
