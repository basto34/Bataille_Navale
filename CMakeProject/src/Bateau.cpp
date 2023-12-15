#include "Bateau.h"

/**
	*\brief Definit si le bateau est horizontal
	*
	*
	*
**/
void Bateau::setHorizontal(bool c) {
	horizontal = c;
}

/**
	*\brief Retourne le nombre de cases (la taille) du bateau
	*
	*
	*
**/
int Bateau::getNbCases() {
	return nbCases;
}

/**
	*\brief Retourne l'indice de la colonne du bateau
	*
	*
	*
**/
int Bateau::getX()
{
	return x;
}

/**
	*\brief Retourne l'indice de la ligne du bateau
	*
	*
	*
**/
int Bateau::getY()
{
	return y;
}

/**
	*\brief Retourne si le bateau est horizontal ou non
	*
	*
	*
**/
bool Bateau::getHorizontal()
{
	return horizontal;
}

/**
	*\brief Definit la coordonee x du bateau
	*
	*
	*
**/
void Bateau::setX(int c)
{
	x = c;
}

/**
	*\brief Definit la coordonee y du bateau
	*
	*
	*
**/
void Bateau::setY(int c)
{
	y = c;
}

/**
	*\brief Definit la taille du bateau
	*
	*
	*
**/
void Bateau::setNbCases(int nb)
{
	this->nbCases = nb;
}

/**
	*\brief Retourne si le bateau est mort ou non
	*
	*
	*
**/
bool Bateau::isMort()
{
	if (touche == nbCases) {
		return true;
	}
	return false;
}

