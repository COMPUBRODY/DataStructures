
# Compiler
CC = gcc

# Compiler flag
CFLAGS = -Wall -Wextra -pedantic -std=c99

#Source files
SRC = Sorting_strings.c

#Executable name

EXE = strings_sorted

# Default target
all: $(EXE)

# Rule to build the executable
$(EXE): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(EXE)
	