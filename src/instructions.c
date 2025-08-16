#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "instructions.h"

int		inst_push (t_stack *stack, int value)
{
	if (stack.top >= 8 || stack.top < -1)
	{
		printf ("Out of bounds, cannot 'PUSH' value at range '%d'\n",
			stack.top);
		return (0);
	}
	stack.top++;
	stack.values[top] = value;
	return (1);
}

int		inst_pop (t_stack *stack);
{
	if (stack.top >= 8 || stack.top < 0)
	{
		printf ("Out of bounds, cannot 'POP' value at range '%d'\n",
			stack.top);
		return (0);
	}
	stack.values[top] = 0;
	stack.top--;
	return (1);
}

int		inst_clear (t_stack *stack);
{
	int	index;

	index = 0;
	if (stack.top < 0)
	{
		printf ("Cannot 'CLEAR' stack, already empty.\n");
		return (0);
	}
	while (stack.values[index])
		stack.values[index] = 0;
	stack.top = -1;
	return (1);
}

int		inst_add (t_stack *stack, int value);
{
	if (stack.top < 0)
	{
		printf ("Cannot 'ADD' stack is empty.\n");
		return (0);
	}
	if (!stack.values[stack.top])
		return (0);
	stack.values[stack.top] += value;
	return (1);
}

int		inst_sub (t_stack *stack, int value);
{
	if (stack.top < 0)
	{
		printf ("Cannot 'SUB' stack is empty.\n");
		return (0);
	}
	if (!stack.values[stack.top])
		return (0);
	stack.values[stack.top] -= value;
	return (1);
}

int		inst_mul (t_stack *stack, int value);
{
	if (stack.top < 0)
	{
		printf ("Cannot 'MUL' stack is empty.\n");
		return (0);
	}
	stack.values[stack.top] /= value;
	return (1);
}

int		inst_div (t_stack *stack, int value);
{
	if (stack.top < 0)
	{
		printf ("Cannot 'DIV' stack is empty.\n");
		return (0);
	}
	if (stack.values[stack.top] == 0)
	{
		printf ("Cannot divide value '%d' at position '%d' by zero.\n", stack.values[stack.top], stack.top);
		return (0);
	}
	stack.values[stack.top] /= value;
	return (1);
}

void	inst_print (t_stack *stack);
{
	if (stack.top < 0)
	{
		printf ("Cannot 'PRT' stack is empty.\n");
		return (0);
	}
	printf ("%d", stack.values[stack.top]);
	return (1);
}

void	inst_dump (t_stack *stack);
{
	int	index;

	if (stack.top < 0)
	{
		printf ("Cannot 'DMP', stack is empty.\n");
		return (0);
	}
	index = 0;
	while (index < 8)
	{
		printf ("%d");
		if (index < 7)
			printf (", ");
	}
	printf ("\n");
	return (1);
}
