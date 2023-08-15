# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 11:10:39 by sbzizal           #+#    #+#              #
#    Updated: 2022/12/28 14:08:39 by sbzizal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putnbr_hex.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putadd.c ft_unsigned.c \

OBGS = ${SRCS:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(NAME) : $(OBGS)
	@ar rc $(NAME) $(OBGS)

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $<

clean :
	rm -f $(OBGS)

fclean : clean
	rm -f ${NAME}

re : fclean all
