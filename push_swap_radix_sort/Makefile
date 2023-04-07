# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shenders <shenders@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 10:55:55 by shenders          #+#    #+#              #
#    Updated: 2023/03/17 14:10:37 by shenders      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = add_back.c add_front.c check_duplicate.c error_message.c free_stack.c \
      ft_atoi.c is_a_sorted.c is_digit.c largest_n.c last_node.c list_size.c \
      merge.c node_init.c push_a.c push_b.c push_swap.c radix_sort.c \
      rank_stack.c reverse_rotate_a.c reverse_rotate_b.c rotate_a.c rotate_b.c \
      short_sort.c sort_three.c swap_a.c swap_b.c valid_integer.c

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

