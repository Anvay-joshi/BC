#include <stdio.h>
#include <stdlib.h>
#include "doubly_LL.h"

void insertAtEnd(node** tail, char n){
    if((*tail) == NULL){
        (*tail) = (node*) malloc(sizeof(node));
        (*tail)->next = NULL;
        (*tail)->prev = NULL;
        (*tail)->data = n;
        return;
    }
    node* temp = (node*) malloc(sizeof(node));
    temp->data = n;
    (*tail)->next = temp;
    temp->prev = *tail;
    temp->next = NULL;
    (*tail) = (*tail)->next;
}

void displayList(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
//    printf("\n");
}

void displayListReverse(node* tail){
    node* temp = tail;
    while(temp!= NULL){
        printf("%d",temp->data);
        temp = temp->prev;
    }
//    printf("\n");
}

void insertAtHead(node** head, char n){
    node* temp = (node*) malloc(sizeof(node));
    temp->data = n;
    (*head)->prev = temp;
    temp->next = *head;
    temp->prev = NULL;
    (*head) = (*head)->prev;
    
}
