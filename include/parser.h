#ifndef PARSER_H
#define PARSER_H

void add_instr(INSTR **instructions, int *count, int *capacity, INSTR instr);

INSTR *parse_line(char *buffer);

INSTR *parse_program(FILE *file, int *count);

#endif
