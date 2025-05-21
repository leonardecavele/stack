#include "instructions.h"
#include "parser.h"
#include <stdio.h>

int main(void)
{
	FILE *file = fopen("input/test3.txt", "r");
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
