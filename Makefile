# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 23:02:27 by bmoodley          #+#    #+#              #
#    Updated: 2017/07/01 11:03:32 by bmoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

SRC = FdF.c\
	  lines.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	gcc -o $(NAME) $(SRC) $(FLAGS) 

clean:
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean:	clean
	$(MAKE) fclean -C ./libft

re: flcean all
