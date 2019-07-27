SHELL := /bin/bash

objects = game.o test_a.o

all: game test_a
.PHONY : all

game: game

game.o :
test_a.o :

.PHONY : check
check : all
	./test_a

.PHONY : clean
clean :
	rm game test_a $(objects)
