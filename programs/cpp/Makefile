all: compile link clean

compile: main.cpp test.cpp
	g++ -c main.cpp test.cpp

link: main.o test.o
	g++ main.o test.o -o hello

clean:
	rm *.o
	
