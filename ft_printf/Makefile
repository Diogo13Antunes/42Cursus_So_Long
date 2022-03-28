# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 12:26:51 by dcandeia          #+#    #+#              #
#    Updated: 2021/12/15 12:46:39 by dcandeia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = libftprintf.a

SRC = 	Libft/ft_strlen.c				\
		Libft/ft_itoa_base.c			\
		ft_putescapes.c 				\
		ft_printf.c						\
		ft_putvar.c						\
		ft_putchar.c					\
		ft_putstr.c						\
		ft_putunnumbers.c				\
		ft_putnumbers.c					\
		ft_hexnumbers.c					\
		ft_putaddr.c					\
		

OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
