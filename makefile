CC = cc
CFLAGS = -I/opt/homebrew/opt/raylib/include -Wall -g
LIBS = -L/opt/homebrew/opt/raylib/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL

snake: main.c window.c snake.c pellet.c
	$(CC) $(CFLAGS) -o snake main.c window.c snake.c pellet.c $(LIBS)

clean:
	rm -f snake
	rm -rf snake.dSYM
