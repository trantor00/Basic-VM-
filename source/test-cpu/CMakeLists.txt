cmake_minimum_required(VERSION 3.10)
project(Basiccpu)


add_executable(Basiccpu
 ../cpu/cpu.h
 ../cpu/cpu.c
 ../cpu/cpuIO.c
 ../stack-lists/stack.h
 ../stack-lists/stack.c
 ../cpu/processorInstructions.h
 ../test-cpu/testCPU.c
)
