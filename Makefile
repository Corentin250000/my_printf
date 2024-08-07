##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/mini_printf.c	\
		src/int_to_char/int_to_char.c	\

SRC_UNIT_TESTS	=	tests/tests.c	\
					src/mini_printf.c	\
					src/int_to_char/int_to_char.c	\

OBJ	=	$(SRC:.c=.o)

OBJ_UNIT_TESTS	=	$(SRC_UNIT_TESTS:.c=.o)

NAME	=	mini-printf

CC	=	gcc

FLAGS	=	-Wall -Wextra -g

CFLAGS	=	-fprofile-arcs -ftest-coverage -O0

LIBS	=	--coverage -lcriterion

$(NAME):
		$(CC) -o $(NAME) $(SRC) $(FLAGS) $(CFLAGS) $(LIBS)

all:	$(NAME)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_UNIT_TESTS)
		find . -type f -name '*.gcda' -exec rm -f {} +
		find . -type f -name '*.gcno' -exec rm -f {} +
		find . -type f -name '*.gcov' -exec rm -f {} +

fclean:	clean
		rm -f $(NAME)
		rm -f a.out
		rm -f unit_tests
		rm -f coverage.info
		rm -f coverage_filtered.info
		rm -rf out

re:		fclean all

tests_run: $(OBJ_UNIT_TESTS)
		$(CC) -o unit_tests $(OBJ_UNIT_TESTS) $(FLAGS) $(CFLAGS) $(LIBS)
		./unit_tests --verbose
		lcov --capture --directory . --output-file coverage.info \
		--ignore-errors mismatch
		lcov --remove coverage.info '*/tests/*' --output-file \
		coverage_filtered.info
		genhtml coverage_filtered.info --output-directory out

coding_style:	fclean
			coding-style . .
			cat coding-style-reports.log
			rm -f coding-style-reports.log

.PHONY:	all clean fclean re tests_run coding_style
