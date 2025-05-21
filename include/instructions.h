#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef enum
{
	NOP = 0,
	PSH = 1,
	POP = 2,
	CLR = 3,
	ADD = 4,
	SUB = 5,
	MUL = 6,
	DIV = 7,
	PRT = 8,
	DMP = 9,
} COMMAND;

typedef struct
{
	COMMAND num;
	int arg;
	int has_arg;
} INSTR;

#endif
