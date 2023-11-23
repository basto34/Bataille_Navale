#include "Board.h"
#include"Utilisateur.h"
#include"iostream"
using namespace std;


void main() {
	int nbjoueurs;
	int longueur, largeur;

	cout << "nombre de joueurs : ";
	cin >> nbjoueurs;

	cout << "longueur des grilles : ";
	cin >> longueur;
	cout << endl << "largeur des grilles : ";
	cin >> largeur;

	Board grille1(longueur, largeur, 4);
	Board grille2(longueur, largeur, 4);

	if (nbjoueurs == 2) {
		string nom1, nom2;
		cout << endl << "pseudo joueur 1 : ";
		cin >> nom1;
		Utilisateur joueur1(nom1);






	}





}