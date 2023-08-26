#include <stdbool.h>
#include "doubly_LL.h"
#ifndef NUMBERS_H_
#define NUMBERS_H_

#define ACCURACY 2

typedef struct number{
    int size;
    bool sign;
    /* 
       sign = 0 for negative, 
       sign = 1 for positive 
    */
    node* head;
    node* tail;
    int decimal_pos;
}number;

number init_number(char digit);
number* init_number_ptr(char digit);
void insertDigitAtEnd(number*, char digit);
void insertDigitAtHead(number*, char digit);
void displayNumber(number );
void displayNumberReverse(number);

#endif
