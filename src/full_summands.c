/*
** EPITECH PROJECT, 2021
** cpoolprojects evalexpr
** File description:
** evalexpr changed functions
*/

#include "my.h"
#include <stdlib.h>

char *compute_op(char *a, char c, char *b);

char operand_sum(char **str_ptr);

char *factors(char **str_ptr);

char *better_summands(char **str_ptr)
{
    int i = 0;
    char *sum = factors(str_ptr);
    char c = 0;
    char *nbr2;

    while (str_ptr[0][0] != '\0') {
        c = operand_sum(str_ptr);
        nbr2 = factors(str_ptr);
        sum = compute_op(sum, c, nbr2);
        i++;
    }
    return sum;
}
