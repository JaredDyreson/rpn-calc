#include <stdio.h>
#include <math.h>
#include "../includes/rpn_calculator.h"
#include "../includes/parser.h"
#include  "../includes/stack.h"


void rpn_calc(struct stack* st, int operand_code){
  double operand_one, operand_two;
  switch(operand_code){
    case LINEFEED: 
      if(st->stack_pointer_ != 0){ fprintf(stdout, "%.8g\n", peek(st)); }
      break;
    case POP:
      // force a pop operation
      fprintf(stdout, "%.8g\n", pop(st)); 
      break;
    case PEEK:
      fprintf(stdout, "%.8g\n", peek(st)); 
      break;
    case ADD:
      push(st, pop(st) + pop(st));
      break;
    case SUB:
      push(st, -(pop(st) - pop(st)));
      break;
    case MUL:
      push(st, pop(st) * pop(st));
      break;
    case DIV:
      operand_two = pop(st);
      if(operand_two == 0.0){
        fprintf(stderr, "divide by zero exception thrown, cowardly refusing!\n");
        break;
      }
      push(st, pop(st) / operand_two);
      break;
    case MOD:
      operand_two = pop(st);
      push(st, fmod(pop(st), operand_two));
      break;
    case SIN:
      push(st, sin(pop(st)));
      break;
    case COS:
      push(st, cos(pop(st)));
      break;
    case TAN:
      push(st, tan(pop(st)));
      break;
    case ASIN:
      push(st, asin(pop(st)));
      break;
    case ACOS:
      push(st, acos(pop(st)));
      break;
    case ATAN:
      push(st, atan(pop(st)));
      break;
    case FLOOR:
      push(st, floor(pop(st)));
      break;
    case EXP:
      push(st, exp(pop(st)));
      break;
    case POW:
      operand_two = pop(st);
      push(st, pow(pop(st), operand_two));
      break;
    case SQRT:
      push(st, pow(pop(st), 0.5));
      break;
    case SWAP:
      fprintf(stdout, "peeking 1st: %g and 2nd: %g\n", peek_n(st, 1), peek_n(st, 2));
      operand_one = pop(st);
      operand_two = pop(st);
      push(st, operand_one);
      push(st, operand_two);
      break;
    case NOP: break;
    case PI:
      push(st, M_PI);
      break;
    default:
      fprintf(stderr, "got an error with op_code %d\n", operand_code);
      break;
  }
}
