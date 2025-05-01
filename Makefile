CC = gcc
CFLAGS = -O2
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
BUILD_DIR = build
EXECUTABLE = $(BUILD_DIR)/atobl
BINDIR = /usr/local/bin

.PHONY: all build run clean install uninstall

all: build
build: $(EXECUTABLE)

$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXECUTABLE): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(OBJ)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -rf build/*.o build/atobl .cache

install: 
	mkdir -p $(BINDIR)
	cp -f $(BUILD_DIR)/atobl $(BINDIR)/atobl

uninstall:
	rm -f $(BINDIR)/atobl
