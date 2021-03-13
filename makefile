CC=gcc

CFLAGS=-g -Wall -pedantic -D_GNU_SOURCE=1 -D_REENTRANT
#CFLAGS=-g -Wall -D_REENTRANT
MATH_FLAGS=-lm
SOURCES=main.c tela.c jogo.o config.c
OBJECTS=main.o tela.o jogo.c config.o
BINARIES=main

all: $(BINARIES)

main: main.o tela.o jogo.o config.o
	$(CC) -o main main.o tela.o jogo.o config.o

main.o: main.c interfaces/defs.h
	$(CC) -c main.c $(CFLAGS) $(MATH_FLAGS)

tela.o: funcoes/tela.c interfaces/funcoes.h
	$(CC) -c funcoes/tela.c $(CFLAGS)

jogo.o: funcoes/jogo.c interfaces/funcoes.h
	$(CC) -c funcoes/jogo.c $(CFLAGS)

config.o: funcoes/config.c interfaces/funcoes.h
	$(CC) -c funcoes/config.c $(CFLAGS)	

clean:
	rm -rf *.o *.exe *.bak *.c~ $(BINARIES) core a.out

limpa:
	del *.o *.exe *.bak *.c~ $(BINARIES) core

