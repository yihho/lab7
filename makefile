main:main.o lab5.o
	g++ -o main main.o lab5.o

main.o:main.cpp lab5.h
	g++ -c main.cpp

lab5.o:lab5.cpp lab5.h
	g++ -c lab5.cpp

