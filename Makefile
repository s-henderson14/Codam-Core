# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: shenders <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/17 09:55:33 by shenders      #+#    #+#                  #
#    Updated: 2022/11/17 10:02:24 by shenders      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE =

OBJECTS = 

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
