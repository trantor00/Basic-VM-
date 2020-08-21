#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"
#include "processorInstructions.h"



void showLinkedStacks();
void test1();
bool sourceInput();
bool compiledOutput();

int main(int argc, char *argv[]) {
  test1();

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
  /* char lines[10][6];
   FILE *FILE;
     const char * FILENAME="sourceFILE";

    FILE= fopen(FILENAME,"r");
     if(FILE==NULL){
            printf("Error opening file!!!! ");
            return false;
        }

    int i=0;

    char *asd=malloc(sizeof(lines)/sizeof(lines[0]));
    while(!feof(FILE)){
    fgets(asd,6,FILE);
    if(asd[0]=='\n'){
        continue;
    }
    strcpy(lines[i],asd);
    printf("%s\n",lines[i]);
    i++;
}
   free(asd);
   fclose(FILE);

   int arraySize= sizeof(lines)/sizeof(lines[i]);
   int j;
   for(j=0;j<arraySize;j++){
        if(lines[0]>=48 && lines[0]<=57)
            INSTRUCTIONS[j]=lines[0]-48;
   else if(lines[1]>=48 && lines[1]<=57)
     INSTRUCTIONS[j]=lines[1]-48;
   else
    INSTRUCTIONS[j]=instructionToInt(lines[j]);
    printf("%d\n",INSTRUCTIONS[j]);
   }
    return true;*/

}

bool compiledOutput(){
     FILE *FILE;
    const char * FILENAME="CompiledFILE";
    FILE= fopen(FILENAME,"w");
    int i=0;
   while(STACK[i]!=0){
      int data=STACK[i];
    fprintf(FILE, "%d ",data);
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
        PUSH,99,
        MUL,
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




