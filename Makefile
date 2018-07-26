NAME = wolf3D

FLAGS = -Wall -Werror -Wextra -lSDL2 -I includes/ -I includes/SDL2/ -L ~/lib

LIB = includes/libft/libft.a

FILES = main.c read.c includes/get_next_line/get_next_line.c

$(NAME):
	$(MAKE) -C ./includes/libft
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
	@gcc -o $(NAME) $(FILES) $(FLAGS) $(LIB)

all: $(NAME)

fclean:
	rm -rf $(NAME)
	rm -rf includes/SDL2
	rm -rf SDL2-2.0.8
	rm -rf SDL2-2.0.8.tar.gz
	$(MAKE) -C ./includes/libft fclean

re: fclean all

co:
	$(CC) $(FILES) $(FLAGS)
	./$(NAME)

