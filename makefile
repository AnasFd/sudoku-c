CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
OBJS = gridCreation.o main.o

all: soduku

soduku: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

gridCreation.o: gridCreation.c gridCreation.h
	$(CC) $(CFLAGS) -c gridCreation.c -o $@

main.o: main.c gridCreation.h
	$(CC) $(CFLAGS) -c main.c -o $@

clean:
	rm -f $(OBJS)