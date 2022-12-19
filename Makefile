# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 07:50:53 by jchapell          #+#    #+#              #
#    Updated: 2022/11/10 01:49:27 by jchapell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c ft_int2hex.c

OBJS	= ${SRC:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
				make -C libft
				mv libft/libft.a $(NAME)
				ar rc $(NAME) $(OBJS)

test: ${NAME}
	gcc $(OBJS) -L. -lftprintf -o printf

clean:
		rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}
			make -C ./libft clean

re:			fclean all

.PHONY:		all clean fclean