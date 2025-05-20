#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef enum
{
	ADD = 0,
	POP = 1,
	CLR = 2,
	SUB = 3,
	MUL = 4,
	DIV = 5,
	PRT = 6,
	DMP = 7,
} COMMAND;

typedef struct
{
	COMMAND num;
	int arg;
	int has_arg;
} INSTR;

#endif
