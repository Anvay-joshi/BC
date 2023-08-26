#ifndef STACK_H_
#define STACK_H_
#include "singly_LL.h"
#include <stdbool.h>

typedef struct stack{
    SLL_node* top;
    SLL_node* bottom;
    int height;
}stack;

void push(stack*, DTYPE);
void pop(stack*);
DTYPE stack_top(stack);
stack init_stack(DTYPE);
bool isempty_stack(stack);
void print_stack(stack S);

#endif
