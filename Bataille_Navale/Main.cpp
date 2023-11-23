#include "Board.h"
#include"Utilisateur.h"
#include"iostream"
#include"IA.h"
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

	Board board1(longueur, largeur, 4);
	Board board2(longueur, largeur, 4);

	if (nbjoueurs == 2) {
		string nom1, nom2;
		cout << endl << "pseudo joueur 1 : ";
		cin >> nom1;
		Utilisateur joueur1(nom1);






	}

	else if (nbjoueurs == 1) {
		vector<int> attaqueIA;
		IA joueur2;
		//jeu IA
		while (!board1.estVide() && !board2.estVide()) {

			attaqueIA = joueur2.jouerAleatoire(longueur, largeur);
			//tant que la position d'attaque choisie par l'IA est interdite
			//on demande une autre position
			while (board1.getGrille()[attaqueIA[0]][attaqueIA[2]] > 0) {
				attaqueIA = joueur2.jouerAleatoire(longueur, largeur);
			}
		}

}