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

/* 8 valeurs de 64 bits signés avec index du sommet de la pile */
typedef struct s_stack
{
	long long int values[8];
	int top;
} t_stack;

/* Fonctions de base de manipulation de la pile */
void    initialize_stack(t_stack *stack);
int     is_empty(const t_stack *stack);
int     is_full(const t_stack *stack);

#endif
