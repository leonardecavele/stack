/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gabinap <gab@mail>                         #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-20 22:19:25 by Gabinap           #+#    #+#             */
/*   Updated: 2025-05-20 22:19:25 by Gabinap          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "instructions.h"
# include "stack.h"

/* Fonction principale d'exécution */
void    execute_program(INSTR *instructions, int count);

/* Fonctions d'opérations */
int     execute_push(t_stack *stack, int value);
int     execute_pop(t_stack *stack);
void    execute_clear(t_stack *stack);
int     execute_add(t_stack *stack);
int     execute_sub(t_stack *stack);
int     execute_mul(t_stack *stack);
int     execute_div(t_stack *stack);
void    execute_print(t_stack *stack, int has_arg, int arg);
void    execute_dump(t_stack *stack);

#endif
