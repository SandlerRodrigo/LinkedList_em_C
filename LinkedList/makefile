all : main

main : main.o LinkedList.o
	gcc -o main main.o LinkedList.o

main.o : main.c LinkedList.h
	gcc -c main.c

LinkedList.o : LinkedList.c LinkedList.h
	gcc -c LinkedList.c

clean :
	rm main main.o LinkedList.o