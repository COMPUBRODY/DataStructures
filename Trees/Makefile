
# Compiler
CC = gcc

# Compiler flag
CFLAGS = -Wall -Wextra -pedantic -std=c99

#Source files
SRC = dynamic_system_directory.c

#Executable name

EXE = filesystem

# Default target
all: $(EXE)

# Rule to build the executable
$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(EXE)
	