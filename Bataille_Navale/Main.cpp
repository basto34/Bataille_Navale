#include "Board.h"
#include"Utilisateur.h"
#include <iostream>
#include <thread>
#include <stdlib.h>     //for using the function sleep

#include"IA.h"
#include <string> 
using namespace std;


void main() {
	int nbjoueurs;
	int longueur = 10, largeur = 10;
	int nbbateaux = 1;

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

			//Nettoyer la console
			system("CLS");

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
				char lettre = 0;
				int y = 0;
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
					int comptdebile = 0;
					while (orientation != "h" && orientation != "v" && orientation != "H" && orientation != "V") {
						comptdebile += 1;
						cin >> orientation;
						if (orientation == "h" || orientation == "H") {
							isHorizontal = true;
						}
						else if (orientation == "v" || orientation == "V") {
							isHorizontal = false;
						}
						else {
							if (comptdebile <=2) { std::cout << "Choisissez une valeur possible" << endl; }
							else { std::cout << "T'es idiot ? On t'a dis choisis une valeur possible" << endl; }
						}
					}
					

					//On demande la position du bateau
					cout << "Entrez le point d'origine du premier bateau (x,y) sachant que x est une lettre (A a J) et y un nombre (1 a 10) : " << endl;
					cin >> lettre >> y;
					//On vérifie si la lettre et le nombre sont dans le bon intervalle
					cout << int(lettre) << endl;
					cout << y << endl;
					while ((int(lettre) <= 64 || (int(lettre) > 74 && int(lettre) < 97) || int(lettre) > 106) || (y < 1 || y > 10))
					{
						cout << "Les valeurs ne sont pas bonnes ! Rentrez la colonne entre A et J puis la ligne entre 1 et 10" << endl;
						cin >> lettre >> y;
					}
					
					int x;
					y = y - 1;
					if (int(lettre) >= 97) {
						x = int(lettre) - 97;
						cout << x << endl;
					}
					else {
						x = int(lettre) - 65;
						cout << x << endl;
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
							grille1.poseBoat(boat);
							grille1.afficherGrille();
							system("pause");
						}
						else {
							cout << "Le bateau ne peut pas etre place ici. Recommencez" << endl;
						}
						
						
					}
					else {
						if (grille2.estBienPlace(boat)) {
							cout << "Le bateau est bien place" << endl;
							test = true;
							grille2.poseBoat(boat);
							grille2.afficherGrille();
							system("pause");
						}
						else {
							cout << "Le bateau ne peut pas etre place ici. Recommencez" << endl;
							
						}
						
						
					}
					
					
				} while (!test);
					


			}
		}

			//On doit créer deux autres grilles qui sont les grilles sur lesquelles on tire
			Board grille3(longueur, largeur, nbbateaux);
			Board grille4(longueur, largeur, nbbateaux);
			//Jeu : on joue tant que les deux grille contiennent des bateaux
			
			while (!grille1.estVide() || !grille2.estVide()) {
				//On nettoye la console
				system("CLS");

				//Tour du joueur 1 
				cout << "Tour de " + nom1 << endl;
				char lettre1;
				int y1;
				cout << "Grille de l'adversaire" << endl;
				grille3.afficherGrille();
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "Votre grille" << endl;
				grille1.afficherGrille();
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
				system("CLS");
				cout << "Coup envoye !" << endl;
				for (int i = 0; i <= 2; i++) {
					std::this_thread::sleep_for(333ms);
					cout << ".";
				}
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
				std::this_thread::sleep_for(1500ms);
				//On note le résultat sur la grille de l'adversaire
				grille3.setVal(x1, y1, touche1);

				//On nettoye la console
				system("CLS");

				//Tour du joueur 2 
				cout << "Tour de " + nom2 << endl;
				char lettre2;
				int y2;
				cout << "Grille de l'adversaire" << endl;
				grille4.afficherGrille();
				cout << "-------------------------------------------------------------------------" << endl;
				cout << "Votre grille" << endl;
				grille2.afficherGrille();
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
				system("CLS");
				cout << "Coup envoye !" << endl;
				for (int i = 0; i <= 2; i++) {
					std::this_thread::sleep_for(333ms);
					cout << ".";
				}
				
				switch (touche2) {
				case -1:
					cout << "Dans l'eau :(" << endl;
					break;
				case -2:
					cout << "Touche !!!" << endl;
					break;
				default:
					cout << "Bizarre..." << endl;
					break;
				}
				std::this_thread::sleep_for(1500ms);
				//On note le résultat sur la grille de l'adversaire
				grille4.setVal(x2, y2, touche2);
			}

		





	}

	else if (nbjoueurs == 1) {
		vector<int> attaqueIA;
		IA joueur2;
		//jeu IA
		cout << "jeu ia" << endl;
		while (!grille1.estVide() && !grille2.estVide()) {
			grille1.afficherGrille();
			attaqueIA = joueur2.jouerReflechi(grille1);
			//tant que la position d'attaque choisie par l'IA est interdite
			//on demande une autre position
			while (grille1.getGrille()[attaqueIA[0]][attaqueIA[2]] > 0) {
				attaqueIA = joueur2.jouerReflechi(grille1);
			}
		}

	}
}