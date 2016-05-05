CC = g++
FLAGS = -g -Wall -std=c++11
OPT = -O3 -Wall -std=c++11 -Wall

all: primegenerator	

primegenerator: primegenerator.o
	$(CC) -o primegenerator primegenerator.o

primegenerator.o: primegenerator.cpp
	$(CC) $(FLAGS) -c primegenerator.cpp

optimized:
	$(CC) $(OPT) -o primegenerator primegenerator.cpp

clean:
	rm -f primegenerator primegenerator.o

