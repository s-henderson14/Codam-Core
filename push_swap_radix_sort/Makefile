# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shenders <shenders@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 10:55:55 by shenders          #+#    #+#              #
#    Updated: 2023/04/14 12:08:37 by shenders      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

CFLAGS = -g -Wall -Wextra -Werror

INC = -Ilibft -Iinclude

SRC_DIR = src
SRC = add_back.c\
	   add_front.c \
	   check_duplicate.c\
	   error_message.c \
	   free_stack.c \
	   atoi.c \
	   is_a_sorted.c \
	   largest_n.c \
	   last_node.c \
	   listsize.c \
	   merge.c \
	   node_init.c \
	   parser.c \
	   push_a.c \
	   push_b.c \
	   push_swap.c \
	   radix_sort.c \
	   rank_stack.c \
	   reverse_rotate_a.c \
	   reverse_rotate_b.c \
	   rotate_a.c rotate_b.c \
	   short_sort.c \
	   sort_three.c \
	   stack_init.c \
	   swap_a.c \
	   swap_b.c \
	   valid_integer.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRC))

HEADER_DIR = include
HEADERS = push_swap.h
HEADERS := $(addprefix $(HEADER_DIR)/, $(HEADERS))

OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC = cc

all: make_libft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#$(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

.PHONY: make_libft fclean clean re

make_libft:
	$(MAKE) -C libft

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean dfclean all

dfclean:
	$(MAKE) -C libft fclean
dre:
	$(MAKE) -C libft re
