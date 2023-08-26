#include <stdio.h>
#include <stdlib.h>
#include "singly_LL.h"

SLL_node* createNode_SLL(DTYPE num){
    SLL_node* temp = (SLL_node*) malloc(sizeof(SLL_node));
    temp->data = num;
    temp->next = NULL;
    return temp;
}

void insertAtTail_SLL(SLL_node** head, DTYPE num){
    SLL_node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    SLL_node* newNode = createNode_SLL(num);
    temp->next = newNode;
    //free(temp);
    return;
}

//void display_SLL(SLL_node* head){
//    SLL_node* temp = head;
//    while(temp!=NULL){
//        printf("%d ",temp->data);
//        temp = temp->next;
//    }
//    free(temp);
//}

void insertAtHead_SLL(SLL_node** head, DTYPE num){
    SLL_node* temp = createNode_SLL(num);
    temp->next = (*head);
    (*head) = temp;

}

void insertAtPosition_SLL(SLL_node** head, DTYPE num, int pos){
    if(pos == 0){
        insertAtHead_SLL(head, num);
        return;
    }
    
    SLL_node* temp = (*head);
    int i = 1;
    while(i < pos && temp-> next != NULL){
        temp = temp->next;        
        i++;
    }
    SLL_node* newNode = createNode_SLL(num);
    newNode->next = temp->next;
    temp->next = newNode;
    return; 
}

void deleteAtPosition_SLL(SLL_node** head, int pos){
    if(pos == 0){
        deleteHead_SLL(head);
        return;
    }

    int i = 1;
    SLL_node* temp = (*head);
    while(i < pos && (temp->next)->next != NULL){
        temp = temp->next;
    }
    
    SLL_node* temp3 = temp->next;
    temp->next = temp3->next;
    free(temp3);
}

void deleteHead_SLL(SLL_node** head){
    if(*head == NULL){
        return;
    }
    SLL_node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteTail_SLL(SLL_node** head){
    SLL_node* temp = *head;
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
    SLL_node* temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}
