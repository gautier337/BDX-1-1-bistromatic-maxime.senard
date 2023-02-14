/*
** EPITECH PROJECT, 2021
** do_op
** File description:
** computes an operations
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *op_sum(char *a, char *b);

char *op_diff(char *a, char *b);

char *op_prod(char *a, char *b);

char *op_div(char *a, char *b);

char *op_mod(char *a, char *b);

static void check_op(char c, char *b)
{
    if ((c == '/') && (b[0] == '0')) {
        my_putstr("Error");
        exit(84);
    } else if ((c == '%' && (b[0] == '0'))) {
        my_putstr("Error");
        exit(84);
    }
}

char *compute_op(char *a, char c, char *b)
{
    char str_op[] = {'+', '-', '*', '/', '%', 0};
    char *(*op[])(char*, char*) = {&op_sum, &op_diff, &op_prod,
        &op_div, &op_mod, 0};
    int i = 0;

    check_op(c, b);
    for (; c != str_op[i]; i++) {
        if (str_op[0] == 0) {
            my_putstr("Stop : invalid syntax");
            exit(84);
        }
    }
    return (op[i](a, b));
}

char *do_op(int argc, char **argv)
{
    char *result;

    if ((argv[2][0] == '/') && (argv[3][0] == '0')) {
        write(2, "Stop : division by zero\n", 24);
        return (0);
    }
    if ((argv[2][0] == '%' && (argv[3][0] == '0'))) {
        write(2, "Stop : modulo by zero\n", 22);
        return (0);
    }
    if (argc != 4) {
        write(2, "Stop : invalid args\n", 20);
        return (0);
    }
    result = compute_op(argv[1], argv[2][0], argv[3]);
    return (result);
}
