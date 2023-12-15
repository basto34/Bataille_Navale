#include "Board.h"

/**
	*\brief Verifie si la grille est vide
	*
	*
	*Ne retourne true que si toutes les cases sont vides, c'est a dire s'il n'y a pas de bateau en vie. Les bateaux coules comptent pour une case vide
**/
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

/**
	*\brief Constructeur de grille
	*
	*
	*Prend une longueur, une largeur et un nombre de bateaux en arguments
**/
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

/**
	*\brief Effectue un tir sur la position donnee en arguments
	*
	*
	*Ne change la valeur de la position que si elle n'a pas ete tiree precedemment
**/
int Board::toucherPos(int x, int y) {
	if (grille[y][x] > 0) {
		grille[y][x] = 0 - grille[y][x];
	}
	return grille[y][x];
}

/**
	*\brief Pose le bateau sur la grille. A n'appeler que si on a utilise estBienplace precedemment
	*
	*
	* Prend un bateau en argument. Met a jour la grille en posant le bateau.
**/
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

/**
	*\brief Ecrit l'entier val dans la grille a la position x,y
	*
	*
	*
**/
void Board::setVal(int x, int y, int val)
{
	grille[y][x] = val;
}

/**
	*\brief Retourne la grille
	*
	*
	*
**/
vector<vector<int>> Board::getGrille()
{
	return grille;
}

/**
	*\brief Verifie si le bateau est bien place
	*
	*
	*Prend le bateau a verifier en argument. Retourne true si le bateau est bien place. 
	* Le bateau est mal place si il deborde de la grille ou si il est place sur un autre bateau.
**/
bool Board::estBienPlace(Bateau boat)
{
	bool horizontal = boat.getHorizontal();
	int x = boat.getX();
	int y = boat.getY();

	if (horizontal) {
		//On vérifie si c'est bien dans la grille
		if (x + boat.getNbCases() > 10) {
			
			return false;
		}
		for (int i = x; i < x + boat.getNbCases(); i++) {
			//Vérification superposition
			if (grille[y][i] == 2) {
				return false;
			}
		}
		return true;
	}


	else {
		if (y + boat.getNbCases() > 10) {
			return false;
		}
		for (int i = y; i < y + boat.getNbCases(); i++) {
			//Vérification superposition
			if (grille[i][x] == 2) {
				return false;
			}
		}
		return true;
	}
}

/**
	*\brief Affiche la grille
	*
	*
	*affiche la grille dans la console.
**/
void Board::afficherGrille() {
	// Afficher la numérotation des colonnes (A à J)
	cout << "   A B C D E F G H I J" << endl;
	for (int i = 0; i < longueur; i++) {
		// Afficher la numérotation des lignes (1 à 10)
		if(i<=8) { cout << i + 1 << "  "; }
		else { cout << i + 1 << " "; }
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
			cout << " "; // Ajouter un espace entre chaque case pour améliorer la lisibilité
		}
		cout << endl;
	}
}