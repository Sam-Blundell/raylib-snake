CC = cc
CFLAGS = -Iinclude -I/opt/homebrew/opt/raylib/include -Wall -Wextra -Werror -pedantic -Wconversion -g
LIBS = -L/opt/homebrew/opt/raylib/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)
DEPS = $(OBJ:obj/%.o=dep/%.d)

bin/snake: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

obj/%.o dep/%.d: src/%.c
	@mkdir -p obj dep bin
	$(CC) $(CFLAGS) -c $< -o obj/$*.o
	$(CC) $(CFLAGS) -MM $< -MT obj/$*.o -MF dep/$*.d

clean:
	rm -f bin/snake $(OBJ) $(DEPS)
	rm -rf snake.dSYM bin obj dep

.PHONY: clean

-include $(DEPS)
