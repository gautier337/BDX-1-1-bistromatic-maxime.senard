/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** primary function
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

char *extract_expr(char **str_ptr);

char *eval_expr(char const *str)
{
    char *res;
    char *my_str;
    int i;

    my_str = malloc(sizeof(char) * (my_strlen(str) + 2));
    for (i = 0; i < my_strlen(str); i++)
        my_str[i] = str[i];
    my_str[i] = ')';
    my_str[i + 1] = '\0';
    res = extract_expr(&my_str);
    return res;
}
