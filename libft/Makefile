# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: shenders <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 09:50:25 by shenders      #+#    #+#                  #
#    Updated: 2022/11/11 18:10:08 by shenders      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c \
      ft_isprint.c \
      ft_isdigit.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_strlen.c \
      ft_memset.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_putstr_fd.c \
      ft_strtrim.c \
      ft_putchar_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_itoa.c \
      ft_split.c \
      get_next_line.c \
      get_next_line_utils.c

SRCB = ft_lstnew_bonus.c \
       ft_lstadd_front_bonus.c \
       ft_lstsize_bonus.c \
       ft_lstlast_bonus.c \
       ft_lstadd_back_bonus.c \
       ft_lstdelone_bonus.c \
       ft_lstclear_bonus.c \
       ft_lstiter_bonus.c \
       ft_lstmap_bonus.c

OBJS = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

ifdef W_BONUS
	SRC += $(SRCB)
endif

all: files $(NAME)

#bonus:	
	#$(MAKE) W_BONUS=1
bonus: $(OBJS) $(OBJB)
	ar -rc $(NAME) $(OBJB)	
files:
	$(CC) $(CFLAGS) -c $(SRC)


$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJB)


fclean: clean
	rm -f $(NAME)


re: fclean $(NAME)


.PHONY: all clean fclean re bonus


