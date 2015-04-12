lab3main:lab3main.o cow.o
	g++ -o lab3main lab3main.o cow.o

lab3main.o:lab3main.cpp cow.h
	g++ -c lab3main.cpp

cow.o:cow.cpp cow.h
	g++ -c cow.cpp

clean:
	rm lab3main *.o

