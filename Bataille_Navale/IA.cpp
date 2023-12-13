#include "IA.h"

/**
	*\brief Joue au hasard
	*
	*
	*
**/
vector<int> IA::jouerAleatoire()
{
	vector<int> pos;
	pos.push_back(rand() % 10);
	pos.push_back(rand() % 10);
	return pos;
}
/**
	*\brief Joue selon les derniers coups de l'adversaire
	*
	*
	*
**/
vector<int> IA::jouerReflechi(Board grille) {
	vector<int> pos;
	vector<vector<int>> tableau = grille.getGrille();
	int coups = historique.size();
	if (tableau[historique[coups - 1][0]][historique[coups - 1][1]] == -2 && tableau[historique[coups - 2][0]][historique[coups - 2][1]] == -2 && historique.size() >= 2) {
		if (historique[coups - 1][0] == historique[coups - 2][0]) {
			if (historique[coups - 1][1] < 9 || tableau[historique[coups - 1][0]][historique[coups - 1][1] + 1] == -1) {
				pos = { historique[coups - 1][0],historique[coups - 1][1] + 1 };
			}
			else {
				int i = 1;
				while (tableau[historique[coups - 1][0]][historique[coups - 2 - i][1]] == -2) {
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
				while (tableau[historique[coups - 2 - i][0]][historique[coups - 1][1]] == -2) {
					i++;

				}
				pos = { historique[coups - 2][0] - i,historique[coups - 2][1] };

			}
		}
	}
	else if (tableau[historique[coups - 1][0]][historique[coups - 1][1]] == -2 && historique.size() >= 1) {
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
		/*	while ((pos[0] > 9 || pos[0] < 0 || pos[1]>9 || pos[1] < 0) && j < 4) {
				pos = hasard[rand() % 3];
			}*/
	}
	else {
		pos.push_back(rand() % 10);
		pos.push_back(rand() % 10);
	}
	while (tableau[pos[0]][pos[1]] < 0) {
		pos.push_back(rand() % 10);
		pos.push_back(rand() % 10);
	}
	historique.push_back(pos);
	return pos;

}