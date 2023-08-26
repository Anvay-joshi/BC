#include <stdbool.h>
#include <stdio.h>
#include "singly_LL.h"
#include "stack.h"

stack init_stack(DTYPE num){
    stack S;
    S.top = createNode_SLL(num);
    S.height = 1;
    S.bottom = S.top;
    return S;
}

void push(stack* S, DTYPE item){
    if(S->height == 0){
        S->bottom = createNode_SLL(item);
        S->top = S->bottom;
        S->height = 1;
        return;
    }

    ((*S).top)->next = createNode_SLL(item);
    (*S).top = ((*S).top)->next;
    S->height ++;
}

void pop(stack* S){
    if(S->top == NULL){
        return;
    }
    if(S->height == 1){
        S->bottom = NULL;
        S->top = S->bottom;
    }
    else{
        deleteTail_SLL(&(S->bottom));
        SLL_node* temp = S->bottom;
        while(temp->next != NULL){
            temp = temp->next;
        }
        S->top = temp;
    }
    S->height --;
}

DTYPE stack_top(stack S){
    return ((S.top)->data);
}

bool isempty_stack(stack S){
    if(S.height == 0){
        return true;
    }
    else{
        return false;
    }
}

void print_stack(stack S){
    SLL_node* temp = S.bottom;
    while(temp!=NULL){
        printf("%d (%c)\t",*(temp->data),*(temp->data));
        temp = temp->next;
    }
    printf("\n");
}
