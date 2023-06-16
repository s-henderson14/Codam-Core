# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: shenders <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/16 16:43:42 by shenders      #+#    #+#                  #
#    Updated: 2023/06/16 16:56:41 by shenders      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
CFLAGS	:= -g -Wall -Wextra -Werror
LIBFT	:= libft/libft.a
LIBMLX	:= MLX42
HEADERS := -Ilibft -IMLX42/include/MLX42/.
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit  
SRCS 	:= $(shell find ./MLX42/src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

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
