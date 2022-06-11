# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 19:14:49 by atopalli          #+#    #+#              #
#    Updated: 2022/06/11 19:14:49 by atopalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I -nostartfiles
RM = rm -f

MANDATORY = ft_printf.c
MANDATORY_OBJ = $(MANDATORY:.c=.o)

$(NAME): $(MANOBJS)
	ar rcs $(NAME) $(MANDATORY_OBJ)
all: $(NAME)
clean:
	$(RM) $(MANDATORY_OBJ)
fclean: clean
	$(RM) *.out *.a
re: fclean all
