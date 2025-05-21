#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "parser.h"
#include "instructions.h"

#define LINE_LENGTH 31

void add_instr(INSTR **instructions, int *count, int *capacity, INSTR *instr)
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
	(*instructions)[(*count)++] = *instr;
}

int is_valid(char *buffer)
{
	int num_count = 0;
	int char_count = 0;
	int a = 0;

	for(int i = 0; buffer[i] != '\0'; i++)
	{
		if(isalpha(buffer[i]) && a < 3)
		{
			char_count++;
			buffer[a++] = buffer[i];
		}
		else if(isdigit(buffer[i]) && a >= 3)
		{
			num_count++;
			buffer[a++] = buffer[i];
		}
	}
	buffer[a] = '\0';

	if(char_count < 3)
		return 1;
	return 0;
}

void to_uppercase(char *str)
{
	for(int i = 0; str[i] != '\0'; i++)
		str[i] = toupper((unsigned char)str[i]);
}

INSTR *parse_line(char *buffer)
{
	if(is_valid(buffer))
		return NULL;

	INSTR *instr = malloc(sizeof(INSTR));
	if(!instr)
	{
		perror("malloc");
		return NULL;
	}

	char opcode[4] = {0};
	char operand[28] = {0};

	for(int i = 0; i < 3; i++)
		opcode[i] = buffer[i];
	opcode[3] = '\0';

	to_uppercase(opcode);

	int a = 0;
	for(int i = 3; buffer[i] != '\0'; i++)
	{
		if(isdigit(buffer[i]))
			operand[a++] = buffer[i];
	}
	operand[a] = '\0';

	if(strcmp(opcode, "NOP") == 0)
	{
		instr->num = NOP;
	}
	else if(strcmp(opcode, "PSH") == 0)
	{
		instr->num = PSH;
	}
	else if(strcmp(opcode, "POP") == 0)
	{
		instr->num = POP;
	}
	else if(strcmp(opcode, "CLR") == 0)
	{
		instr->num = CLR;
	}
	else if(strcmp(opcode, "ADD") == 0)
	{
		instr->num = ADD;
	}
	else if(strcmp(opcode, "SUB") == 0)
    {
        instr->num = SUB;
    }
    else if(strcmp(opcode, "MUL") == 0)
    {
        instr->num = MUL;
    }
    else if(strcmp(opcode, "DIV") == 0)
    {
        instr->num = DIV;
    }
	else if(strcmp(opcode, "PRT") == 0)
    {
        instr->num = PRT;
    }
    else if(strcmp(opcode, "DMP") == 0)
    {
        instr->num = DMP;
    }
    else
		return NULL;

	instr->has_arg = (a > 0);
	if(instr->has_arg)
		instr->arg = atoi(operand);

	return instr;
}

void end_line(int *i, int *count, int *capacity, char *buffer, INSTR **instructions)
{
	buffer[*i] = '\0';
    *i = 0;
    INSTR *instr = parse_line(buffer);
    if (!instr)
        return;
    add_instr(instructions, count, capacity, instr);
	free(instr);
}

INSTR *parse_program(FILE *file, int *count)
{	
	INSTR *instructions = NULL;
	char buffer[LINE_LENGTH + 1];

	int capacity, i, line_count, c;
	*count = i = capacity = line_count = 0;
	
	while((c = fgetc(file)) != EOF)
	{
		if(c == '\n')
		{
			line_count++;
			end_line(&i, count, &capacity, buffer, &instructions);
		}
		if(i >= LINE_LENGTH)
		{
			fprintf(stderr, "Line %d exceeds %d character limit.\n", line_count, LINE_LENGTH);
			exit(EXIT_FAILURE);
		}
		buffer[i++] = c;
	}
	end_line(&i, count, &capacity, buffer, &instructions);
	return instructions;
}
