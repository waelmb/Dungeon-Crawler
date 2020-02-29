/*
*	player.cpp
*	A source file that contains the Player class's member functions
*
****************************************/
#include "proj7.h"

Player::Player() {
	gold = 0;
	numTiles = 0;
	x = 0;
	y = 0;
}

int Player::getGold() {
	return gold;
}

int Player::getNumTiles() {
	return numTiles;
}

int Player::getX() {
	return x;
}

int Player::getY() {
	return y;
}

void Player::addGold(int a) {
	gold = gold + a;
}

void Player::addNumTiles(int t) {
	numTiles = numTiles + t;
}

void Player::setX(int px) {
	x = px;
}

void Player::setY(int py) {
	y = py;
}

void Player::move(int px, int py) {
	x = px;
	y = py;
}
