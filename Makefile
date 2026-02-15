# Variables
CC      := gcc
CFLAGS  := -Wall -Wextra -g
INC     := -Iinclude
SRC_DIR := src
OBJ_DIR := obj
TARGET  := my_program

# Automatically find all .c files in src/
SRCS := $(wildcard $(SRC_DIR)/*.c)
# Convert .c file paths to .o file paths in the obj/ directory
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default rule
all: $(OBJ_DIR) $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean up build files
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
