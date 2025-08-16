/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   executor.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: Gabinap <gab@mail>						 #+#  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025-05-20 21:35:21 by Gabinap		   #+#	#+#			 */
/*   Updated: 2025-05-20 21:35:21 by Gabinap		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "executor.h"
#include "instructions.h"

int	get_instnbr (INSTR *instructions)
{
	int	index;

	index = 0;
	while (instructions[index] != 0)
		index++;
	return (index);
}

int	execute (INSTR *instructions)
{
	int	instnbr;
	int	index;
	int	success;
	t_stack stack;

	instnbr = get_instnbr (instructions);
	index = 0;
	success = 1;
	initialize_stack (&stack);
	while (instructions[index] && index < instnbr)
	{
		if (instructions[index].num == NOP)
			continue ;
		else if (instructions[index].num == PUSH)
			success = push (&stack, instructions[index].arg);
		else if (instructions[index].num == POP)
			success = pop (&stack);
		else if (instructions[index].num == CLR)
			clear (&stack);
		else if (instructions[index].num == ADD)
			success = add (&stack);
		else if (instructions[index].num == SUB)
			success = sub (&stack);
		else if (instructions[index].num == MUL)
			success = mul (&stack);
		else if (instructions[index].num == DIV)
			success = div (&stack);
		else if (instructions[index].num == PRT)
			success = print (&stack, instruction[index].arg);
		else if (instructions[index].num == DMP)
			success = dump (&stack);
		else
		{
			printf ("Unknown instruction of type '%d' at number '%d'\n",
				instructions[index].num,
				index);
		}
		if (!success)
		{
			printf ("Error at instruction number '%d' of type '%d'\n",
				index,
				instructions[index].num);
			return (0);
		}
		index++;
	}
	return (1);
}
