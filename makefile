# Name of the executable
TARGET = main

# Source files
SRCS = main.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g0

.PHONY: all clean

# Default target
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

# Clean up
clean:
	rm -f $(TARGET)

