#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"
#include "doubly_LL.h"
#include "operations.h"

number div_mag(number n1, number n2){
    if(n2.size == 1 && n2.head->data == 0){
        printf("division by zero error\n");
        return  n2;
    }     

    number quotient = init_number(0);
    char factor = 0;
    number rem = n1;
    int order_of_mag = 0;
    while(numberComparison(rem, n2) == 1){
        number intermediate = init_number(0);
        if(n2.head->data > n1.head->data){
            order_of_mag = n1.size - n2.size - 1; 
        }
        else{
            order_of_mag = n1.size - n2.size;
        }
        while(order_of_mag --){
            insertDigitAtEnd(&intermediate, 0);
        }
        while(numberComparison(mul_by_constant(quotient, factor + 1),rem) != 1){
            factor++;
        }
        mul_by_constant(intermediate, factor);
        add_mag(quotient, intermediate);
        rem = sub_mag(rem,mul_mag(n2,intermediate));
    }
    return quotient;

}

number mul_by_constant(number n1, char a){
    number n2 = init_number(0);
    n2.size = 0;
    node* temp = n1.tail;
    int carry = 0;
    int prod = 0;
    while(temp != NULL){
        prod = a * temp->data + carry;
        carry = prod / 10;
        prod = prod % 10;

        if(n2.size == 0){
            n2.head->data = prod;
            n2.size = 1;
        }
        else
            insertDigitAtHead(&n2, prod); 
        temp = temp->prev;
    }  
    if(carry != 0){
        insertDigitAtHead(&n2, prod);
    }
    return n2;
}

number mul(number n1, number n2){
    if(n1.sign == n2.sign)
        return mul_mag(n1,n2);
     
    else{
        number n3 = mul_mag(n1,n2);
        n3.sign = false;
        return n3;
    }

}

number mul_mag(number n1, number n2){
    number n3 = init_number(0);
    number n4 = init_number(0);
    node* temp2 = n2.tail;
    int temp2_pos = 0;
    while((temp2!= NULL)){

        char num = temp2->data;   
        node* temp1 = n1.tail;
        node* temp4 = n4.tail;
        int prod, carry = 0;
        for(int i = 1; i <= temp2_pos; i++){
         
           if (temp4 == NULL){
               insertDigitAtHead(&n4, 0);
               temp4 = n4.head;
           }
           else
               temp4->data = 0;
               
           temp4 = temp4->prev;
        }
        while(temp1 != NULL){
            prod = num * temp1->data + carry; 
            carry = prod / 10; 
            prod = prod % 10;

            if (temp4 == NULL){
                insertDigitAtHead(&n4, prod);
                temp4 = n4.head;
            }
            else{
                temp4->data = prod;
            }
            temp1 = temp1->prev;
            temp4 = temp4->prev;
        }
        if(carry != 0){
            insertDigitAtHead(&n4, carry);
        }
        n3 = add_mag(n3, n4);
        temp2_pos ++;
        temp2 = temp2->prev;
        
    }
    return n3;
}


number add_mag(number n1, number n2){
    char sum = 0;
    char carry = 0;

    sum = (n1.tail)->data + (n2.tail)->data;
    carry = sum/10;
    sum = sum % 10;

    number n3 = init_number(sum);
    node* temp1 = (n1.tail)->prev;
    node* temp2 = (n2.tail)->prev;
    
    while(temp1 != NULL || temp2 != NULL){
        if(temp1 == NULL && temp2 != NULL){
            sum = (temp2->data + carry);
            carry = sum / 10;
            sum = sum % 10;
            insertDigitAtHead(&n3, sum);
            temp2 = temp2->prev;
        }

        else if(temp1 != NULL && temp2 == NULL){
            sum = (temp1->data + carry);
            carry = sum / 10;
            sum = sum % 10;
            insertDigitAtHead(&n3, sum);
            temp1 = temp1->prev;
        }

        else if(temp1 == NULL && temp2 == NULL && carry != 0){
            insertDigitAtHead(&n3, carry);
        }

        else{
            sum = (temp1->data + temp2->data + carry);
            carry = sum / 10;
            sum = sum % 10;
            insertDigitAtHead(&n3, sum);
            temp1 = temp1->prev;
            temp2 = temp2->prev;

        }
    }
    return n3;
}

