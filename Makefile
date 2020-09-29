CC=gcc
CFLAGS= -ggdb --pedantic --std=c89 -Wall -Wextra -Wconversion

all:
	$(CC) $(CFLAGS) $(ARGS)
