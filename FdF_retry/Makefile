# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 15:54:09 by bmoodley          #+#    #+#              #
#    Updated: 2018/01/11 15:54:11 by bmoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
		keys.c \
		window.c \
		utils.c \

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = -L. libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	gcc -o $(NAME) $(SRC) $(LIB) $(FLAGS) $(MLX)

clean:
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean:	clean
	$(MAKE) fclean -C ./libft

re: fclean all
