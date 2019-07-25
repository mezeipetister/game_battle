objects = game.o

game.o : game.c
					gcc game.c -o game_battle

all: game

.PHONY : clean
clean : -rm game.o

test_a : test_a.c
					gcc test_a.c -o test_a

check: test_a
