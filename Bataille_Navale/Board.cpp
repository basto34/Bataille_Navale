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

Board::Board(int lar, int lon, int bat){
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

void Board::toucherPos(int x, int y) {
	grille[x][y] = 0 - grille[x][y];
}

void Board::poseBoat(Bateau boat) {
	bool c;
	int x;
	int y;
	
	c = boat.getHorizontal();
	x = boat.getX();
	y = boat.getY();

	if (c) {
		for (int i = x; i < x + boat.getNbCases(); i++){
			grille[y][i] = 2; 
		}
	}
	else {
		for (int i = y; i < y + boat.getNbCases(); i++) {
			grille[i][x] = 2;
		}
	}
	
}

vector<vector<int>> Board::getGrille()
{
	return grille;
}
bool Board::estBienPlace(Bateau boat)
{
	bool horizontal = boat.getHorizontal();
	if (horizontal) {
		int x = boat.getX();
		if (x + boat.getNbCases() > 10) {
			return false;
		}
		return true;
	}
	else {
		int y = boat.getY();
		if (y + boat.getNbCases() > 10) {
			return false;
		}
		return true;
	}
}
void Board::afficherGrille() {
	for (int i = 0; i < longueur; i++) {
		for (int j = 0; j < largeur; j++) {
			int val = grille[i][j];
			switch (val)
			{
			case 2:
				cout << "X";
				break;
			case -2:
				cout << "O";
				break;
			case 1:
				cout << ".";
				break;
			case -1:
				cout << "*";
				break;
			}
		}
		cout << endl;
	}
}