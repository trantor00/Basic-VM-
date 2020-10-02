#include "stack.h"


void makeDataLIST(int32_t instructionSet[], int32_t supposedSIZE ){  // pushing
// Instruction Stack-List
   int i;
   for(i=0;i<supposedSIZE;i++){
    int32_t newIP=instructionSet[i];
    instructionStack *currentStack=(instructionStack *)malloc(sizeof(instructionStack*));
        currentStack->ip=newIP;
        strcpy(currentStack->instructionTYPE,instructionToString(newIP));
        currentStack->nextStack=instructionStackHead;
        instructionStackHead=currentStack;
  }
// Data(RAM) Stack-List
for(i=0;i<supposedSIZE;i++){
    int32_t newSP=RAM[i];
    dataStack *currentStack=(dataStack *)malloc(sizeof(dataStack*));
       currentStack->sp=newSP;
       currentStack->nextStack=dataStackHead;
       dataStackHead=currentStack;
}
}
void showLinkedStacks(int32_t newInstructionSet[],int32_t size){
printf("\n-------------------Instruction stack-------------------\n");
   makeDataLIST(newInstructionSet,size);
   instructionStack *current=instructionStackHead;
  while(current!=NULL){
    printf("%s\n",current->instructionTYPE);
    current=current->nextStack;
  }
  free(current);
}
char *instructionToString(int32_t instructionType){
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
int32_t instructionToInt(char * instructionType){
    int32_t instruction;
  /*  int j;
    for(j=0;j<6;j++){
       if(instructionType[j]=='\n')
        instructionType[j]='\0';
    }*/
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



void showStack(int32_t supposedSIZE){
    int i;
    printf("\n");
    for(i=0;i<supposedSIZE;i++){
        printf("Stack element %d. ->> %d\n",i,RAM[i]);
    }
    printf("All stack elements are demonstrated..\n");
}

void duplicateArrays(int32_t arr1[], int32_t arr2[]){
 int32_t arraySize=sizeof(arr2)/sizeof(arr2[0]);
 int i;
 for(i=0;i<arraySize;i++){
    arr1[i]=arr2[i];
 }
}


