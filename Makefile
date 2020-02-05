# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iariss <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/27 13:17:36 by iariss            #+#    #+#              #
#    Updated: 2020/01/01 15:42:11 by iariss           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGUES = -Wall -Werror -Wextra
INCLUDES = c.h

SRC = ft_printf.c ft_new.c ft_printc.c ft_atoi.c ft_printwid.c ft_putchar.c ft_substr.c ft_strlen.c ft_prints.c\
ft_printn.c ft_printhexa.c ft_printp.c ft_print0.c ft_putstr.c ft_itoa.c ft_printu.c ft_printx.c ft_convert.c ft_printhx.c\
ft_condd.c

OBJ = ft_printf.o ft_new.o ft_printc.o ft_atoi.o ft_printwid.o ft_putchar.o ft_substr.o ft_strlen.o ft_prints.o\
ft_printn.o ft_printhexa.o ft_printp.o ft_print0.o ft_putstr.o ft_itoa.o ft_printu.o ft_printx.o ft_convert.o ft_printhx.o\
ft_condd.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	gcc -g $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
