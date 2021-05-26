COMPILER=gcc
STD=c99
COMPILEFLAGS=-c -Wall -Wextra -pedantic
LINKFLAGS=-Wall -Wextra -pedantic

all: run

array.o: array.c array.h display.h array.h arraydef.h
	$(COMPILER) -std=$(STD) $(COMPILEFLAGS) -o $@ $<

display.o: display.c display.h array.h arraydef.h
	$(COMPILER) -std=$(STD) $(COMPILEFLAGS) -o $@ $<

main.o: main.c main.h array.h arraydef.h display.h ui.h
	$(COMPILER) -std=$(STD) $(COMPILEFLAGS) -o $@ $<

ui.o: ui.c ui.h
	$(COMPILER) -std=$(STD) $(COMPILEFLAGS) -o $@ $<

run: array.o display.o main.o ui.o
	$(COMPILER) -std=$(STD) $(LINKFLAGS) -o $@ $^

clean:
	rm run
	rm *.o
