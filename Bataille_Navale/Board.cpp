#include "Board.h"

bool Board::estVide() {
	bool res =true;
	for (int i = 0; i < longueur; i++) {
		for (int j = 0; j < largeur; j++) {
			if (grille[i][j] == 2) {
				res = false;
			}
		}
	}
	return res;

}

Board::Board(int lar, int lon, int bat)
{
	largeur = lar;
	longueur = lon;
		for (int i = 0; i < longueur; i++) {
			grille.push_back({});
			for (int j = 0; j < largeur; j++) {
				grille[i].push_back(1);
			}
		}
		nbBateaux = bat;

}
