#include <stdbool.h>
#include <stdio.h> 
#include "numbers.h"
#include "doubly_LL.h"
#include <stdlib.h>

number init_number(char digit){
    number n;
    n.head = (node*) malloc(sizeof(node*));
    (n.head)->data = digit;
    (n.head)->prev = NULL;
    n.tail = n.head;
    (n.tail)->next = NULL;
    n.size = 1;
    n.sign = true;
    return n;
}

void insertDigitAtEnd(number* n, char digit){
    insertAtEnd(&(n->tail), digit);
    (n->size)++ ;
}

void insertDigitAtHead(number* n, char digit){
    insertAtHead(&(n->head), digit);
    (n->size)++ ;
}

void displayNumber(number n){
    if(n.sign == 0)
        printf("-");
    displayList(n.head);
    printf("\n");
}

void displayNumberReverse(number n){
    displayListReverse(n.tail);
    if(n.sign == 0)
        printf("-");
    printf("\n");
}
