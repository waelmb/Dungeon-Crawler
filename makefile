proj7: wmobei2Proj7.o tile.o chest.o door.o wall.o room.o player.o
	g++ -g -o proj7 wmobei2Proj7.o tile.o chest.o door.o wall.o room.o player.o

wmobei2Proj7.o: wmobei2Proj7.cpp proj7.h
	g++ -g -c wmobei2Proj7.cpp

tile.o: tile.cpp proj7.h
	g++ -g -c tile.cpp

chest.o: chest.cpp proj7.h
	g++ -g -c chest.cpp

door.o: door.cpp proj7.h
	g++ -g -c door.cpp

wall.o: wall.cpp proj7.h
	g++ -g -c wall.cpp

room.o: room.cpp proj7.h
	g++ -g -c room.cpp

player.o: player.cpp proj7.h
	g++ -g -c player.cpp
