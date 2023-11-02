# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 14:22:06 by bebrandt          #+#    #+#              #
#    Updated: 2023/11/02 12:13:49 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	test_get_next_line

SRCS	=	get_next_line.c get_next_line_utils.c main.c

OBJS		:=	$(SRCS:.c=.o)

HDRS		=	-I .

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all: $(NAME)

%.o:	%.c
	$(CC) $(HDRS) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(HDRS) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
