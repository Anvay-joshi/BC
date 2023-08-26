#ifndef STACK_H_NUMBERS_
#define STACK_H_NUMBERS_
#include "singly_LL_numbers.h"
#include <stdbool.h>

typedef struct stack_number{
    SLL_number_node* top;
    SLL_number_node* bottom;
    int height;
}stack_number;

void push_number(stack_number*, DTYPE1);
void pop_number(stack_number*);
DTYPE1 stack_number_top(stack_number);
stack_number init_stack_number(DTYPE1);
bool isempty_stack_number(stack_number);
void print_stack_number(stack_number S);

#endif
