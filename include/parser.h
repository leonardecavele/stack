#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include "instructions.h"

void add_instr(INSTR **instructions, int *count, int *capacity, INSTR *instr);

int is_valid(char *buffer);

void to_uppercase(char *str);

INSTR *parse_line(char *buffer);

void end_line(int *i, int *count, int *capacity, char *buffer, INSTR **instructions);

INSTR *parse_program(FILE *file, int *count);

#endif
