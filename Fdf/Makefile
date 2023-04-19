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

NAME := fDF

CFLAGS := -g -Wall -Wextra -Werror

LIBFT := libft/libft.a
LIBMLX := MLX42

HEADERS := -Ilibft -IMLX42/include/MLX42/.
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm 

SRCS := $(shell find ./MLX42/src -iname "*.c")
OBJS := ${SRCS:.c=.o}
all:  libft libmlx $(NAME)

libft:
	$(MAKE) -C libft

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBS) $(LIBFT) $(HEADERS) -o $(NAME)

.PHONY: libmlx libft fclean clean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	rm -rf $(LIBMLX)/build

re: fclean all
