#ifndef PROCESSORINSTRUCTIONS_H_
#define PROCESSORINSTRUCTIONS_H_

//Byte Codes
//Register arithmetics
#define ADD 0x0
#define SUB 0x1
#define MUL 0x2
#define DIV 0x3
//Register logic
#define AND 0x4
#define NOT 0x5
#define OR 0x6
#define XOR 0x7
//Data access instruction and Register loading
#define LOAD 0x8
#define STOR 0x9
#define PUSH 0xA
#define POP 0xB
#define CALL 0xC
#define BR 0xD
#define RET 0xE
#define JMP 0xF //unconditional jump
#define PRINT 0x10
// STOP
#define HALT 0x11



#endif // PROCESSORINSTRUCTIONS_H_
