CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c17 -g
SRC = main.c func.c
OBJ = $(SRC:.c=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c func.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(EXEC)