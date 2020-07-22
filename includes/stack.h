#pragma once
#include <stdio.h>

#define STACK_SIZE 100

int stack_pointer_ = 0;
static double stack[STACK_SIZE];

void push(double value);

double peek();

double peek_n(int position);

double pop();

void clear_stack();

double* duplicate_stack();
