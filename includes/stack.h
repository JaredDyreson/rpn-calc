#pragma once
#include <stdio.h>
#define STACK_SIZE 100

struct stack {
  int stack_pointer_;
  double* contents;
};

struct stack* stack_constructor();
void stack_destructor();

void push(struct stack*, double);

double peek(struct stack*);

double peek_n(struct stack*, int position);

double pop(struct stack*);

void clear_stack(struct stack*);
