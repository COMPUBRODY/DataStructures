
# Compiler
CC = gcc

# Compiler flag
CFLAGS = -fsanitize=address -Wall -Wextra -pedantic -std=gnu99 -g

#Source files
#SRCS = Sorting_strings.c includes/snips.c
#SRCS = Querying_document.c includes/snips.c
SRCS = Reversal_array.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
#HDRS = includes/snips.h

#Executable name

EXE = Reverse_array.out

# Default target
all: $(EXE)

# Rule to build the executable
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build the object files
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -f $(EXE) $(OBJS)
	