# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 14:22:06 by bebrandt          #+#    #+#              #
#    Updated: 2023/11/06 11:35:20 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	test_get_next_line

SRCS	=	get_next_line.c get_next_line_utils.c main.c

OBJS		:=	$(SRCS:.c=.o)

HDRS		=	-I .

CC			=	gcc

BUFFER_MACCRO = BUFFER_SIZE=

BS =

ifdef BS
CFLAGS		=	-Wall -Wextra -Werror -D $(BUFFER_MACCRO)$(BS) -g
else
CFLAGS		=	-Wall -Wextra -Werror -g
endif

RM			=	rm -f

all: $(NAME)

%.o:	%.c
	$(CC) $(HDRS) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(HDRS) $(CFLAGS) $(OBJS) -o $(NAME)  -fsanitize=address

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
