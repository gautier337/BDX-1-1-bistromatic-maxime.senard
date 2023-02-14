/*
** EPITECH PROJECT, 2021
** criterion syntax error
** File description:
** syntax error criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int error(int argc, char **argv);

int error2(char *operation);

int error5(char *operation);

void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error, test_error, .init = redirect)
{
    char *av[5] = {"./calc", "0", "()+-*/%", "3", NULL};

    error(3, av);
    cr_assert_stdout_eq_str("syntax error");
}

Test(error2, test_error, .init = redirect)
{
    char operation[5] = "(3+6";

    error2(operation);
    cr_assert_stdout_eq_str("syntax error");
}

Test(error5, test_error, .init = redirect)
{
    char operation[5] = "3//6";

    error5(operation);
    cr_assert_stdout_eq_str("syntax error");
}
