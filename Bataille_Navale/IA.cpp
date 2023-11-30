#include "IA.h"

vector<int> IA::jouerAleatoire(int longueur, int largeur)
{
	vector<int> pos;
	pos.push_back(rand() % longueur);
	pos.push_back(rand() % largeur);
	return pos;
}