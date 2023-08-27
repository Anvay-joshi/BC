#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "numbers.h"
#include "doubly_LL.h"
#include "operations.h"

#include "stack_numbers.h"
#include "stack.h"

#define MAX_EXPRESSION_LENGTH 100

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isPoint(char c){
    return (c == '.');
}

int isNumber(char c){
    return (isdigit(c) || isPoint(c));
}

int precedence(char operator) {
    if (operator == '*' || operator == '/')
        return 2;
    if (operator == '+' || operator == '-')
        return 1;
    return 0;
}

number* applyOperator(number* a, number* b, char operator) {
    switch (operator) {
        case '+': 
            //printf("adding ");
            //displayNumber(a);
            //printf("and ");
            //displayNumber(b);
            return add(a, b);

        case '-': 
            //printf("subtracting ");
            //displayNumber(a);
            //printf("from ");
            //displayNumber(b);
            return sub(a, b);

        case '*': 
            //printf("multiply ");
            //displayNumber(a);
            //printf("and ");
            //displayNumber(b);
            return mul(a, b);
            //case '/': return a / b;
    }
    return init_number_ptr(0);
}

number* evaluateExpression(char *expression) {
    number nul = init_number(-1);
    char nul_char = '0';
    stack opStack;
    opStack = init_stack(&nul_char);
    stack_number numStack;
    numStack = init_stack_number(&nul);

    int len = strlen(expression);
    number* temp;
    for (int i = 0; i < len; i++) {
        temp = NULL;
        if (expression[i] == ' ') {
            continue;
        } 
        else if (isNumber(expression[i])) {
            //printf("\t %c occured\n",expression[i]);
            int j = 0;
            int deci_pos = 0;
            int deci_flag = 0;
            while (i < len && isNumber(expression[i])) {
                if(isPoint(expression[i]) && deci_flag == 0){
                    deci_flag = 1;
                    i++;
                    
                }
                else if(isPoint(expression[i]) && deci_flag == 1){
                    temp = init_number_ptr(0);
                    printf("\n\nmultiple Decinal point exception!!\n\n");
                    return temp;
                }
                else if(isdigit(expression[i])){
                    if(deci_flag == 1){
                        deci_pos++;
                    }
                    if(j == 0){
                        //printf("initializing with %c\n",expression[i]);
                        temp = init_number_ptr(expression[i] - '0');
                    }
                    else{
                        //printf("appending %c\n",expression[i]);
                        insertDigitAtEnd(temp, expression[i] - '0');
                    }
                    j++;
                    i++;

                    if(!(isNumber(expression[i]))){
                        temp->decimal_pos = deci_pos;
                        push_number(&numStack, temp);

                    }
                }
            }
            i--;
        } 
        else if(expression[i] == '('){
            //printf("operator %c occured\n", expression[i]);
            push(&opStack, &(expression[i]));
        }

        else if(expression[i] == ')'){
            //printf("operator %c occured\n", expression[i]);
            while(*stack_top(opStack) != nul_char && *stack_top(opStack) != '('){
                number b = *stack_number_top(numStack);
        //printf("old numStack is:\n");
        //print_stack_number(numStack);
                pop_number(&numStack);
        //printf("\n\nnumber b is:\n");
        //displayNumber(b);
        //printf("new numStack is:\n");
        //print_stack_number(numStack);
                number a = *stack_number_top(numStack);
                pop_number(&numStack);
        //printf("\n\nnumber a is:\n");
        //displayNumber(a);
        //printf("new numStack is:\n");
        //print_stack_number(numStack);
                char op = *stack_top(opStack);
                pop(&opStack);
                number* result = applyOperator(&a, &b, op);
                push_number(&numStack, result);
                
            }
            pop(&opStack);
        }

        else if (isOperator(expression[i])) {
            //printf("operator %c occured\n", expression[i]);
            while ((*stack_top(opStack) != -1) && precedence(*stack_top(opStack)) >= precedence(expression[i])) {
                number b = *stack_number_top(numStack);
                //printf("\n\nnumber b is:\n");
                //displayNumber(b);
                //pop_number(&numStack);
                number a = *stack_number_top(numStack);
                //printf("\n\nnumber a is:\n");
                //displayNumber(a);
                pop_number(&numStack);
                char op = *stack_top(opStack);
                pop(&opStack);
                number* result = applyOperator(&a, &b, op);
                push_number(&numStack, result);
            }
            push(&opStack, &(expression[i]));
        }
    }

    while (*stack_top(opStack) != nul_char) {
        number b = *stack_number_top(numStack);
        pop_number(&numStack);
        number a = *stack_number_top(numStack);
        pop_number(&numStack);
        char op = *stack_top(opStack);
        pop(&opStack);
        number* result = applyOperator(&a, &b, op);
        push_number(&numStack, result);
    }

    return stack_number_top(numStack);
    }

    int main(int argc, char* argv[]){
        char expression[MAX_EXPRESSION_LENGTH];
        char input[MAX_EXPRESSION_LENGTH];

        while (1) {
            if (argc > 1) {
                strncpy(expression, argv[1], MAX_EXPRESSION_LENGTH);
                argc = 0; // Reset argc to avoid reusing the same expression in loop
            } else {
                printf("Enter an infix expression (or 'X' to exit): ");
                fgets(input, sizeof(input), stdin);
                if (input[0] == 'X' || input[0] == 'x') {
                    break;
                }
                strncpy(expression, input, MAX_EXPRESSION_LENGTH);
            }

            number* result = evaluateExpression(expression);
            printf("result\n");
            //printf("%d\n", result.decimal_pos);
            displayNumber(result);
            //printf("Result: %d\n", result);
        }


        return 0;
    }




    //    number n1 = init_number(1);
    //    insertDigitAtEnd(&n1, 6);
    //    insertDigitAtEnd(&n1, 3);
    //    displayNumber(n1);
    //
    //    number n2 = init_number(4);
    //    insertDigitAtEnd(&n2, 5);
    //    insertDigitAtEnd(&n2, 7);
    //    displayNumber(n2);
    //    
    //    n1.sign = false;
    //    n2.sign = false;
    //
    //    number n3 = mul(n2,n1);
    //    displayNumber(n3);
    //    printf("\n\n");
    //
    ////    number n4 = mul_by_constant(n1,2);
    ////    displayNumber(n4);
    ////    printf("\n\n");
    ////    number n4 = div_mag(n2,n1);
    ////    displayNumber(n4);
    //    printf("\n\n");
    //
    //
