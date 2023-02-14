##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Llib -lmy -g
override CPPFLAGS += -Iinclude

TESTSRC = tests/test_make.c \
					tests/test_syntax.c

TESTOBJ = $(TESTSRC:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

SRC = src/do_op/do_op.c \
			src/do_op/function_operators.c \
			src/convertinput.c \
			src/evalexpr.c \
			src/extract_expr.c \
			src/full_summands.c \
			src/help_menu.c \
			src/number.c \
			src/read_echo.c \
			src/summands.c \
			src/errors_handling/errors_handler1.c \
			src/errors_handling/errors_handler2.c \
			src/errors_handling/errors_handler3.c \
			src/inf_op/nb_utils.c \
			src/inf_op/nb_utils2.c \
			src/inf_op/operator_handler.c \
			src/inf_op/inf_add/inf_add.c \
			src/inf_op/inf_add/infinadd.c \
			src/inf_op/inf_sum/inf_sum.c \
			src/inf_op/inf_sum/infinsum.c \
			src/inf_op/inf_mult/inf_mult.c \
			src/inf_op/inf_div/inf_div.c \
			src/inf_op/inf_mod/inf_mod.c \
			src/convertingbase.c \
			src/convertingbase2.c

OBJ = $(SRC:.c=.o)

HEADER = my.h

NAME = calc

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
				make -C lib/my
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
				rm -f $(OBJ)
				make clean -C lib/my

fclean: clean
				rm -f $(NAME)
				make fclean -C lib/my

re: fclean all

tests_run:	CFLAGS += -lcriterion --coverage
tests_run: re $(TESTOBJ)
				gcc -o unit_tests $(TESTOBJ) $(SRC) $(CFLAGS) $(CPPFLAGS)
				./unit_tests

cover:
				gcovr --exclude tests
				gcovr --exclude tests --branches
				rm -f unit_tests*
