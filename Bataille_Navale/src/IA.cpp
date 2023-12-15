#include "IA.h"

/**
	*\brief Renvoie une position aleatoire pour le tir
	*
	*
	*Renvoie une position aleatoire pour le tir
**/

vector<int> IA::jouerAleatoire()
{
	vector<int> pos;
	pos.push_back(rand() % 10);
	pos.push_back(rand() % 10);
	return pos;
}

/**
	*\brief Renvoie une position qui depend des coups precedents pour le tir
	*
	*
	*Renvoie une position qui depend des coups precedents pour le tir
**/


vector<int> IA::jouerReflechi(Board grille) {
	vector<int> pos;
	vector<vector<int>> tableau = grille.getGrille();
	int coups = historique.size();

	//Si les 2 derniers coups touchent un bateau, on tire sur la même ligne/colonne
	if ((historique.size() >= 2) && (tableau[historique[coups - 1][0]][historique[coups - 1][1]] == -2 && tableau[historique[coups - 2][0]][historique[coups - 2][1]] == -2)) {
		if (historique[coups - 1][0] == historique[coups - 2][0]) {
			if (historique[coups - 1][1] < 9 || tableau[historique[coups - 1][0]][historique[coups - 1][1] + 1] == -1) {
				pos = { historique[coups - 1][0],historique[coups - 1][1] + 1 };
			}
			else {
				int i = 1;
				while (historique[coups - 2][1] - i >= 0 && tableau[historique[coups - 1][0]][historique[coups - 2][1] - i] == -2) {
					i++;

				}
				pos = { historique[coups - 1][0],historique[coups - 2][1] - i };

			}
		}
		else if (historique[coups - 1][1] == historique[coups - 2][1]) {
			if (historique[coups - 1][0] < 9) {
				pos = { historique[coups - 1][0] + 1,historique[coups - 1][1] };
			}
			else {
				int i = 1;
				while (historique[coups - 2][0] - i >= 0 && tableau[historique[coups - 2][0] - i][historique[coups - 1][1]] == -2) {
					i++;

				}
				pos = { historique[coups - 2][0] - i,historique[coups - 2][1] };

			}
		}
	}
	//si uniquement le dernier coup touche un bateau, on dire dans une des cases autours
	else if ((coups >= 1) && tableau[historique[coups - 1][0]][historique[coups - 1][1]] == -2) {
		vector<vector<int>> hasard;
		if (historique[coups - 1][0] - 1 >= 0 && tableau[historique[coups - 1][0] - 1][historique[coups - 1][1]] > 0) {
			hasard.push_back({ historique[coups - 1][0] - 1, historique[coups - 1][1] });
		}
		if (historique[coups - 1][0] + 1 < 10 && tableau[historique[coups - 1][0] + 1][historique[coups - 1][1]] > 0) {
			hasard.push_back({ historique[coups - 1][0] + 1, historique[coups - 1][1] });
		}
		if (historique[coups - 1][1] - 1 >= 0 && tableau[historique[coups - 1][0]][historique[coups - 1][1] - 1] > 0) {
			hasard.push_back({ historique[coups - 1][0], historique[coups - 1][1] - 1 });
		}
		if (historique[coups - 1][1] + 1 < 10 && tableau[historique[coups - 1][0]][historique[coups - 1][1] + 1] > 0) {
			hasard.push_back({ historique[coups - 1][0], historique[coups - 1][1] + 1 });
		}

		if (hasard.size() == 0) {
			pos.push_back(rand() % 10);
			pos.push_back(rand() % 10);
		}
		else { pos = hasard[rand() % hasard.size()]; }
	}

	// Si le dernier coup n'a pas touché ou si c'est le premier coup, on tire au hasard
	else {
		pos.push_back(rand() % 10);
		pos.push_back(rand() % 10);
	}
	//Si le tir a déja été fait on tire au hasard autre part
	while (tableau[pos[0]][pos[1]] < 0) {
		pos[0] = (rand() % 10);
		pos[1] = (rand() % 10);
	}
	//On ajoute la position du tir dans l'historique des coups
	historique.push_back(pos);
	// On renvoie la position du tir choisie
	return pos;

}

/**
	*\brief Renvoie une position aleatoire pour le placement du bateau
	*
	*
	*Renvoie une position aleatoire pour le placement du bateau
**/

vector<int> IA::posBoat()
{
	return { rand() % 10,rand() % 10 };
}

/**
	*\brief Renvoie un booleen pour l'horizontalite du bateau
	*
	*
	*Renvoie un booleen pour l'horizontalite du bateau
**/

bool IA::horizontalBoat() {
	int i = rand() % 2;
	if (i == 0) {
		return true;
	}
	else {
		return false;
	}
}





