#include "stack-lists/stack.h"
/* #include "cpu.h" */
#include "processorInstructions.h"
#include "Interpreter.h"

/*For a simple cpu
  test use test1();*/
void test1();

int main() {
   debug = 1;  // initialize 0 not to get cpu compilation details
   if(sourceInput()){  // input from a source file
   cpu(INSTRUCTIONS,0,1000,instructionSize,debug);
   if(debug){
   showStack(instructionSize);
   showLinkedStacks(INSTRUCTIONS,instructionSize);
   }
   compiledOutput();  // output of compiled instructions
   }
   else
    printf("NOT WORKING!");
    getch();
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




