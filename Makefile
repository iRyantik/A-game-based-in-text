hello.o: hello.cpp hello.h
	g++ -c hello.cpp
main.o: main.cpp hello.h
	g++ -c main.cpp
main: hello.o main.o
	g++ hello.o main.o -o main
