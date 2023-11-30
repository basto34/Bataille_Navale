#include "Board.h"
#include"Utilisateur.h"
#include"iostream"
using namespace std;


void main() {
	int nbjoueurs;
	int longueur, largeur;
	int nbbateaux = 4;

	cout << "nombre de joueurs : ";
	cin >> nbjoueurs;

	cout << "longueur des grilles : ";
	cin >> longueur;
	cout << endl << "largeur des grilles : ";
	cin >> largeur;

	Board grille1(longueur, largeur, nbbateaux);
	Board grille2(longueur, largeur, nbbateaux);

	if (nbjoueurs == 2) {
		string nom1, nom2;
		cout << endl << "pseudo joueur 1 : ";
		cin >> nom1;
		Utilisateur joueur1(nom1);
		cout << endl << "pseudo joueur 2 : ";
		cin >> nom2;
		Utilisateur joueur2(nom2);
		for (int i = 0; i <= nbbateaux; i++) {
			bool isHorizontal;
			cout << "Bateau horizontal ou vertical ? 1 : horizontal, 0 : vertical" << endl;
			cin >> isHorizontal;
			Bateau boat()
			grille1.poseBoat()
		}





	}

	else if (nbjoueurs == 1) {

	}

}