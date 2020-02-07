NAME = libftprintf.a
NAME_TEST = test_ft_printf
SRC = ft_itoa_base.c ft_print_int.c ft_printf.c parcer.c string_print.c char_print.c percent_print.c printf_help.c printf_help_2.c pointer_print.c long_double_print.c
OBJ = *.o libft/*.o
INCL = .
FLAGS = -g -Wall -Werror -Wextra

$(NAME):
	make -C libft/ fclean && make -C libft/ all
	gcc $(FLAGS) -I $(INCL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(NAME_TEST):
	clang $(FLAGS) -I $(INCL) -o main.o -c main.c
	clang -g -o $(NAME_TEST) main.o -L. -lftprintf

all: $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_TEST)
	make -C libft/ fclean

re: fclean all

pr: fclean $(NAME) $(NAME_TEST)

.PHONY: all clean fclean re pr