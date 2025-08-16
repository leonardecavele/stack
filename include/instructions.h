#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "stack.h"

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

int	inst_push (t_stack *stack, int value);

int	inst_pop (t_stack *stack);

int	inst_clear (t_stack *stack);

int	inst_add (t_stack *stack);

int	inst_sub (t_stack *stack);

int	inst_mul (t_stack *stack);

int	inst_div (t_stack *stack);

int	inst_print (t_stack *stack, int arg);

int	inst_dump (t_stack *stack);

#endif
