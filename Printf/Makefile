# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shenders <shenders@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 09:55:33 by shenders          #+#    #+#              #
#    Updated: 2022/11/25 11:31:04 by shenders         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = ft_printf.c print_char.c print_string.c print_nbr.c \
print_pointer.c print_hex_lower.c print_hex_upper.c \
print_unsigned_i.c

OBJECTS = $(SOURCE:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $?

%o: %c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re