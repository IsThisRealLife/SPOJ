CC = g++
FLAGS = -g -Wall -std=c++11
OPT = -O3 -Wall -std=c++11 -Wall

all: hashit	

hashit: hashit.o
	$(CC) -o hashit hashit.o

hashit.o: hashit.cpp
	$(CC) $(FLAGS) -c hashit.cpp

optimized:
	$(CC) $(OPT) -o hashit hashit.cpp

clean:
	rm -f hashit hashit.o

