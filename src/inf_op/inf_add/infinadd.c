/*
** EPITECH PROJECT, 2021
** cpoolprojects evalexpr
** File description:
** functions for do_op
*/

#include "my.h"
#include <stdlib.h>
#include <stddef.h>

int is_neg_pos(char *nb);

char *turn_nb_neg(char *nbsrc);

char *turn_nb_pos(char *nbsrc);

char *rem_useless_zero(char *nbsrc);

char char_setter_nb(int i, char *nb);

int get_bigger_num(char *nb1, char *nb2);

char *format_res(char *res, int biggernb);

char *add_sub_handler(char *res, char *nb1, char *nb2, int biggernb);

char _process_add(int *ret, char charnb1, char charnb2)
{
    char result;

    charnb1 -= 48;
    charnb2 -= 48;
    result = charnb1 + charnb2;
    if (*ret == 1) {
        *ret = 0;
        result++;
    }
    if (result >= 10) {
        *ret = 1;
        result -= 10;
    }
    result += 48;
    return result;
}

char *process_add(char *res, char *nb1, char *nb2, int biggernb)
{
    int ret = 0;
    char charnb1;
    char charnb2;
    int i = 0;

    res = malloc(sizeof(char) * (biggernb + 2));
    nb1 = my_revstr(nb1);
    nb2 = my_revstr(nb2);
    do {
        charnb1 = char_setter_nb(i, nb1);
        charnb2 = char_setter_nb(i, nb2);
        res[i] = _process_add(&ret, charnb1, charnb2);
        i++;
    } while (nb1[i] != '\0' || nb2[i] != '\0');
    res[i] = ret + 48;
    res = my_revstr(res);
    return res;
}

char *infinadd(char *nb1, char *nb2)
{
    char *res;
    int biggernb = get_bigger_num(nb1, nb2);

    res = malloc(sizeof(char) * (biggernb + 2));
    res = add_sub_handler(res, nb1, nb2, biggernb);
    return format_res(res, biggernb);
}
