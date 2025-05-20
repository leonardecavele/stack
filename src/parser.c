#include <stdio.h>
#include "parser.h"
#include "instructions.h"

void add_instr(INSTR **instructions, int *count, int *capacity, INSTR instr)
{
	if(*count >= *capacity)
	{
		if (*capacity == 0)
			*capacity = 8;
		else
			*capacity = *capacity * 2;
	}
	*instructions = realloc(*instructions, sizeof(INSTR) * (*capacity));
	if (!*instructions)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	(*instructions)[(*count)++] = instr;
}

INSTR parse_line(char *buffer)
{
	d
}


INSTR *parse_program(FILE *file, int *count)
{
	*count = 0;
	int capacity = 0;
	INSTR *instructions = NULL;

	char buffer[16];
	int i = 0;
	int c;

	while((c = fgetc(file)) != EOF)
	{
		if(c == '\n')
		{
			buffer[i] = '\0';
			i = 0;
			add_instr(&instructions, count, &capacity, parse_line(buffer));
		}
		buffer[i++] = c;
	}
	return instructions;
}
