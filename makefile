ifdef web
CC = emcc
CFLAGS = -Os -Iinclude -I./raylib -Wall
LFLAGS = -s USE_GLFW=3 -s USE_LIBPNG=1 -s FULL_ES3=1 -s ALLOW_MEMORY_GROWTH=1
LIBS = -L./raylib -lraylib
OUTPUT = bin/snake.html
else
CC = cc
CFLAGS = -Iinclude -I./raylib -Wall -Wextra -Werror -pedantic -Wconversion -g
LFLAGS = 
LIBS = -L/opt/homebrew/opt/raylib/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL
OUTPUT = bin/snake
endif

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
DEPS = $(OBJ:.o=.d)

$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^ $(LIBS)

-include $(DEPS)

obj/%.o: src/%.c
	@mkdir -p obj dep bin
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -f bin/* $(OBJ) $(DEPS)
	rm -rf snake.dSYM bin obj dep

.PHONY: clean
