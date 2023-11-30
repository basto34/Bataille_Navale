#include "Board.h"
#include"Utilisateur.h"
#include"iostream"
#include"IA.h"
#include <string> 
using namespace std;


void main() {
	int nbjoueurs;
	int longueur = 10, largeur = 10;
	int nbbateaux = 2;

	cout << "Nombre de joueurs : ";
	cin >> nbjoueurs;

	Board grille1(longueur, largeur, nbbateaux);
	Board grille2(longueur, largeur, nbbateaux);

	if (nbjoueurs == 2) {
		string nom1, nom2;
		cout << endl << "Pseudo joueur 1 : ";
		cin >> nom1;
		Utilisateur joueur1(nom1);
		cout << endl << "Pseudo joueur 2 : ";
		cin >> nom2;
		Utilisateur joueur2(nom2);
		

		//Initialisation de la grille pour les 2 joueurs
		for (int n = 0; n <= 1; n++) {
			cout << "Le placement des bateaux verticaux s'effectue de haut en bas, celui des horizontaux de gauche a droite" << endl;

			for (int i = 0; i < nbbateaux; i++) {
				int taillebateau;
				//On donne des bateaux de tailles différentes
				switch (i)
				{
				case 0:
					taillebateau = 5;
					break;
				case 1:
					taillebateau = 4;
					break;
				case 2:
					taillebateau = 3;
					break;
				case 3:
					taillebateau = 3;
					break;
				case 4:
					taillebateau = 2;
					break;
				}
				
				bool isHorizontal;
				char lettre;
				int y;
				bool test = false;
				Bateau boat;
				do {

					//Ecriture du placement du bateau x (de taille x) pour le joueur x
					cout << "Placement bateau " + to_string(i + 1) + " " + + "(de taille " + to_string(taillebateau) + ")" + " pour le joueur ";
						if (n == 0) {
							cout << nom1 << endl;
					}
						else {
							cout << nom2 << endl;
						}

					//On demande si le bateau est horizontal ou vertical avec les lettres h et v et on ajuste isHorizontal en fonction
					cout << "Bateau horizontal ou vertical ? h : horizontal, v : vertical" << endl;
					string orientation;
					cin >> orientation;
					if (orientation == "h") {
						isHorizontal = true;
					}
					else {
						isHorizontal = false;
					}

					//On demande la position du bateau
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

					//On initialise le bateau
					boat.setX(x);
					boat.setY(y);
					boat.setHorizontal(isHorizontal);
					boat.setNbCases(taillebateau);
					
					//On vérifie si le bateau est bien placé : si oui, on passe au suivant. sinon, on recommence la boucle 
					if (n == 0) {
						if (grille1.estBienPlace(boat)) {
							cout << "Le bateau est bien place" << endl;
							test = true;
						}
						else {
							cout << "Le bateau ne peut pas etre place ici. Recommencez" << endl;
						}
						grille1.poseBoat(boat);
						grille1.afficherGrille();
					}
					else {
						if (grille2.estBienPlace(boat)) {
							cout << "Le bateau est bien place" << endl;
							test = true;
						}
						else {
							cout << "Le bateau ne peut pas etre place ici. Recommencez" << endl;
						}
						grille2.poseBoat(boat);
						grille2.afficherGrille();
					}

					
				} while (!test);
					


			}
		}
			//Jeu : on joue tant que les deux grille contiennent des bateaux 
			while (!grille1.estVide() || !grille2.estVide()) {
				//Tour du joueur 1 
				char lettre1;
				int y1;
				cout << nom1 + " donnez votre coup (x,y) avec sachant que x est une lettre (A a J) et y un nombre (1 a 10) : " << endl;
				cin >> lettre1;
				cin >> y1;

				//On transforme la lettre en entier
				int x1;
				y1 = y1 - 1;
				if (int(lettre1) >= 98) {
					x1 = int(lettre1) - 97;
				}
				else {
					x1 = int(lettre1) - 65;
				}

				//On frappe la grille adverse
				int touche1 = grille2.toucherPos(x1, y1);
				switch (touche1) {
				case -1:
					cout << "Dans l'eau";
					break;
				case -2:
					cout << "Touche";
					break;
				default:
					cout << "Bizarre...";
					break;
				}


				//Tour du joueur 2 
				char lettre2;
				int y2;
				cout << nom2 + " donnez votre coup (x,y) avec sachant que x est une lettre (A a J) et y un nombre (1 a 10) : " << endl;
				cin >> lettre2;
				cin >> y2;

				//On transforme la lettre en entier
				//A refaire : la gestion des minuscules pour le tir fait planter
				int x2;
				y2 = y2 - 1;
				if (int(lettre2) >= 98) {
					x2 = int(lettre2) - 97;
					cout << x2 << endl;
				}
				else {
					x2 = int(lettre2) - 65;
					cout << x2 << endl;
				}

				//On frappe la grille adverse
				int touche2 = grille1.toucherPos(x2, y2);
				switch (touche2) {
				case -1:
					cout << "Dans l'eau";
					break;
				case -2:
					cout << "Touche";
					break;
				default:
					cout << "Bizarre...";
					break;
				}
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