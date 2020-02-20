dictionary: main.o
	g++ main.o -o dictionary
main.o: main.cpp dictionary.h
	g++ -c -std=c++11 main.cpp dictionary.h
clean:
	rm *.o dictionary
target: 
	dependencies
	action