CC=g++
CCFLAGS=-c -Wall -std=c++11 
CLASS=binary_search_tree

all: main

main: main.o $(CLASS).o
	$(CC) main.o $(CLASS).o -o main

main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp

$(CLASS).o: $(CLASS).cpp
	$(CC) $(CCFLAGS) $(CLASS).cpp $(CLASS).h

clean:
	rm -rf *o *.gch