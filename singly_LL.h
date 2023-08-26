#ifndef SINGLY_LL_H_
#define SINGLY_LL_H_

#define DTYPE char*

typedef struct SLL_node{
    DTYPE data;
    struct SLL_node* next;
}SLL_node;

SLL_node* createNode_SLL(DTYPE);
void insertAtTail_SLL(SLL_node**, DTYPE);
//void display_SLL(SLL_node*);
void insertAtHead_SLL(SLL_node** , DTYPE);
void insertAtPosition_SLL(SLL_node** , DTYPE , int );
void deleteHead_SLL(SLL_node**);
void deleteTail_SLL(SLL_node**);

#endif
