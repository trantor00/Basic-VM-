#ifndef STACK_H_
#define STACK_H_
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#include "../cpu/processorInstructions.h"

#define MAX_SIZE 1000 // max_size

int32_t RAM[MAX_SIZE];
int32_t INSTRUCTIONS[MAX_SIZE];
int32_t DATA[MAX_SIZE];

int32_t instructionSize;
int8_t debug;


typedef struct instructionStack{
	int16_t ip;
	char instructionTYPE[5];
    struct instructionStack *nextStack;

}instructionStack;

typedef struct dataStack{
  int16_t sp;
  struct dataStack *nextStack;
}dataStack;

//struct heads
 instructionStack *instructionStackHead;
 dataStack *dataStackHead;

//prototypes
void makeDataLIST(int32_t instructionSet[],int32_t supposedSIZE);
void showLinkedStacks();
char *instructionToString(int32_t instructionType);
int instructionToInt(char * instructionType);
void showStack(int32_t supposedSIZE);
void duplicateArrays(int32_t arr1[], int32_t arr2[]);   //first array must be empty!
// CPU IO
bool sourceInput();
bool compiledOutput();

#endif // STACK_H_
