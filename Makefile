CC=gcc
LDFLAGS=-lncurses
CFLAGS=-Wall -Werror -Wextra

pong: pong.o game.o

.PHONY: clean
clean:
	rm -f *.o
	rm -f pong
