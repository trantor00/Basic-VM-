#!/bin/bash

cd build-assembler && cmake .. && make && cd ..

echo Source file location $1
echo Destination location $2

./build-assembler/BasicAssembler $1 $2
