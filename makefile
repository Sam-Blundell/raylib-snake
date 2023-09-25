CC = cc
CFLAGS = -I/opt/homebrew/opt/raylib/include -Wall -g
LIBS = -L/opt/homebrew/opt/raylib/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL

SRC = main.c \
	  window.c \
	  snake.c \
	  pellet.c \
	  collisions.c \
	  input.c \
	  draw.c \
	  update.c

snake: $(SRC)
	$(CC) $(CFLAGS) -o snake $(SRC) $(LIBS)

clean:
	rm -f snake
	rm -rf snake.dSYM
