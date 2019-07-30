PROGRAM_NAME=01-arquivos

CC=gcc
CFLAGS=-Wall -Wextra -Werror -g

$(PROGRAM_NAME): main.o utils.o file.o menu.o input.o user.o
	$(CC) -o $(PROGRAM_NAME) main.o utils.o file.o menu.o input.o user.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

input.o: input.c input.h
	$(CC) $(CFLAGS) -c input.c

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

file.o: file.c file.h
	$(CC) $(CFLAGS) -c file.c

user.o: user.c user.h
	$(CC) $(CFLAGS) -c user.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -rf $(PROGRAM_NAME) *.o
