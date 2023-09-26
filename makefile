ifdef web
CC = emcc
CFLAGS = -Os -Iinclude -I/Users/samblundell/raylib/src -Wall -s USE_GLFW=3
LIBS = -L/Users/samblundell/raylib/src -lraylib
OUTPUT = bin/snake.html
else
CC = cc
CFLAGS = -Iinclude -I/opt/homebrew/opt/raylib/include -Wall -Wextra -Werror -pedantic -Wconversion -g
LIBS = -L/opt/homebrew/opt/raylib/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL
OUTPUT = bin/snake
endif
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
DEPS = $(OBJ:obj/%.o=dep/%.d)

$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

obj/%.o dep/%.d: src/%.c
	@mkdir -p obj dep bin
	$(CC) $(CFLAGS) -c $< -o obj/$*.o
	$(CC) $(CFLAGS) -MM $< -MT obj/$*.o -MF dep/$*.d

clean:
	rm -f bin/* $(OBJ) $(DEPS)
	rm -rf snake.dSYM bin obj dep

.PHONY: clean

-include $(wildcard dep/*.d)
