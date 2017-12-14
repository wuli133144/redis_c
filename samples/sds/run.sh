#!/bin/bash

file=./bin/list

if [ -e $file  ] ;then
    exec ./bin/list
else
    exec cmake-script.sh
    exec  ./bin/list
fi
