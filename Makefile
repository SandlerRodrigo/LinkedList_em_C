CFLAGS = -Wall -g
CC = gcc
LD = gcc
SRCS = $(wildcard LinkedList/*.c)
OBJS = $(SRCS:.c=.o)
CLEAN_FILES = main $(OBJS)

all: main

main: $(OBJS)
	$(LD) $(OBJS) -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLEAN_FILES)