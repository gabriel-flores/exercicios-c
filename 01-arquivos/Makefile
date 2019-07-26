CC=gcc
CFLAGS=-Wall -Wextra -Werror -g

01-arquivos: main.o
	${CC} ${CFLAGS} -o 01-arquivos *.o

main.o: menu.o input.o file.o user.o
	${CC} ${CFLAGS} -c main.c

input.o: input.h
	${CC} ${CFLAGS} -c input.c

menu.o: menu.h
	${CC} ${CFLAGS} -c menu.c

file.o: file.h
	${CC} ${CFLAGS} -c file.c

user.o: user.h
	${CC} ${CFLAGS} -c user.c

clean:
	rm -rf 01-arquivos *.o
