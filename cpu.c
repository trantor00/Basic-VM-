#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpu.h"

void cpu(int instructionSet[], int ip, int memorysize, int CODESIZE){
   printf("New instruction set inserted.. Size of set= %d\n", CODESIZE);
   IP = ip;
   int data[CODESIZE];
   int stack[CODESIZE];
   duplicateArrays(DATA,data); duplicateArrays(STACK,stack); duplicateArrays(INSTRUCTIONS, instructionSet);

   while(IP< CODESIZE){
        printf("Instruction turn= %d | Instruction type= %s\n",IP,instructionToString(instructionSet[IP]));
      int opcode=instructionSet[IP];  //fetching from the given instructionSet
     IP++;
     switch(opcode){
       case ADD:
            SP++;
            STACK[SP]=STACK[SP-1]+STACK[SP-2];
           break;
       case SUB:
            SP++;
            STACK[SP]=STACK[SP-1]-STACK[SP-2];
           break;
       case MUL:
            SP++;
            STACK[SP]=STACK[SP-1]*STACK[SP-2];
           break;
       case DIV:
            SP++;
            STACK[SP]=STACK[SP-1]/STACK[SP-2];
           break;
       case AND:
            SP++;
            STACK[SP]=STACK[SP-1]&STACK[SP-2];
           break;
       case NOT:
            SP++;
            STACK[SP]=~STACK[SP-1];
           break;
       case OR:
            SP++;
            STACK[SP]=STACK[SP-1]|STACK[SP-2];
           break;
       case XOR:
            SP++;
            STACK[SP]=STACK[SP-1]^STACK[SP-2];
           break;
       case LOAD:{
            int loadVALUE= DATA[instructionSet[IP]];
            IP++;
            SP++;
            STACK[SP]=loadVALUE;
           break;}
       case STOR:{
            int storVALUE=STACK[SP];
            SP--;
            DATA[instructionSet[IP]]=storVALUE;
            IP++;
           break;}
       case PUSH:{
            int value=instructionSet[IP];
            IP++;
            SP++;
            STACK[SP]=value;
           break;}
       case POP:
            SP--; // simple as this -_-
           break;
       case CALL:{
            int callVALUE=instructionSet[IP];
            IP=STACK[callVALUE]; // I'm not much sure about this section.
           break;}
       case BR:
            IP=instructionSet[IP++];
           break;
       case RET:
            STACK[SP]=instructionSet[IP];  // I'm not much sure about this section either.
            SP++;
           break;
       case JMP:{
            IP--;  // for executing instruction at instructionSet[IP], we need to decrement IP value(because every loop turn IP value increments by 1)
           break;}
       case PRINT:{
            int value=STACK[SP];
            printf("Current Stack Value= %d -- Previous Stack Value= %d -- Other Previous= %d\n",value, STACK[SP-1], STACK[SP-2]);
            duplicateArrays(DATA,STACK);
           // SP--;
           break;}
       case HALT:
            printf("CPU HALTED\n");
           return;
            }
   }

}


