CC = g++
FLAGS = -g -Wall -std=c++11
OPT = -O3 -Wall -std=c++11 -Wall

all: fctrl	

fctrl: fctrl.o
	$(CC) -o fctrl fctrl.o

fctrl.o: fctrl.cpp
	$(CC) $(FLAGS) -c fctrl.cpp

optimized:
	$(CC) $(OPT) -o fctrl fctrl.cpp

clean:
	rm -f fctrl fctrl.o

