# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 14:22:06 by bebrandt          #+#    #+#              #
#    Updated: 2024/01/19 11:09:41 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test_get_next_line

NAME_BONUS	=	test_get_next_line_bonus

SRCS		=	get_next_line.c get_next_line_utils.c main.c

SRCS_BONUS	=	get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c

OBJS		:=	$(SRCS:.c=.o)

OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)

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
	$(CC) $(HDRS) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:	$(OBJS_BONUS)
	$(CC) $(HDRS) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
