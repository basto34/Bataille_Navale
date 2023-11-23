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
	cout << "x?";
	cin >> x;
	cout << "y?";
	cin >> y;
	boat.setX(x);
	boat.setY(y);
	cout << "horizontal (True) ou vertical (False)?"; 
	cin >> c; 
	boat.setHorizontal(c);
	if (c) {
		while (x+ boat.getNbCases()>largeur) {
			cout << "nouveau x?";
			cin >> x; 
			boat.setX(x); 
		}
		for (int i = x; i = x + boat.getNbCases(); i++){
			grille[i][y] = 2; 
		}
	}
	else 
		while (y + boat.getNbCases() > longueur) {
			cout << "nouveau y?";
			cin >> y;
			boat.setY(y);
		}
	for (int i = y; i = y + boat.getNbCases(); i++) {
		grille[x][i] = 2;
	}
}

vector<vector<int>> Board::getGrille()
{
	return grille;
}
void Board::afficherGrille()
{
	for (int i = 0; i < longueur; i++) {
		for (int j = 0; j < largeur; j++) {
			cout << grille[i][j];
		}
		cout << endl;
	}