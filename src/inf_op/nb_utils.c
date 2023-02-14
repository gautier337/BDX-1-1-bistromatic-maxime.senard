/*
** EPITECH PROJECT, 2021
** inf_op
** File description:
** nb_utils
*/

#include <stdlib.h>
#include "my.h"

int is_neg_pos(char *nb)
{
    int i = 0;
    int is_neg = 1;

    while (nb[i] == '-' || nb[i] == '+') {
        if (nb[i] == '-')
            is_neg *= -1;
        i++;
    }
    return is_neg;
}

char *turn_nb_neg(char *nbsrc)
{
    char *nbdest = malloc(sizeof(char) * (my_strlen(nbsrc) + 2));

    nbdest[0] = '-';
    for (int i = 0; nbsrc[i] != '\0'; i++) {
        nbdest[i + 1] = nbsrc[i];
    }
    return nbdest;
}

char *turn_nb_pos(char *nbsrc)
{
    char *nbdest = malloc(sizeof(char) * my_strlen(nbsrc));
    for (int i = 0; nbsrc[i + 1] != '\0'; i++) {
        nbdest[i] = nbsrc[i + 1];
    }
    return nbdest;
}

char *rem_useless_zero(char *nbsrc)
{
    char *nbdest;
    int j = 0;
    int is_neg = 0;

    if (nbsrc[0] == '-') {
        is_neg = 1;
        nbsrc[0] = '0';
    }
    while (nbsrc[j] == '0')
        j++;
    nbdest = malloc(sizeof(char) * my_strlen(nbsrc) + 1 - j);
    for (int i = 0; nbsrc[i + j] != '\0'; i++) {
        nbdest[i] = nbsrc[i + j];
    }
    if (is_neg)
        nbdest = turn_nb_neg(nbdest);
    return nbdest;
}

char char_setter_nb(int i, char *nb)
{
    if (i > my_strlen(nb) - 1)
        return '0';
    else
        return nb[i];
}
