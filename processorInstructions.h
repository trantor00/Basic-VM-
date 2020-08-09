#ifndef PROCESSORINSTRUCTIONS_H_
#define PROCESSORINSTRUCTIONS_H_


//Byte Codes
//Register arithmetics
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
//Register logic
#define AND 4
#define NOT 5
#define OR 6
#define XOR 7
//Data access instruction and Register loading
#define LOAD 8
#define STOR 9
#define PUSH 10
#define POP 11

#define CALL 12
#define BR 13
#define RET 14
#define JMP 15 //unconditional jump
#define PRINT 16
// STOP
#define HALT 17



#endif // PROCESSORINSTRUCTIONS_H_
