COMPILER=gcc
STD=c99
FLAGS=-Wall -Wextra -pedantic

all: run

run: main.c
	$(COMPILER) -std=$(STD) $(FLAGS) -o $@ $<

clean:
	rm run
