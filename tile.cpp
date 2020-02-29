/*
*	tile.cpp
*	A source file that contains the Tile class's member functions
*
****************************************/

#include "proj7.h"

Tile::Tile() {
	status = ' ';
	isVisited = false;
	isPushed = false;
}

Tile::~Tile() {
	printf("Tile destrucor has been called\n");
}

bool Tile::getIsPlayerHere() {
	return isPlayerHere;
}

int Tile::getAmount() {
	return -1;
}

char* Tile::getName() {
	return "default.txt";
}


char Tile::getStatus() {
	return status;
}

bool Tile::getIsVisited() {
	return isVisited;
}

bool Tile::getIsPushed() {
	return isPushed;
}

void Tile::setIsPlayerHere(bool p) {
	isPlayerHere = p;
}

void Tile::setStatus(char c) {
	status = c;
} 

void Tile::setIsVisited(bool p) {
	isVisited = p;
}

void Tile::setIsPushed(bool p) {
	isPushed = p;
}
