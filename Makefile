# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llebaken <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 09:00:13 by llebaken          #+#    #+#              #
#    Updated: 2018/09/12 14:43:45 by llebaken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3D

FLAGS = -Wall -Werror -Wextra -lSDL2 -I includes/ -I includes/SDL2/ -L ~/lib

LIB = includes/libft/libft.a

SDL = SDL2-2.0.8

FILES = main.c validation.c read.c raycasting.c draw.c keypress.c includes/get_next_line/get_next_line.c

all: $(NAME)
$(SDL):
	curl -O https://libsdl.org/release/SDL2-2.0.8.tar.gz
	gunzip -c SDL2-2.0.8.tar.gz | tar xf -
	cd SDL2-2.0.8; \
	mkdir build; \
	cd build; \
	../configure; \
	make
	mkdir -p ~/lib/
	cp SDL2-2.0.8/build/build/.libs/libSDL2-2.0.0.dylib ~/lib/
	ln -F -s ~/lib/libSDL2-2.0.0.dylib ~/lib/libSDL2.dylib
	mkdir -p includes/SDL2
	cp SDL2-2.0.8/include/*.h includes/SDL2/

$(NAME): $(SDL)
	$(MAKE) -C ./includes/libft
	@gcc -o $(NAME) $(FILES) $(FLAGS) $(LIB)

fclean:
	rm -rf $(NAME)
	$(MAKE) -C ./includes/libft fclean

re: fclean all

co:
	$(CC) $(FILES) $(FLAGS)
	./$(NAME)

