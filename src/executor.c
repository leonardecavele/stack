/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabinap <gab@mail>                         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-20 21:35:21 by Gabinap           #+#    #+#             */
/*   Updated: 2025-05-20 21:35:21 by Gabinap          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "stack.h"
#include "executor.h"
#include "instructions.h"
//faut que 5 fonctions par fichier .c
// C'est l'idee, apres a voir en fonction des instructions de abd
int execute_push(t_stack *stack, int value)
{
    return push(stack, (long long int)value);
}

int execute_pop(t_stack *stack)
{
    long long int tmp;

    return pop(stack, &tmp);
}

void execute_clear(t_stack *stack)
{
    return clear();
}

int execute_add(t_stack *stack)
{

}

int execute_sub(t_stack *stack)
{

}

int execute_mul(t_stack *stack)
{

}

int execute_div(t_stack *stack)
{

}

void execute_print(t_stack *stack, int has_arg, int arg)
{

}

void execute_dump(t_stack *stack)
{

}

void execute_program(INSTR *instructions, int count)
{
    t_stack stack;
    int i;
    int success;

    initialize_stack(&stack);

    i = 0;
    while (i < count)
    {
        success = 1;

        if (instructions[i].num == PUSH)
            success = execute_push(&stack, instructions[i].arg);
        else if (instructions[i].num == POP)
            success = execute_pop(&stack);
        else if (instructions[i].num == CLR)
            execute_clear(&stack);
        else if (instructions[i].num == ADD)
            success = execute_add(&stack);
        else if (instructions[i].num == SUB)
            success = execute_sub(&stack);
        else if (instructions[i].num == MUL)
            success = execute_mul(&stack);
        else if (instructions[i].num == DIV)
            success = execute_div(&stack);
        else if (instructions[i].num == PRT)
            execute_print(&stack, instructions[i].has_arg, instructions[i].arg);
        else if (instructions[i].num == DMP)
            execute_dump(&stack);

        if (!success)
            printf("Operation failed\n", i);

        i = i + 1;
    }
}
