#ifndef DOUBLY_LL_H_
#define DOUBLY_LL_H_
typedef struct node{
    char data;
    struct node* next;
    struct node* prev;
}node;

void insertAtEnd(node**, char n);
void insertAtHead(node**, char n);
void displayList(node*);
void displayListReverse(node*);

#endif
