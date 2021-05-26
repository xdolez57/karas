COMPILER=gcc
STD=c99
COMPILEFLAGS=-c -Wall -Wextra -pedantic
LINKFLAGS=-Wall -Wextra -pedantic

all: run

main.o: main.c main.h
	$(COMPILER) -std=$(STD) $(COMPILEFLAGS) -o $@ $<

ui.o: ui.c ui.h
	$(COMPILER) -std=$(STD) $(COMPILEFLAGS) -o $@ $<

run: main.o ui.o
	$(COMPILER) -std=$(STD) $(LINKFLAGS) -o $@ $^

clean:
	rm run
	rm *.o
