/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabinap <gab@mail>                         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-20 21:37:14 by Gabinap           #+#    #+#             */
/*   Updated: 2025-05-20 21:37:14 by Gabinap          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "stack.h"

void initialize_stack(t_stack *stack)
{
	stack->top = -1;
}

int is_empty(const t_stack *stack)
{
	return (stack->top == -1);
}

int is_full(const t_stack *stack)
{
	return (stack->top == 7);
}