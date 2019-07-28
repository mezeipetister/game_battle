#
# Demo GNU Make file
# Copyright 2019 Peter Mezei
#
SHELL := /bin/bash

STIME = 1
COLOR_NORMAL	= \e[38;5;74m
COLOR_DEFAULT	=	\e[39m

objects = game.o test_a.o

LINE = $(call print,-----------------------------)
print = echo -e "$(COLOR_NORMAL)$1$(COLOR_DEFAULT)"

install_linux = print,installing package: $1; sleep $(STIME); $(LINE); sudo apt install $1

.PHONY : all
all: game test_a
	@$(info Bruhuhuuu) \
	$(call install_linux,htop)\
	$(info htop installed)

game: game.o
test_a: test_a.o

%.o :

RESULT = $(shell ls; echo $$?)

.PHONY : check
check : all
	@$(LINE); \
	echo Hello bello;\
	echo Result is $(RESULT);\
	$(LINE)

.PHONY : clean
clean :
	rm game test_a $(objects)
