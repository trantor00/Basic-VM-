#!/bin/bash


#Source file can be changed or edited etc..
ex1="../../examples/sourcefile"
ex2="../../examples/assembledfile"
ex3="../../examples/compiledfile"

cd Assembler
./assembler.sh $ex1 $ex2

printf  "\nSource file is assembled!\n"

sleep 3

cd .. && cd test-cpu
./Basiccpu.sh $ex2 $ex3

printf "\nAssembled file is compiled by the cpu!\n"




