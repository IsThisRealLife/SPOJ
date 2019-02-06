CC = g++
FLAGS = -g -Wall -std=c++11
OPT = -O3 -Wall -std=c++11 -Wall

all: simpleSieve	

simpleSieve: simpleSieve.o
	$(CC) -o simpleSieve simpleSieve.o

simpleSieve.o: simpleSieve.cpp
	$(CC) $(FLAGS) -c simpleSieve.cpp

optimized:
	$(CC) $(OPT) -o simpleSieve simpleSieve.cpp

clean:
	rm -f simpleSieve simpleSieve.o

