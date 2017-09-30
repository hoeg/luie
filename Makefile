CC=gcc
CFLAGS=-Wall -Ilua -I.
LDPATH=-Llua -llua -lm -ldl

OUTPUT=main

all:
	$(CC) -o $(OUTPUT) main.c $(CFLAGS) $(LDPATH)

clean:
	$(RM) $(OUTPUT)

.PHONY:all clean
