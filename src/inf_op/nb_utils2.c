/*
** EPITECH PROJECT, 2021
** inf_op
** File description:
** nb_utils2
*/

#include <stdlib.h>
#include "my.h"

int get_bigger_num(char *nb1, char *nb2)
{
    int lennb1 = my_strlen(nb1);
    int lennb2 = my_strlen(nb2);

    if (lennb1 > lennb2)
        return lennb1;
    else
        return lennb2;
}

char *format_res(char *res, int biggernb)
{
    char *finres;

    if ((res[0] == '+' && res[1] == '0') || (res[0] == '-' && res[1] == '0')) {
        finres = malloc(sizeof(char) * (biggernb + 1));
        for (int i = 1; res[i] != '\0'; i++)
            finres[i] = res[i + 1];
        finres[0] = res[0];
    } else {
        finres = malloc(sizeof(char) * (biggernb + 2));
        my_strcpy(finres, res);
    }
    if (finres[0] == '+') {
        res = malloc(sizeof(char) * (my_strlen(finres + 1)));
        for (int i = 0; finres[i] != '\0'; i++)
            res[i] = finres[i + 1];
        return res;
    } else
        return finres;
}
