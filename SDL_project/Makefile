NAME = build
SRC = src/entity.cpp src/math.cpp src/main.cpp src/renderwindow.cpp

all: $(NAME)

$(NAME):
	g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main

re: clean all

clean:
	rm -f *.o

.PHONY:
	clean