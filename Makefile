CC = gcc
CFLAGS = -Wall -g
SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRC_FILES))
TARGET = rp

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET) $(ARGS)

clean:
	rm -f $(TARGET) $(OBJ_FILES)
