#include <stdbool.h>
#ifndef OPERATIONS_H_
#define OPERATIONS_H_

number add(number n1, number n2);
number add_mag(number n1, number n2);
number sub(number n1, number n2);
number sub_mag(number n1, number n2);
number mul(number n1, number n2);
number mul_mag(number n1, number n2);
number mul_by_constant(number n1, char a);
//number div(number n1, number n2);
//number div_mag(number n1, number n2);
char numberComparison(number, number);

#endif
