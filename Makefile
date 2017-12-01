# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 18:31:48 by jpinyot           #+#    #+#              #
#    Updated: 2017/12/01 19:41:18 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

SRC =	get_next_line.c\
		main.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
			@$(MAKE) -C libft
		 	@gcc -Wall -Werror -Wextra $(OBJ) -Llibft/ -lft -Ilibft/. -o $(NAME)

%.o: %.c
	@gcc -Wall -Werror -Wextra -Ilibft/ -c $<

clean:
			@$(MAKE) -C libft clean
		 	@/bin/rm -rf *.o

fclean: clean
			@$(MAKE) -C libft fclean
		 	@/bin/rm -f $(NAME)

re: fclean
	make



.PHONY: clean fclean re all
