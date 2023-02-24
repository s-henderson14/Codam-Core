# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: shenders <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/24 10:55:55 by shenders      #+#    #+#                  #
#    Updated: 2023/02/24 14:57:55 by shenders      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_a.c push_b.c swap_a.c swap_b.c rotate_a.c rotate_b.c \
	  reverse_rotate_a.c reverse_rotate_b.c stack_init.c ft_atoi.c \
      ft_printf.c print_node.c stack_init.c stack_size.c

OBJECTS = $(SRC:.c=.o)

CC = c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

