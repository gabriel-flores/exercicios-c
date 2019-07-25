01-arquivos: main.o
	gcc -o 01-arquivos *.o

main.o: file.o user.o
	gcc -c main.c

file.o: file.h
	gcc -c file.c

user.o: user.h
	gcc -c user.c

clean:
	rm -rf 01-arquivos *.o
