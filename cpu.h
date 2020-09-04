#ifndef CPU_H_
#define CPU_H_

#include "stack.h"
#include "processorInstructions.h"

int IP;  // instruction pointer
int SP=-1;  // stack pointer


//prototypes

void cpu(int instructionSet[], int ip, int memorysize, int CODESIZE);



#endif // CPU_H_
