
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osamooja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 19:31:18 by osamooja          #+#    #+#              #
#    Updated: 2019/10/19 15:37:52 by osamooja         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRC = source/*.c
OBJ = *.o
INCL = includes
FLAGS = -g -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) -I $(INCL) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
