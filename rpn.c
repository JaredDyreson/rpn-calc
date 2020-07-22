#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "includes/parser.h" // get the operand codes
#include "includes/hash_table.h" // store the variable values (python dictionary equivalent)
#include "includes/stack.h" // pushing, popping, peeking on the stack
#include "includes/rpn_calculator.h" // all the math functionality of this program. Please refer to this header and parser.h to implement more math functions

// all code here and in local imports written by Jared Dyreson, California State University Fullerton (889546529)
//

static int stack_pointer_ = 0;
static double stack[STACK_SIZE];

int main(int argc, const char* argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: %s 'expression'", argv[0]);
        return 1;
    }

    char * line = strdup(argv[1]);
    if(strlen(line) == 0){
        fprintf(stderr, "error: please an expression\n");
        return 1;
    }

    int operand_code_value_;
    char* pointer;
    double value_;
    struct hash_table* map = new_hash_table();
    bool break_condition = false;
    double* cloned_stack = NULL;

    char* token = strtok(line, " ");
    while(token){
        operand_code_value_ = operand_code(token);
        switch(operand_code_value_){
            case NUMBER:
                push(strtod(token, &pointer));
                break;
            case GARBAGE:
                fprintf(stderr, "got garbage value from operand of value: %s\n", token);
                clear_stack();
                break;
            case ASSIGN:
                // we want to remove the first element in the buffer, then move pointer along
                memmove(token, token+1, strlen(token));
                if(is_var_name_valid_(token)){
                    value_ = pop();
                    insert(map, token, value_);
                    fprintf(stdout, "inserted key: %s with value of: %g\n", token, value_);
                    break;
                }
                break;
            case RETRIEVE:
                memmove(token, token+1, strlen(token));
                push(get_key(map, token));
                fprintf(stdout, "retrieved key: %s with value of: %g\n", token, peek());
                break;
            case CLONE:
                cloned_stack = duplicate_stack();
                fprintf(stdout, "cloned the stack!\n");
                break;
            case EXIT:
                break_condition = true;
                break;
            default: 
                rpn_calc(operand_code_value_);
                break;
        }
        token = strtok(NULL, " ");
    }


    fprintf(stdout, "%.8g\n", pop()); 

    // we need to free the memory we allocated throughout the lifetime of the program
    if(line != NULL){ free(line); }
    else if(cloned_stack != NULL){ free(cloned_stack); }
    destructor_(map);
    return 0;
}
