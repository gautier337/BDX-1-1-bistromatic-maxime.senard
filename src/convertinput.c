/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** converting input into decimal and under stable operators
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *convert_mai(char *to_convert, char *base);

char *convert_output(char *result, char *base);

char *checksymbol(char *calcul, char *symbol, int i)
{
    int x;
    char signe[8] = "()+-*/%\0";

    for (x = 0; x < 7; x++) {
        if (calcul[i] == symbol[x])
            calcul[i] = signe[x];
    }
    return calcul;
}

char *my_convertinput(char **av)
{
    char *symbol = av[2];
    char *base = av[1];
    int i;
    char *calcul = av[0];

    for (i = 0; i < my_strlen(calcul); i++) {
        checksymbol(calcul, symbol, i);
    }
    calcul = convert_mai(calcul, base);
    return calcul;
}

char checkbase2(char *calcul, char *base, int i)
{
    int x;
    char nombre[11] = "0123456789\0";
    char *result = malloc(sizeof(char) * my_strlen(calcul) + 1);

    for (x = 0; x < 10; x++) {
        if (calcul[i] == nombre[x]) {
            result[i] = base[x];
        } else
            result[i] = calcul[i];
    }
    return result[i];
}

char *my_convertoutput(char *result, char *base)
{
    int i;

    if (result[0] == '0')
        return "0";
    if (my_strlen(base) == 10) {
        for (i = 0; i < my_strlen(result); i++) {
            result[i] = checkbase2(result, base, i);
        }
    } else {
        result = convert_output(result, base);
    }
    return result;
}
