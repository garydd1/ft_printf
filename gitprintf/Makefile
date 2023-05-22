# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 10:24:42 by dgarizad          #+#    #+#              #
#    Updated: 2022/12/02 10:24:45 by dgarizad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_putptr.c  ft_putnbr.c

OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	@gcc -Wall -Wextra -Werror $< -c $(<:.c.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	
clean :
	rm  -f *.o
fclean: clean
		rm -f $(NAME)
re: fclean all
.PHONY : all clean fclean bonus re 
