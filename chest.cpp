/*
*	chest.cpp
*	A source file that contains the Chest class's member functions
*
****************************************/

#include "proj7.h"

Chest::Chest() {
	amount = 0;
}

Chest::Chest(int a) {
	amount = a;
}

int Chest::getAmount() {
	return amount;
}

void Chest::setAmount(int a) {
	amount = a;
}
