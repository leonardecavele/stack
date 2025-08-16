#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "instructions.h"

void add_instr(INSTR **instructions, int *count, int *capacity, INSTR *instr);

void to_uppercase(char *str);

void end_line(int *i, int *count, int *capacity, char *buffer, INSTR **instructions);

int is_valid(char *buffer);

INSTR *parse_line(char *buffer);

INSTR *parse_program(FILE *file, int *count);

#endif
