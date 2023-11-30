#include "Board.h"
#include"Utilisateur.h"
#include"iostream"
#include"IA.h"
#include <string> 
using namespace std;


void main() {
	int nbjoueurs;
	int longueur = 10, largeur = 10;
	int nbbateaux = 4;

	cout << "nombre de joueurs : ";
	cin >> nbjoueurs;

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
		cout << "Le placement des bateaux verticaux s'effectue de haut en bas, celui des horizontaux de gauche a droite" << endl;

		//Initialisation de la grille pour les 2 joueurs
		for (int n = 0; n <= 1; n++) {
			for (int i = 0; i <= nbbateaux; i++) {
				int taillebateau = 4;
				bool isHorizontal;
				char lettre;
				int y;

				Bateau boat;
				while (true) {
					cout << "Placement bateau " + to_string(i + 1) + " pour le joueur ";
						if (n == 1) {
							cout << nom1 << endl;
					}
						else {
							cout << nom2 << endl;
						}
					cout << "Bateau horizontal ou vertical ? 1 : horizontal, 0 : vertical" << endl;
					cin >> isHorizontal;
					cout << "Entrez le point d'origine du premier bateau (x,y) sachant que x est une lettre (A a J) et y un nombre (1 a 10) : " << endl;
					cin >> lettre >> y;
					int x;
					y = y - 1;
					if (int(lettre) >= 98) {
						x = int(lettre) - 97;
					}
					else {
						x = int(lettre) - 65;
					}
					boat.setX(x);
					boat.setY(y);
					boat.setHorizontal(isHorizontal);
					boat.setNbCases(taillebateau);

					if (grille1.estBienPlace(boat)) {
						cout << "Le bateau est bien place" << endl;
						break;
					}
					else {
						cout << "Le bateau ne peut pas etre place ici. Recommencez" << endl;
					}
				}


				grille1.poseBoat(boat);
				grille1.afficherGrille();


			}

			//Jeu 
		}





	}

	else if (nbjoueurs == 1) {
		vector<int> attaqueIA;
		IA joueur2;
		//jeu IA
		while (!grille1.estVide() && !grille2.estVide()) {

			attaqueIA = joueur2.jouerAleatoire(longueur, largeur);
			//tant que la position d'attaque choisie par l'IA est interdite
			//on demande une autre position
			while (grille1.getGrille()[attaqueIA[0]][attaqueIA[2]] > 0) {
				attaqueIA = joueur2.jouerAleatoire(longueur, largeur);
			}
		}

	}
}