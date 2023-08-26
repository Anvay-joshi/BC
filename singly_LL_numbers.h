#ifndef SINGLY_LL_H_NUMBERS_
#define SINGLY_LL_H_NUMBERS_

#include "numbers.h"
#define DTYPE1 number*

typedef struct SLL_number_node{
    DTYPE1 data;
    struct SLL_number_node* next;
}SLL_number_node;

SLL_number_node* createNode_SLL_number(DTYPE1);
void insertAtTail_SLL_number(SLL_number_node**, DTYPE1);
//void display_SLL(SLL_number_node*);
void insertAtHead_SLL_number(SLL_number_node** , DTYPE1);
void insertAtPosition_SLL_number(SLL_number_node** , DTYPE1 , int );
void deleteHead_SLL_number(SLL_number_node**);
void deleteTail_SLL_number(SLL_number_node**);

#endif
