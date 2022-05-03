# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 00:12:48 by siykim            #+#    #+#              #
#    Updated: 2022/02/24 11:58:21 by tson             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
	   1_0check_input1.c\
	   1_1check_input2.c\
	   1_2mystring.c\
	   2_0map_maker.c\
	   3_0square_finder.c\
	   3_1square_finder_utilities.c

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
