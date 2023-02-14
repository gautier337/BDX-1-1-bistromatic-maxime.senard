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

int where_it_is(char *base, char result);

char *change_base(char *nbr, char *base);

char *convert_base1(char *result, char *base)
{
    int tmp = 0;
    char *res = malloc(sizeof(char) * my_strlen(result) + 2);
    char base10[10] = "0123456789";

    for (int i = 0; my_strlen(result) > i; i++) {
        tmp = where_it_is(base, result[i]);
        if (tmp != -1) {
            res[i] = base10[tmp];
        } else {
            res[i] = result[i];
        }
    }
    return res;
}

char *put_in_result(char *result, char *temp, char *base)
{
    temp = change_base(temp, base);
    result = my_strcat(result, temp);
    return result;
}

char *convert_other(char *to_convert, char *base, char *temp, char *result)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < my_strlen(to_convert); i++) {
        if (where_it_is(base, to_convert[i]) != -1) {
            temp[k] = to_convert[i];
            k++;
        } else if (k > 10) {
            exit(84);
        } else {
            result = put_in_result(result, temp, base);
            k = 0;
            temp = malloc(sizeof(char) * 10);
            j = my_strlen(result);
            result[j] = to_convert[i];
        }
    }
    return (put_in_result(result, temp, base));
}

char *convert_mai(char *to_convert, char *base)
{
    char *temp = malloc(sizeof(char) * 10);
    char *result = malloc(sizeof(char) * my_strlen(base) * 5);

    if (my_strlen(base) == 10)
        return convert_base1(to_convert, base);
    else
        return convert_other(to_convert, base, temp, result);
}
