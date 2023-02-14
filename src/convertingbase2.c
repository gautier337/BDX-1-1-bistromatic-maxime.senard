/*
** EPITECH PROJECT, 2021
** convert base
** File description:
** converting base
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *nbr_to_str(int n);

char *to_str_loop(int n);

int where_it_is(char *base, char result)
{
    for (int x = 0; x < my_strlen(base); x++) {
        if (base[x] == result)
            return x;
    }
    return -1;
}

char *change_base(char *nbr, char *base)
{
    int k = my_strlen(nbr) - 1;
    int q = 0;
    int p = my_strlen(base);
    int tmp = 0;
    int result = 1;

    while (q < k) {
        tmp = where_it_is(base, nbr[q]);
        result = result + (tmp * my_compute_power_rec(p, k - q));
        q++;
    }
    return nbr_to_str(result);
}

char *convertion_of_the_output(int nbr, char *base)
{
    int q = my_strlen(base);
    int p = 0;
    int tmp = nbr;
    char *result = malloc(sizeof(char) * q * 5);
    int i = 0;

    while (my_compute_power_rec(q, p) <= nbr) {
        p = p + 1;
    }
    while (p >= 1) {
        tmp = tmp / (my_compute_power_rec(q, p) / q);
        result[i] = base[tmp];
        nbr = nbr - (my_compute_power_rec(q, p) / q) * tmp;
        tmp = nbr;
        i++;
        p = p - 1;
    }
    return (result);
}

char *convert_output(char *nbr, char *base)
{
    if (my_strlen(nbr) >= 10)
        return nbr;
    return convertion_of_the_output(my_getnbr(nbr), base);
}
