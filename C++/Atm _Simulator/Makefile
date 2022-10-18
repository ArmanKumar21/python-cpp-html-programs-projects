all: atm

atm: atm.o
	g++ -Wall -o atm atm.o

atm.o:
	g++ -Wall -c atm.cpp

clean:
	rm -f atm *.o
