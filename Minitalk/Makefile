# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sean <sean@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 10:55:55 by shenders          #+#    #+#              #
#    Updated: 2023/06/17 19:24:10 by sean             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

SERVER_DIR = ./src/server
CLIENT_DIR = ./src/client

LIBFT = libft/libft.a
INC = -I libft -I include 

CFLAGS = -g -Wall -Wextra -Werror

SERVER_SRCS = $(shell find $(SERVER_DIR) -name "*.c")
CLIENT_SRCS = $(shell find $(CLIENT_DIR) -name "*.c")

HEADER_DIR = include
HEADERS = minitalk.h
HEADERS := $(addprefix $(HEADER_DIR)/, $(HEADERS))

OBJ_DIR = obj
SERVER_OBJS = $(patsubst $(SERVER_DIR)/%.c, $(OBJ_DIR)/server/%.o, $(SERVER_SRCS))
CLIENT_OBJS = $(patsubst $(CLIENT_DIR)/%.c, $(OBJ_DIR)/client/%.o, $(CLIENT_SRCS))

CC = cc

.PHONY: all clean fclean re

all: make_libft $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) -o $(SERVER) $(SERVER_OBJS) $(LIBFT)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) -o $(CLIENT) $(CLIENT_OBJS) $(LIBFT)

$(OBJ_DIR)/server/%.o: $(SERVER_DIR)/%.c $(HEADERS) | $(OBJ_DIR)/server
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/client/%.o: $(CLIENT_DIR)/%.c $(HEADERS) | $(OBJ_DIR)/client
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/server:
	mkdir -p $(OBJ_DIR)/server

$(OBJ_DIR)/client:
	mkdir -p $(OBJ_DIR)/client

make_libft:
	$(MAKE) -C libft

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
