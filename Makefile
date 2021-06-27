all: build

build: obj
	gcc -o hp12 *.o

obj: pilha.c
	gcc -Wall -g -c main.c pilha.c

clean:
	rm *.o hp12

run: all
	./hp12
