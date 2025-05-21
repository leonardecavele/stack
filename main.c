#include "instructions.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: stack_machine [FILE]");
		return EXIT_FAILURE;
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		perror("fopen");
		return 1;
	}

	int count;
	INSTR *instructions = parse_program(file, &count);

	for(int i = 0; i < count; i++)
	{
		printf("instr %d\n", i);
		printf("\topcode %d\n", instructions[i].num);
		printf("\thas arg %d\n", instructions[i].has_arg);
		if(instructions[i].has_arg)
			printf("\targ %u\n", instructions[i].arg);
		else
			printf("\tno arg\n");
	}

	fclose(file);
	return 0;
}
