#pragma once
#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_RESERVED_WORDS 15

typedef enum{
  ADD,
  SUB,
  DIV,
  MUL,
  MOD,
  SIN,
  COS,
  TAN,
  ASIN,
  ACOS,
  ATAN,
  FLOOR,
  POW,
  EXP,
  SQRT,
  VAR,
  NUMBER,
  GARBAGE,
  ASSIGN,
  RETRIEVE,
  SWAP,
  CLONE,
  LINEFEED,
  POP,
  PEEK,
  NOP, // no operation code
  PI,
  EXIT 
} operands;

int operand_code(char* element);

bool is_var_name_valid_(char* variable_name);
