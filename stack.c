#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"



//instructionStackHead=NULL;
//dataStackHead=NULL;

void makeDataLIST(int instructionSet[], int supposedSIZE ){  // pushing
// Instruction Stack-List
   int i;
   for(i=0;i<supposedSIZE;i++){
    int newIP=instructionSet[i];
    instructionStack *currentStack=(instructionStack *)malloc(sizeof(instructionStack*));
        currentStack->ip=newIP;
        strcpy(currentStack->instructionTYPE,instructionToString(newIP));
        currentStack->nextStack=instructionStackHead;
        instructionStackHead=currentStack;
  }
// Data Stack-List
for(i=0;i<supposedSIZE;i++){
    int newSP=STACK[i];
    dataStack *currentStack=(dataStack *)malloc(sizeof(dataStack*));
       currentStack->sp=newSP;
       currentStack->nextStack=dataStackHead;
       dataStackHead=currentStack;
}
}
char *instructionToString(int instructionType){
    char * instructionName;
switch(instructionType){
       case ADD:
         instructionName="ADD";
           break;
       case SUB:
         instructionName="SUB";
           break;
       case MUL:
         instructionName="MUL";
           break;
       case DIV:
         instructionName="DIV";
           break;
       case AND:
         instructionName="AND";
           break;
       case NOT:
         instructionName="NOT";
           break;
       case OR:
         instructionName="OR";
           break;
       case XOR:
         instructionName="XOR";
           break;
       case LOAD:
         instructionName="LOAD";
           break;
       case STOR:
         instructionName="STOR";
           break;
       case PUSH:{
           instructionName="PUSH";
           break;}
       case POP:
           instructionName="POP";
           break;
       case CALL:
           instructionName="CALL";
           break;
       case BR:
           instructionName="BR";
           break;
       case RET:
           instructionName="RET";
           break;
       case JMP:
           instructionName="JMP";
           break;
       case PRINT:
           instructionName="PRINT";
           break;
       case HALT:
           instructionName="HALT";
           break;}
           return instructionName;
}
int instructionToInt(char * instructionType){
    int instruction;
      if (!strcmp(instructionType,"ADD")) instruction=0;
      if (!strcmp(instructionType,"SUB")) instruction=1;
      if (!strcmp(instructionType,"MUL")) instruction=2;
      if (!strcmp(instructionType,"DIV")) instruction=3;
      if (!strcmp(instructionType,"AND")) instruction=4;
      if (!strcmp(instructionType,"NOT")) instruction=5;
      if (!strcmp(instructionType,"OR")) instruction=6;
      if (!strcmp(instructionType,"XOR")) instruction=7;
      if (!strcmp(instructionType,"LOAD")) instruction=8;
      if (!strcmp(instructionType,"STOR")) instruction=9;
      if (!strcmp(instructionType,"PUSH")) instruction=10;
      if (!strcmp(instructionType,"POP")) instruction=11;
      if (!strcmp(instructionType,"CALL")) instruction=12;
      if (!strcmp(instructionType,"BR")) instruction=13;
      if (!strcmp(instructionType,"RET")) instruction=14;
      if (!strcmp(instructionType,"JMP")) instruction=15;
      if (!strcmp(instructionType,"PRINT")) instruction=16;
      if (!strcmp(instructionType,"HALT")) instruction=17;

           return instruction;
}



void showStack(int supposedSIZE){
    int i;
    printf("\n");
    for(i=0;i<supposedSIZE;i++){
        printf("Stack element %d. ->> %d\n",i,STACK[i]);
    }
    printf("All stack elements demonstrated..\n");
}

void duplicateArrays(int arr1[], int arr2[]){
 int arraySize=sizeof(arr2)/sizeof(arr2[0]);
 int i;
 for(i=0;i<arraySize;i++){
    arr1[i]=arr2[i];
 }
}


