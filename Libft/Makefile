# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:29:35 by dcandeia          #+#    #+#              #
#    Updated: 2022/03/08 12:55:00 by dcandeia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = 	ft_lstnew					\
		ft_lstadd_front				\
		ft_lstsize					\
		ft_lstlast					\
		ft_lstclear					\
		ft_lstadd_back

CC =gcc
RM =rm -f
CFLAGS = -Wall -Werror -Wextra -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o) $(BONUS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)
bonus:	$(SRC:=.o)	$(BONUS:=.o)
		ar rc $(NAME) $(SRC:=.o)	$(BONUS:=.o)
