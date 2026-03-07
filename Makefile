CC = gcc
CFLAGS = -Wall -Wextra

SRC = src/core/gulabo.c \
      src/core/parser.c \
      src/core/executor.c \
      src/core/redirection.c

all:
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o bin/gulabo

clean:
	rm -rf bin/gulabo