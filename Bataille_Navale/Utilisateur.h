#pragma once
using namespace std;
#include "iostream"
#include <vector>
#include "Board.h"

class Utilisateur
{
private:
	string surnom;
public:
	vector<int> entrerCase();
	Utilisateur(string pseudo);
	void creerGrille(Board& grille);
};

