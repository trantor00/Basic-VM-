cmake_minimum_required(VERSION "3.18.1")
project(basicvm C)


include_directories( basicvm
 cpu.h
 stack.h
 cpuInstructions.h)

add_executable(basicvm
 testCPU.c
 cpu.c
 stack.c
 cpuIO.c
 )