tetris5:tetris5.cpp Mino.cpp genMino.o MinoT.cpp MinoO.cpp 
	g++ -o tetris5 tetris5.cpp Mino.cpp genMino.o MinoT.cpp MinoO.cpp 

genMino.o:genMino.cpp genMino.h 
	g++ -c genMino.cpp
