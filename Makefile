# Makefile for MyShell Project
# --------------------------------
# Directories
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Compiler and Flags
CC = gcc
CFLAGS = -I$(INC_DIR) -Wall

# Source and Object Files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/shell.c $(SRC_DIR)/execute.c
OBJS = $(SRCS:.c=.o)
TARGET = $(BIN_DIR)/myshell

# Default Target
all: $(TARGET)

# Build Target
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "✅ Build complete: $(TARGET)"

# Compile each .c file into .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Target
clean:
	rm -rf $(SRC_DIR)/*.o $(BIN_DIR)
	@echo "🧹 Cleaned build files."

# Run Target
run: all
	@echo "🚀 Running MyShell..."
	./$(TARGET)

# Phony Targets
.PHONY: all clean run
