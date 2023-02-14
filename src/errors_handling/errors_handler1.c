/*
** EPITECH PROJECT, 2021
** errors_handler
** File description:
** errors
*/

#include <stdlib.h>
#include "my.h"

void check_opbase(char **argv, int i)
{
    int x;

    for (x = 0; x < my_strlen(argv[2]); x++) {
        if (argv[1][i] == argv[2][x]) {
            my_putstr("syntax error");
            exit(84);
        }
    }
}

void check_two_same(char *str, int i)
{
    int x;

    for (x = 0; x < my_strlen(str); x++) {
        if (str[i] == str[x] && x != i) {
            my_putstr("syntax error");
            exit(84);
        }
    }
}

int error(int argc, char **argv)
{
    int i = 0;
    if (argc != 4) {
        my_putstr("syntax error");
        return 84;
    }
    if (my_strlen(argv[1]) < 2 ||
        my_strlen(argv[2]) != 7 || my_getnbr(argv[3]) == 0) {
        my_putstr("syntax error");
        return 84;
    }
    for (i = 0; i < my_strlen(argv[1]); i++)
        check_opbase(argv, i);
    for (i = 0; i < my_strlen(argv[1]); i++)
        check_two_same(argv[1], i);
    for (i = 0;	i < my_strlen(argv[2]); i++)
        check_two_same(argv[2], i);
    return 0;
}

int error2(char *operation)
{
    int parent_open = 0;
    int parent_close = 0;

    for (int i = 0; i < my_strlen(operation); i++) {
        if (operation[i] == '(')
            parent_open++;
        else if (operation[i] == ')')
            parent_close++;
    }
    if (!(parent_open == parent_close)) {
        my_putstr("syntax error");
        return (84);
    } else
        return 0;
}
