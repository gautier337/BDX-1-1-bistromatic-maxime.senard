/*
** EPITECH PROJECT, 2021
** inf_op
** File description:
** handle neg for operation
*/

char *format_res(char *res, int biggernb);

int is_neg_pos(char *nb);

char *turn_nb_pos(char *nbsrc);

char *turn_nb_neg(char *nbsrc);

char *process_add(char *res, char *nb1, char *nb2, int biggernb);

char *process_sum(char *res, char *nb1, char *nb2, int biggernb);

char *rem_useless_zero(char *nbsrc);


char *add_sub_handler(char *res, char *nb1, char *nb2, int biggernb)
{
    int nb1neg = is_neg_pos(nb1);
    int nb2neg = is_neg_pos(nb2);

    if (nb1neg > 0 && nb2neg > 0)
        res = process_add(res, nb1, nb2, biggernb);
    else if (nb1neg < 0 && nb2neg < 0) {
        nb1 = turn_nb_pos(nb1);
        nb2 = turn_nb_pos(nb2);
        res = process_add(res, nb1, nb2, biggernb);
        res = turn_nb_neg(res);
    } else
        res = process_sum(res, nb1, nb2, biggernb);
    res = rem_useless_zero(res);
    return res;
}
