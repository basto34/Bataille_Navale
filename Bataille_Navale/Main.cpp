#include "Board.h"
#include"Utilisateur.h"
#include"iostream"
#include"IA.h"
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

<<<<<<< HEAD
	Board grille1(longueur, largeur, nbbateaux);
	Board grille2(longueur, largeur, nbbateaux);
=======
	Board board1(longueur, largeur, 4);
	Board board2(longueur, largeur, 4);
>>>>>>> 48d4f439fba77efbb108b0696e333ff162798b6b

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