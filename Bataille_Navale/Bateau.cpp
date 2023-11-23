#include "Bateau.h"

void Bateau::setHorizontal(bool c) {
	horizontal = c;
}

int Bateau::getNbCases() {
	return nbCases;
}

int Bateau::getX()
{
	return x;
}

int Bateau::getY()
{
	return y;
}

void Bateau::setX(int c)
{
	x = c;
}

void Bateau::setY(int c)
{
	y = c;
}

