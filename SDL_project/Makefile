NAME = build
SRC = src/entity.cpp src/math.cpp src/main.cpp src/renderwindow.cpp
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main

re: fclean all

clean:
	rm -f $(OBJS)

fclean: cleam
	rm -f $(NAME)