objects = game.o

game.o : game.c
					gcc game.c -o game_battle

all: game

.PHONY : clean
clean : -rm game.o
