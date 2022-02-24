# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 20:19:20 by siykim            #+#    #+#              #
#    Updated: 2022/02/20 20:19:27 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c	main_util.c	parse.c	splitter.c	splitter2.c	tool.c	tool2.c	check_dicterr.c	divide1.c	divide2.c	divide3.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJECTS)
	$(CC)	$(CFLAGS)	-o	$(NAME)	$(OBJECTS)
clean:
	rm	-f	$(OBJECTS)

fclean: clean
	rm	-f	$(NAME)
	
re: fclean all