number add(number n1, number n2){
    if(n1.sign == true && n2.sign == true){
        return add_mag(n1,n2);
    }
    else if(n1.sign == true && n2.sign == false){
        if(n1.size > n2.size){
            return sub_mag(n1, n2);
        }
        else if(n1.size < n2.size){
            number n3 = sub_mag(n2, n1);
            n3.sign = false;
            return n3;
        }
        else{
            if(numberComparison(n1,n2) == 0)
                return init_number(0);
            else if(numberComparison(n1,n2) == 1)
                return sub_mag(n1,n2);
            else /*if(numberComparison(n1,n2) == 2)*/{
                number n3 = sub_mag(n2,n1);
                n3.sign = false;
                return n3;
            }
        }
    }

    else if(n1.sign == false && n2.sign == true){
        if(n2.size > n1.size){
            return sub_mag(n2, n1);
        }
        else if(n2.size < n1.size){
            number n3 = sub_mag(n1, n2);
            n3.sign = false;
            return n3;
        }
        else{
            if(numberComparison(n1,n2) == 0)
                return init_number(0);
            else if(numberComparison(n2,n1) == 1)
                return sub_mag(n2,n1);
            else /*if(numberComparison(n2,n1) == 2)*/{
                number n3 = sub_mag(n1,n2);
                n3.sign = false;
                return n3;
            }
        }
    }

    else{
        number n3 = add_mag(n1,n2);
        n3.sign = false;
        return n3;
    }
}

number sub(number n1, number n2){
    if(n1.sign == true && n2.sign == false){
        return add_mag(n1,n2);
    }
    else if(n1.sign == true && n2.sign == true){
        if(n1.size > n2.size){
            return sub_mag(n1, n2);
        }
        else if(n1.size < n2.size){
            number n3 = sub_mag(n2, n1);
            n3.sign = false;
            return n3;
        }
        else{
            if(numberComparison(n1,n2) == 0)
                return init_number(0);
            else if(numberComparison(n1,n2) == 1)
                return sub_mag(n1,n2);
            else /*if(numberComparison(n1,n2) == 2)*/{
                number n3 = sub_mag(n2,n1);
                n3.sign = false;
                return n3;
            }
        }
    }

    else if(n1.sign == false && n2.sign == false){
        if(n2.size > n1.size){
            return sub_mag(n2, n1);
        }
        else if(n2.size < n1.size){
            number n3 = sub_mag(n1, n2);
            n3.sign = false;
            return n3;
        }
        else{
            if(numberComparison(n1,n2) == 0)
                return init_number(0);
            else if(numberComparison(n2,n1) == 1)
                return sub_mag(n2,n1);
            else /*if(numberComparison(n2,n1) == 2)*/{
                number n3 = sub_mag(n1,n2);
                n3.sign = false;
                return n3;
            }
        }
    }

    else{
        number n3 = add_mag(n1,n2);
        n3.sign = false;
        return n3;
    }
}

/* returns n1 - n2 */
number sub_mag(number n1, number n2){
    char diff;
    char borrow = 0;
    node* temp1 = n1.tail;
    node* temp2 = n2.tail;

    diff = (temp1->data - temp2->data + 10);
    borrow = diff / 10;
    borrow = borrow ^ 1;
    diff = diff % 10;
//    printf("%d - %d - %d = %d\n",temp1->data, temp2->data, borrow, diff);
    number n3 = init_number(diff);
    temp1 = temp1->prev;
    temp2 = temp2->prev;
    
    while(temp1 != NULL || temp2 != NULL){
        if(temp1 != NULL && temp2 == NULL){
            diff = temp1->data - borrow ; 
            borrow = 0;
 //           printf("%d - %d - %d = %d\n",temp1->data, temp2->data, borrow, diff);
            insertDigitAtHead(&n3,diff);
            temp1 = temp1->prev;
        }
        else if(temp1 != NULL && temp2 != NULL){
            diff = (temp1->data - temp2->data - borrow + 10);
            borrow = diff / 10;
            diff = diff % 10;
            borrow = borrow ^ 1;
//            printf("%d - %d - %d = %d\n",temp1->data, temp2->data, borrow, diff);
            insertDigitAtHead(&n3, diff);
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
    }
    return n3;
}

char numberComparison(number n1, number n2){
    /* 
     *  return 1 if n1 is greater than n2
     *  return 2 if n1 is smaller than n2
     *  return 0 if n1 is equal to n2
     */
    if(n1.size > n2.size){
        return 1;
    } 

    else if(n1.size < n2.size){
        return 2;
    }

    else if(n1.size == n2.size){

        node* temp1 = (n1.head); 
        node* temp2 = (n2.head); 
        while(temp1 != NULL){
            if(temp1->data > temp2->data){
                 return 1;
            } 
            else if(temp1->data < temp2->data){
                 return 2;
            } 
    
            else if(temp1->data == temp2->data){
                 temp1 = temp1->next;
                 temp2 = temp2->next;
            }
    
        }
        return 0;
    }

}
