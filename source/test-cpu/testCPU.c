#include "../stack-lists/stack.h"
/* #include "../cpu/cpu.h" */
#include "../cpu/processorInstructions.h"
//#include "Interpreter.h"

/*For a simple cpu
  test use test1();*/
void test1();

int main(int argc, char *argv[]) {
    if(argc==3){
   debug = 1;  // initialize 0 not to get cpu compilation details
   if(sourceInput(argv[1])){  // input from a source file
   cpu(INSTRUCTIONS,0,100,instructionSize,debug);
   if(debug){
   showStack(instructionSize);
   //showLinkedStacks(INSTRUCTIONS,instructionSize);
   }
   compiledOutput(argv[2]);  // output of compiled instructions
   }
   else{
    printf("\nNOT WORKING!\n");
   // getch();
   }
}
   else{
    printf("Please enter proper args\n");
    }
    return 0;
}

void test1(){
int32_t newInstructionSet[]={  //example instruction set for cpu
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
  int32_t size=sizeof(newInstructionSet)/sizeof(newInstructionSet[0]);

   cpu(newInstructionSet,0,1000,size,0);
   showStack(size);
   showLinkedStacks(newInstructionSet,size);
   compiledOutput();
}




