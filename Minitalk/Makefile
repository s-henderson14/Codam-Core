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

NAME = minitalk
SERVER = server
CLIENT = client

SERVER_DIR = ./src/server
CLIENT_DIR = ./src/client

LIBFT = libft/libft.a
INC = -Ilibft

CFLAGS = -g -Wall -Wextra -Werror

SERVER_SRCS = $(shell find ./src/server -iname "*.c")
CLIENT_SRCS = $(shell find ./src/client -iname "*.c")

HEADER_DIR = include
HEADERS = minitalk.h
HEADERS := $(addprefix $(HEADER_DIR)/, $(HEADERS))

OBJ_DIR = ./obj
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJ_DIR/, $(CLIENT_SRCS:.c=.0))

# OBJS = $(patsubst $(SERVER_DIR)%.c, $(CLIENT_DIR)%.c, $(OBJ_DIR)%.o, $(SERVER_SRCS), $(CLIENT_SRCS)

CC = cc

all: make_libft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(INC) -o $(NAME)$(OBJ_DIR)/%.o: $(SERVER_DIR)/%.c, $(CLIENT_DIR)/%.c
#$(HEADERS)
$(OBJ_DIR)/%.o: $(SERVER_DIR)/%.c, $(CLIENT_DIR)/%.c
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
