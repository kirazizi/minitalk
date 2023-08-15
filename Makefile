# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 11:20:10 by sbzizal           #+#    #+#              #
#    Updated: 2022/12/28 15:53:45 by sbzizal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MINI_TALK

CC = cc

FLAGS = -Wall -Wextra -Werror

all : ft_printf/libftprintf.a server client

ft_printf/libftprintf.a : 
	make -C ft_printf
	
server : server.c minitalk.h
	$(CC) $(FLAGS) ft_printf/libftprintf.a server.c -o server 
	
client : client.c minitalk.h
	$(CC) $(FLAGS) ft_printf/libftprintf.a client.c -o client

bonus : ft_printf/libftprintf.a client_bonus server_bonus

server_bonus : server_bonus.c minitalk.h
	$(CC) $(FLAGS) ft_printf/libftprintf.a server_bonus.c -o server_bonus
	
client_bonus : client_bonus.c minitalk.h
	$(CC) $(FLAGS) ft_printf/libftprintf.a client_bonus.c -o client_bonus
 
clean :
	rm -f server client server_bonus client_bonus

fclean : clean
	make fclean -C ft_printf

re : fclean all bonus

.PHONY : all fclean clean re