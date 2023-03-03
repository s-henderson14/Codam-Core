# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shenders <shenders@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 10:55:55 by shenders          #+#    #+#              #
#    Updated: 2023/03/03 14:54:07 by shenders         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = add_back.c add_front.c ft_atoi.c is_sorted.c largest_number.c last_node.c \
	  list_size.c node_init.c print_node.c push_a.c push_b.c push_swap.c \
	  reverse_rotate_a.c reverse_rotate_b.c rotate_a.c rotate_b.c \
	  sorter.c swap_a.c swap_b.c


OBJECTS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	cc -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

