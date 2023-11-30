#pragma once
#include<vector>
#include"Bateau.h"
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
	void toucherPos(int x, int y);
	void poseBoat(Bateau boat);
	vector<vector<int>> getGrille();
	void afficherGrille();
	bool estBienPlace(Bateau boat);
};

