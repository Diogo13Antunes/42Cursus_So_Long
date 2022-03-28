# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:29:35 by dcandeia          #+#    #+#              #
#    Updated: 2021/11/17 09:47:18 by dcandeia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC  = 	ft_strlen.c				\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_itoa_base.c			\

CC =gcc
RM =rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)
