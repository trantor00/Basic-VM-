#ifndef STACK_H_
#define STACK_H_
#include "processorInstructions.h"

#define MAX_SIZE 100 // max_size

int DATA[MAX_SIZE];
int STACK[MAX_SIZE];
int INSTRUCTIONS[10];

typedef struct instructionStack{
	int ip;
	char instructionTYPE[5];
    struct instructionStack *nextStack;

}instructionStack;

typedef struct dataStack{
  int sp;
  struct dataStack *nextStack;
}dataStack;

//struct heads
 instructionStack *instructionStackHead;
 dataStack *dataStackHead;

//prototypes
void makeDataLIST(int instructionSet[],int supposedSIZE);
char *instructionToString(int instructionType);
void showStack(int supposedSIZE);
void duplicateArrays(int arr1[], int arr2[]);   //first array must be empty!

#endif // STACK_H_
