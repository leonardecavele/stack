/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabinap <gab@mail>                         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-20 22:19:02 by Gabinap           #+#    #+#             */
/*   Updated: 2025-05-20 22:19:02 by Gabinap          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STACK_H
# define STACK_H

typedef struct
{
	long long int values[8];
	int top;
} t_stack;

void    initialize_stack(t_stack *stack);

int     is_empty(const t_stack *stack);

int     is_full(const t_stack *stack);

#endif
