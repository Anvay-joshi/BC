#include <stdio.h>
#include "numbers.h"
#include "doubly_LL.h"
#include "operations.h"

int main(){
    number n1 = init_number(1);
    insertDigitAtEnd(&n1, 6);
    insertDigitAtEnd(&n1, 3);
    displayNumber(n1);

    number n2 = init_number(4);
    insertDigitAtEnd(&n2, 5);
    insertDigitAtEnd(&n2, 7);
    displayNumber(n2);
    
    n1.sign = false;
    n2.sign = false;

    number n3 = mul(n2,n1);
    displayNumber(n3);
    printf("\n\n");

//    number n4 = mul_by_constant(n1,2);
//    displayNumber(n4);
//    printf("\n\n");
    number n4 = div_mag(n2,n1);
    displayNumber(n4);
    printf("\n\n");


    return 0;
}
