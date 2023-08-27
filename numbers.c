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

number* init_number_ptr(char digit){
    number* n = (number*) malloc(sizeof(number));
    n->head = (node*) malloc(sizeof(node*));
    (n->head)->data = digit;
    (n->head)->prev = NULL;
    n->tail = n->head;
    (n->tail)->next = NULL;
    n->size = 1;
    n->sign = true;
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

//void displayNumber(number n){
//    if(n.sign == 0)
//        printf("-");
//    displayList(n.head);
//    printf("\n");
//}

//void displayNumber(number n){
//    if(n.sign == 0)
//        printf("-");
//    node* temp = n.head;
//    int diff = n.decimal_pos - n.size;
//    if(n.decimal_pos >= n.size){
//        printf("0");
//        printf(".");
//        for(int i = 0; i < diff; i++){
//            printf("0");
//        }
//        while(temp != NULL){
//            printf("%d",temp->data);
//            temp = temp->next;
//        }
//        printf("\n");
//        return;
//    }
//    else if(n.decimal_pos < n.size){
//        diff *= -1; 
//        for(int i = 0; i < diff; i++){
//            printf("%d",temp->data);
//            temp = temp->next;
//        }         
//        printf(".");
//        while(temp != NULL){
//            printf("%d",temp->data);
//            temp = temp->next;
//        }
//    }
//    printf("\n");
//}

void displayNumber(number* n){
    printf("decimal pos of n: %d\n", n->decimal_pos);
    if(n->decimal_pos > 10){
        printf("jasta 0 zalet\n");
        return;
    }
    if(n->sign == 0)
        printf("-");
    node* temp = n->head;
    int diff = n->decimal_pos - n->size;
    printf("diff is: %d\n", diff);
    //if(n->decimal_pos >= n->size){
    if(diff > 0){
        printf("0");
        printf(".");
        for(int i = 0; i < diff; i++){
            printf("0");
        }
        while(temp != NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
        printf("\n");
        return;
    }
    //else if(n->decimal_pos < n->size){
    else if(diff <= 0){
        printf("regular madhe alo\n");
        diff *= -1; 
        for(int i = 0; i < diff; i++){
            //while(temp != NULL){
                printf("%d",temp->data);
                temp = temp->next;
            
        }         
        printf(".");
        while(temp != NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
    }
    
    printf("\n");
}


//void displayNumber(number n){
//    if(n.sign == 0)
//        printf("-");
//    displayList(n.head);
//    printf("\n");
//    printf("decimal place: %d\n",n.decimal_pos);
//
//}

void displayNumberReverse(number n){
    displayListReverse(n.tail);
    if(n.sign == 0)
        printf("-");
    printf("\n");
}
