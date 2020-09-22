#ifndef CPU_H_
#define CPU_H_

#include "stack-lists/stack.h"
#include "processorInstructions.h"


uint16_t IP;  // instruction pointer
uint16_t SP=-1;  // stack pointer


//prototypes

void cpu(int32_t instructionSet[], uint16_t ip, uint16_t memorysize, uint16_t CODESIZE, uint8_t debug);
void resetcpu();




#endif // CPU_H_
