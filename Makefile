# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapryl <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/26 15:33:31 by mapryl            #+#    #+#              #
#    Updated: 2019/07/26 18:45:31 by mflannel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re make all

NAME = fillit

SRC_PATH = ./
HEAD_PATH = ./
LIB_PATH = ./libft/

SRC_FILES = create_list.c field.c find_solution.c tetromino.c validation.c \
			w_h_counter.c

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))

HEAD_FILES = field.h find_solution.h tetr_list.h tetromino.h validation.h
HEADERS = $(addprefix $(HEAD_PATH), $(HEAD_FILES))

LIB_NAME = ./libft/libft.a

OBJS = $(SRC_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(LIB_NAME) $(OBJS)
	$(CC) $(FLAGS) -o$(NAME) $(OBJS) -L $(LIB_PATH) -lft

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(LIB_NAME):
	@make -C $(LIB_PATH) re

clean:
	/bin/rm -rf $(OBJS)
	@make -C $(LIB_PATH) clean

fclean: clean
	/bin/rm -rf $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
