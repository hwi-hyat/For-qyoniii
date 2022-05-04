# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 00:12:48 by siykim            #+#    #+#              #
#    Updated: 2022/05/04 22:21:52 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
	   1_0check_map.c\
	   1_1check_detail.c\
	   1_2make_AJTCS.c\
	   2_0make_map.c\
	   3_0find_square.c\
	   3_1find_square_utils.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJECTS)
	$(CC)	$(CFLAGS)	-o	$(NAME)	$(OBJECTS)

clean:
	rm	-f	$(OBJECTS)

fclean: clean
	rm	-f	$(NAME)
	
re: fclean all

.PHONY: all clean fclean re
