/*
** EPITECH PROJECT, 2021
** error4 bistro
** File description:
** division after parenthese
*/

#include <stdlib.h>
#include "my.h"

int error4(char *operation)
{
    for (int i = 0; i < my_strlen(operation); i++) {
        if (operation[i] == '(' &&
        (operation[i+1] == '/' ||
        operation[i+1] == '%' ||
        operation[i+1] == '*' ||
        operation[i+1] == '+')) {
            my_putstr("syntax error");
            return (84);
        }
        if (operation[i-1] == '\0' &&
        (operation[i] == '/' ||
        operation[i] == '%' ||
        operation[i] == '*' ||
        operation[i] == '+')) {
            my_putstr("syntax error");
            return (84);
        }
    }
    return 0;
}

int error5(char *operation)
{
    for (int i = 0; i < my_strlen(operation); i++) {
        if ((operation[i] == '*' ||
        operation[i] == '/' ||
        operation[i] == '%') &&
        (operation[i+1] == '/' ||
        operation[i+1] == '%' ||
        operation[i+1] == '*' )) {
            my_putstr("syntax error");
            return (84);
        }
    }
    return 0;
}
