CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
OBJS = gridCreation.o difficulty.o play.o main.o

all: sudoku

sudoku: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c headers.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) sudoku
