# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/29 15:02:38 by bmoodley          #+#    #+#              #
#    Updated: 2017/12/17 10:44:50 by bmoodley         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_charequ.c\
	  ft_countwords.c\
	  ft_isascii.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_isupper.c\
	  ft_islower.c\
	  ft_isspace.c\
	  ft_itoa.c\
	  ft_memdel.c\
	  ft_memcmp.c\
	  ft_memset.c\
	  ft_memcpy.c\
	  ft_memalloc.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memmove.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putchar_fd.c\
	  ft_putendl_fd.c\
	  ft_putchar.c\
	  ft_putstr_fd.c\
	  ft_putnbr_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_endl.c\
	  ft_print2dchar.c\
	  ft_strlen.c\
	  ft_strlcat.c\
	  ft_strcmp.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_strncmp.c\
	  ft_striteri.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strcpy.c\
	  ft_strncpy.c\
	  ft_strcat.c\
	  ft_strncat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strjoin.c\
	  ft_strnew.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strsplit.c\
	  ft_strsplitn.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -I includes
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
