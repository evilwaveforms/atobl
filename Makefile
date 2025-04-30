CC = gcc
CFLAGS = -Wall -Wextra -g3
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
BUILD_DIR = $(dir $(word 1, $(OBJ)))

.PHONY: all dev run clean

all: dev

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

dev: $(OBJ)
	$(CC) -o $(BUILD_DIR)atobl $(OBJ) -lm

run: $(BUILD_DIR)atobl
	./$(BUILD_DIR)atobl

clean:
	rm -rf build/*.o build/atobl .cache
