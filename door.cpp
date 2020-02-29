/*
*	door.cpp
*	A source file that contains the Door class's member functions
*
****************************************/

#include "proj7.h"

Door::Door() {
	
}

Door::Door(char* n) {
	int len = strlen(n);
	name = (char*) malloc(sizeof(char) * len);
	strcpy (name, n);
}

char* Door::getName() {
	return name;
}

void Door::setName(char* n) {
	name = n;
}
