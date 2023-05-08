# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 18:30:27 by mabaron-          #+#    #+#              #
#    Updated: 2023/01/06 14:37:43 by mabaron-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c ft_undecimal_fd.c \
		ft_puthex.c ft_putpointer.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

all : $(NAME)

$(NAME) : $(OBJ) ft_printf.h
			@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ) $(NAME)
fclean: clean
	@$(RM) $(NAME)
re: fclean all