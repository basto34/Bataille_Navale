#pragma once
#include<vector>
using namespace std;

class Board
{
private:
	vector<vector<int>> grille;
	int largeur;
	int longueur;
	int nbBateaux;
public:
	bool estVide();
	Board(int lar, int lon, int bat);
	void modifierGrille(int x, int y,int bat);

};

