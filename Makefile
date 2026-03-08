CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/core/gulabo.c \
      src/core/parser.c \
      src/core/executor.c \
      src/core/redirection.c \
      src/core/pipe.c \
      src/core/launcher.c \
      src/core/sysinfo.c \
      src/core/runner.c \
      src/core/task.c \
      src/core/listener.c

all:
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o bin/gulabo

clean:
	rm -f bin/gulabo