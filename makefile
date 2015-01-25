llist:  iofunctions.o llist.o
	 g++ -o llist -D debug iofunctions.o llist.o

iofunctions.o: iofunctions.cpp debugMode.h record.h llist.h
	g++ -c -ansi -Wall iofunctions.cpp

llist.cpp.o: llist.cpp debugMode.h record.h llist.h
	g++ -c -ansi -Wall llist.cpp
