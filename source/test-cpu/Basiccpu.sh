#!/bin/bash

cd build-cpu && cmake .. && make && cd ..

echo Source file location $1
echo Destination location $2

./build-cpu/Basiccpu $1 $2
