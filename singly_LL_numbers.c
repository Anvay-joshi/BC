#include <stdio.h>
#include <stdlib.h>
#include "singly_LL_numbers.h"
#include "numbers.h"

SLL_number_node* createNode_SLL_number(DTYPE1 num){
    SLL_number_node* temp = (SLL_number_node*) malloc(sizeof(SLL_number_node));
    temp->data = num;
    temp->next = NULL;
    return temp;
}

void insertAtTail_SLL_number(SLL_number_node** head, DTYPE1 num){
    SLL_number_node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    SLL_number_node* newNode = createNode_SLL_number(num);
    temp->next = newNode;
    //free(temp);
    return;
}

//void display_SLL(SLL_number_node* head){
//    SLL_number_node* temp = head;
//    while(temp!=NULL){
//        printf("%d ",temp->data);
//        temp = temp->next;
//    }
//    free(temp);
//}

void insertAtHead_SLL_number(SLL_number_node** head, DTYPE1 num){
    SLL_number_node* temp = createNode_SLL_number(num);
    temp->next = (*head);
    (*head) = temp;

}

void insertAtPosition_SLL_number(SLL_number_node** head, DTYPE1 num, int pos){
    if(pos == 0){
        insertAtHead_SLL_number(head, num);
        return;    
    }
    
    SLL_number_node* temp = (*head);
    int i = 1;
    while(i < pos && temp-> next != NULL){
        temp = temp->next;        
        i++;
    }
    SLL_number_node* newNode = createNode_SLL_number(num);
    newNode->next = temp->next;
    temp->next = newNode;
    return; 
}

void deleteAtPosition_SLL_number(SLL_number_node** head, int pos){
    if(pos == 0){
        deleteHead_SLL_number(head);
        return;
    }

    int i = 1;
    SLL_number_node* temp = (*head);
    while(i < pos && (temp->next)->next != NULL){
        temp = temp->next;
    }
    
    SLL_number_node* temp3 = temp->next;
    temp->next = temp3->next;
    free(temp3);
}

void deleteHead_SLL_number(SLL_number_node** head){
    if(*head == NULL){
        return;
    }
    SLL_number_node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteTail_SLL_number(SLL_number_node** head){
    SLL_number_node* temp = *head;
    if(*head == NULL){
        return;
    }
    if(temp->next == NULL){
        *head = NULL;
        return ;
    }

    while((temp->next)->next != NULL){
        temp = temp->next;
    }
    SLL_number_node* temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}
