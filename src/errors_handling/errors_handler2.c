/*
** EPITECH PROJECT, 2021
** handler_error3
** File description:
** bistro
*/

#include "my.h"
#include <stdlib.h>

int boucle1_error3(char c, char **argv)
{
    int yesorno = 1;

    for (int i = 0; i < my_strlen(argv[1]); i++) {
        if (c == argv[1][i])
            yesorno = 0;
    }
    for (int i = 0; i < my_strlen(argv[2]); i++) {
        if (c == argv[2][i])
            yesorno = 0;
    }
    return yesorno;
}

int error3(char *operation, char **argv)
{
    if (operation[0] == ')') {
        my_putstr("syntax error");
        return (84);
    }
    for (int i = 0; i < my_strlen(operation); i++) {
        if (boucle1_error3(operation[i], argv) == 1) {
            my_putstr("syntax error");
            return (84);
        }
    }
    return 0;
}
