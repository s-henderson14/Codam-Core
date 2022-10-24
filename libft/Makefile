# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: shenders <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 09:50:25 by shenders      #+#    #+#                  #
#    Updated: 2022/10/24 14:31:08 by shenders      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isprint.c ft_isdigit.c ft_isalpha.c \
	  ft_isascii.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	  ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	  ft_putstr_fd.c ft_strtrim.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \



OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.


all: files $(NAME)

files:
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME):
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)


re: fclean $(NAME)


.PHONY: all clean fclean re bonus

