#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"
#include "processorInstructions.h"


// prototypes
void showLinkedStacks();
void test1();
bool sourceInput();
bool compiledOutput();
int instructionSize;

int main(int argc, char *argv[]) {
  //test1();
   if(sourceInput()){
   cpu(INSTRUCTIONS,0,1000,instructionSize);
  // showStack(instructionSize);
  // showLinkedStacks(INSTRUCTIONS,instructionSize);
   compiledOutput();
   }
   else
    printf("NOT WORKING!");
  getch();
    return 0;
}

void showLinkedStacks(int newInstructionSet[],int size){
printf("\n-------------------Instruction stack-------------------\n");
   makeDataLIST(newInstructionSet,size);
   instructionStack *current=instructionStackHead;
  while(current!=NULL){
    printf("%s\n",current->instructionTYPE);
    current=current->nextStack;
  }
  free(current);
}
bool sourceInput(){
   char lines[20][7];
     FILE *FILE;
    char * FILENAME="sourceFILE";

    FILE= fopen(FILENAME,"r");
     if(FILE==NULL){
            printf("Error opening file!!!! ");
            return false;
        }
    int i=0;
    char *asd=malloc(sizeof(lines)/sizeof(lines[0]));
    while(!feof(FILE)){
    fgets(asd,7,FILE);
    int x;
    for(x=0;x<7;x++){  // to get rid of \n
        if(asd[x]=='\n'){
            asd[x]='\0';
            break;}
    }
    strcpy(lines[i],asd);
    if(!strcmp(lines[i],"HALT")){
       i++; lines[i][0]='\0';
        break;}
    i++;
}
   instructionSize=i;
   free(asd);
   fclose(FILE);

   int j;
   for(j=0;j<instructionSize-1;j++){
   if(lines[j][0]>=48 && lines[j][0]<=57){
     INSTRUCTIONS[j]=lines[j][0]-48;
     if(lines[j][1]>=48 && lines[j][1]<=57) // OK that's a bit idiotic for now..
        INSTRUCTIONS[j] =INSTRUCTIONS[j]*10 + (lines[j][1]-48);
   }
   else
     INSTRUCTIONS[j]=instructionToInt(lines[j]);
   }
   INSTRUCTIONS[j]=HALT;  // every instruction set finishes off with HALT.
    return true;
}

bool compiledOutput(){
     FILE *FILE;
    const char * FILENAME="CompiledFILE";
    FILE= fopen(FILENAME,"w");
    int i=0;
     fprintf(FILE, "Memory Location - Compiled Data\n");
   while(STACK[i]!=0){
      int data=STACK[i];
    fprintf(FILE, "%d. %d -> %d\n",i,&data+i,data);
       i++;
   }
    fclose(FILE);
    printf("\nCompiled file created as %s",FILENAME);
    return true;
}

void test1(){
int newInstructionSet[]={  //example instruction set for cpu
        PUSH,1,
        PUSH,2,
        ADD,
        ADD,
        SUB,
        PUSH,77,
        PUSH,3,
        MUL,
        SUB,
        PRINT,
        XOR,
        PRINT

 };
  int size=sizeof(newInstructionSet)/sizeof(newInstructionSet[0]);

  cpu(newInstructionSet,0,1000,size);
   showStack(size);
   showLinkedStacks(newInstructionSet,size);
   compiledOutput();
}




