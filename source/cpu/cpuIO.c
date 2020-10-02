#include "../stack-lists/stack.h"

bool sourceInput(const char * FILENAME){
   char lines[20][7];
     FILE *FILE;
    FILE= fopen(FILENAME,"r");
     if(FILE==NULL){
            printf("Error opening file!!!! ");
            return false;
        }
    int i=0;
    int givenData=0;
    char *asd=malloc(sizeof(lines)/sizeof(lines[0]));
    while(!feof(FILE)){
      givenData++;
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
  instructionSize=givenData;
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

bool compiledOutput(const char * FILENAME){
    FILE *FILE;
    FILE= fopen(FILENAME,"w");
    int i;
   if(debug){
    i=0;
    fprintf(FILE, "Memory Location - Data\n");
   while(RAM[i]!=0){
      int data=RAM[i];
    fprintf(FILE, "%d. %d -> %d\n",i,&data+i,data);
       i++;
   }
}
    i=0;
  if(debug)  fprintf(FILE, "COMPILED DATA\n");
   while(DATA[i]!=HALT){
    fprintf(FILE, "%d\n",DATA[i]);
       i++;
   }
    fclose(FILE);
    printf("\nCompiled file created as %s",FILENAME);
    return true;
}
