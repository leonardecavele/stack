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

void    execute_program(INSTR *instructions, int count);

#endif
