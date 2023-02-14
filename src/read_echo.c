/*
** EPITECH PROJECT, 2021
** read echo
** File description:
** return the result of the read and the argv
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char **my_malloc_av(char **argv)
{
    char **av =	malloc(sizeof(char *) * 5);
    int len_argv1 = my_strlen(argv[1]);
    int	len_argv2 = my_strlen(argv[2]);
    int len_read = my_getnbr(argv[3]);

    av[0] = malloc(sizeof(char) * len_read);
    av[1] = malloc(sizeof(char) * len_argv1);
    av[2] = malloc(sizeof(char) * len_argv2);
    return (av);
}

char **my_read_echo(char **argv)
{
    int len_read = my_getnbr(argv[3]);
    char *buff = malloc(sizeof(char) * len_read + 1);
    char **av = my_malloc_av(argv);

    if (len_read != read(0, buff, len_read)) {
        my_putstr("syntax error");
        exit(84);
    }
    av[0] = buff;
    av[1] = argv[1];
    av[2] = argv[2];
    av[3] = argv[3];
    av[4] = 0;
    return av;
}
