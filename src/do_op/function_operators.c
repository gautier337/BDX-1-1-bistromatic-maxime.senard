/*
** EPITECH PROJECT, 2021
** cpoolprojects evalexpr
** File description:
** functions for do_op
*/

#include "my.h"
#include <stdlib.h>

char *inf_add(char *nb1, char *nb2);

char *inf_sum(char *nb1, char *nb2);

char *inf_mult(char *nb1, char *nb2);

char *inf_div(char *nb1, char *nb2);

char *inf_mod(char *nb1, char *nb2);

char *op_sum(char *a, char *b)
{
    char *res = inf_add(a, b);
    return res;
}

char *op_diff(char *a, char *b)
{
    char *res = inf_sum(a, b);
    return res;
}

char *op_prod(char *a, char *b)
{
    char *res = inf_mult(a, b);
    return res;
}

char *op_div(char *a, char *b)
{
    char *res = inf_div(a, b);
    return res;
}

char *op_mod(char *a, char *b)
{
    char *res = inf_mod(a, b);
    return res;
}
