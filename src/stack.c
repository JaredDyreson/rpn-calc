#include <stdio.h>
#include <stdlib.h>
#include "../includes/stack.h"

struct stack* stack_constructor(){
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->stack_pointer_ = 0;
    double* contents = (double*)malloc(sizeof(double) * STACK_SIZE);
    st->contents = contents;
    return st;
}

void stack_destructor(struct stack* st){
    free(st->contents);
    free(st);
}

void push(struct stack* st, double value){
    if(st->stack_pointer_ >= STACK_SIZE){
        fprintf(stderr, "stack full!\n");
        return;
    }
    st->contents[st->stack_pointer_++] = value;
}

double peek(struct stack* st){
    if(st->stack_pointer_ == 0){
        fprintf(stderr, "cannot peek value, stack is empty!\n");
        return 0.0;
    }
    return st->contents[st->stack_pointer_-1];
}

double peek_n(struct stack* st, int position){
    if(st->stack_pointer_ - position > 0){

        fprintf(stderr, "cannot peek that far!\n");
    }
    return st->contents[st->stack_pointer_-position];
}

double pop(struct stack* st){
    if(st->stack_pointer_ == 0){
        fprintf(stderr, "cannot pop value, stack is empty!\n");
        return 0.0;
    }
    return st->contents[--st->stack_pointer_];
}

void clear_stack(struct stack* st){
  while(--st->stack_pointer_ > 0){
    pop(st);
  }
}

