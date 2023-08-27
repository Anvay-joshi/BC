#include <stdbool.h>
#include <stdio.h>
#include "stack_numbers.h"
#include "singly_LL_numbers.h"
#include "numbers.h"

stack_number init_stack_number(DTYPE1 num){
    stack_number S;
    S.top = createNode_SLL_number(num);
    S.height = 1;
    S.bottom = S.top;
    return S;
}

void push_number(stack_number* S, DTYPE1 item){
    if(S->height == 0){
        S->bottom = createNode_SLL_number(item);
        S->top = S->bottom;
        S->height = 1;
        return;
    }

        ((*S).top)->next = createNode_SLL_number(item);
        (*S).top = ((*S).top)->next;
        S->height ++;
}

void pop_number(stack_number* S){
    if(S->top == NULL){
        return;
    }
    if(S->height == 1){
        S->bottom = NULL;
        S->top = S->bottom;
    }
    else{
        deleteTail_SLL_number(&(S->bottom));
        SLL_number_node* temp = S->bottom;
        while(temp->next != NULL){
            temp = temp->next;
        }
        S->top = temp;
    }
    S->height --;
}

DTYPE1 stack_number_top(stack_number S){
    return ((S.top)->data);
}

bool isempty_stack_number(stack_number S){
    if(S.height == 0){
        return true;
    }
    else{
        return false;
    }
}

void print_stack_number(stack_number S){
    SLL_number_node* temp = S.bottom;
    while(temp!=NULL){
        //printf("%d (%c)\t",(temp->data)->data,(temp->data)->data);
        displayNumber((temp->data));
        temp = temp->next;
    }
    printf("\n");
}
