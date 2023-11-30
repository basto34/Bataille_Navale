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

bool Bateau::getHorizontal()
{
	return horizontal;
}

void Bateau::setX(int c)
{
	x = c;
}

void Bateau::setY(int c)
{
	y = c;
}

void Bateau::setNbCases(int nb)
{
	this->nbCases = nb;
}

bool Bateau::isMort()
{
	if (touche == nbCases) {
		return true;
	}
	return false;
}

