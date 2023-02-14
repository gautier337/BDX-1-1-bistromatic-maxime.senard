/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** main file
*/

#include <stdlib.h>
#include "my.h"

char *my_convertinput(char **av);

char **my_read_echo(char **argv);

void display_h(void);

char *eval_expr(char const *str);

char *my_convertoutput(char *result, char *base);

int error(int argc, char **argv);

int error2(char *operation);

int error3(char *operation, char **argv);

int error4(char *operation);

int error5(char *operation);

void executeall(int argc, char **argv);

int main(int argc, char **argv)
{
    if (argc == 1) {
        my_putstr("syntax error");
        exit(84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        display_h();
        return 0;
    }
    executeall(argc, argv);
    return 0;
}

void executeall(int argc, char **argv)
{
    char *res;
    char **result;

    if (error(argc, argv) == 84)
        exit (84);
    result = my_read_echo(argv);
    if (error3(result[0], argv) == 84)
        exit (84);
    res = my_convertinput(result);
    if (error2(res) == 84 || error4(res) == 84 || error5(res) == 84)
        exit (84);
    res = eval_expr(res);
    res = my_convertoutput(res, argv[1]);
    my_putstr(res);
}
