# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaron- <mabaron-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 14:56:23 by mabaron-          #+#    #+#              #
#    Updated: 2023/05/23 19:50:00 by mabaron-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk


SRC_S = server.c
SRC_C = client.c

c_src = utils.c
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft.a
LIBFTD = libft/

all : client server
client: client.o
	$(MAKE) -C $(LIBFTD) 
	$(CC) $(CFLAG) $(LIBFTD)$(LIBFT) $(OBJ_C) -o client

server: server.o
	$(MAKE) -C $(LIBFTD) 
	$(CC) $(CFLAG) $(LIBFTD)$(LIBFT) $(OBJ_S) -o server
	
clean:
	@$(RM) $(OBJ_C) $(OBJ_S) client server
fclean: clean
	@$(RM)
	$(MAKE) -C $(LIBFTD) fclean

re: fclean all
