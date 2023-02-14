/*
** EPITECH PROJECT, 2021
** inf_mult
** File description:
** muliply inf mult
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *infinadd(char *nb1, char *nb2);

char *nbr_to_str(int n);

char *bigmult(char *nbr1, char *nbr2)
{
    char *res = nbr1;
    char *minus = "-1";

    while (nbr2[0] != '\0') {
        res = infinadd(res, nbr1);
        nbr2 = infinadd(nbr2, minus);
    }
    return res;
}

char *smallmult(char *nb1, char *nb2)
{
    int nbr1 = 0;
    int nbr2 = 0;
    int res = 0;

    nbr1 = my_getnbr(nb1);
    nbr2 = my_getnbr(nb2);
    res = nbr1 * nbr2;
    return nbr_to_str(res);
}

char *inf_mult(char *nb1, char *nb2)
{
    char *res;

    if (my_strlen(nb1) <= 5 && my_strlen(nb2) <= 5)
        res = smallmult(nb1, nb2);
    else if (my_str_isnum(nb1) && my_str_isnum(nb2))
        return "0";
    else
        exit(84);
    return res;
}
