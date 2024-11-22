CC=gcc
LIB_DIR=lib
BUILD_DIR=build
SRC_DIR=src
.PHONY: all always clean

all: main

main: always
	$(CC) -g $(SRC_DIR)/main.c -o $(BUILD_DIR)/main -lglut -lGL -lGLU -lXi -lXmu
	chmod +x $(BUILD_DIR)/main
always:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
