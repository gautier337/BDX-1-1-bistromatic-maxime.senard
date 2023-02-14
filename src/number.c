/*
** EPITECH PROJECT, 2021
** cpoolprojects evalexpr
** File description:
** task02 : number
*/

#include "my.h"
#include <stdlib.h>

char *my_concatstr(char *str1, char *str2);

char *compute_op(char *a, char c, char *b);

char *do_op(int ac, char **av);

char *change_nb_sign(char *nbr, int is_neg)
{
    char *res;
    int lennbr = my_strlen(nbr);

    if (is_neg == -1) {
        res = malloc(sizeof(char) * (lennbr + 2));
        for (int i = 0; i < lennbr; i++)
            res[i + 1] = nbr[i];
        res[0] = '-';
        return res;
    }
    return nbr;
}

char *number(char **str_ptr)
{
    int i = 0;
    char *res;
    int neg = 1;

    while ((str_ptr[0][0] == '+') || (str_ptr[0][0] == '-')) {
        if (str_ptr[0][0] == '-')
            neg = neg * -1;
        str_ptr[0] = &str_ptr[0][1];
    }
    while ((str_ptr[0][i] >= '0') && (str_ptr[0][i] <= '9'))
        i++;
    res = malloc(sizeof(char) * (i + 2));
    for (int j = 0; j < i; j++)
        res[j] = str_ptr[0][j];
    str_ptr[0] = &str_ptr[0][i];
    res = change_nb_sign(res, neg);
    return (res);
}

char *to_str_loop(int n)
{
    int m = n;
    char *c;
    int i = 0;

    for (i = 0; n != 0; n /= 10, i++);
    c = malloc(sizeof(char) * (i + 2));
    for (i = 0; m != 0; m /= 10, i++)
        c[i] = (m % 10) + 48;
    c[i] = '-';
    c[i + 1] = '\0';
    return (c);
}

char *nbr_to_str(int n)
{
    if (n == 0)
        return ("0");
    if (n < 0)
        return (my_revstr(to_str_loop(-n)));
    else
        return (&my_revstr(to_str_loop(n))[1]);
}
