#pragma once
#include<iostream>
#include<vector>
#include"Bateau.h"
#include "Board.h"
using namespace std;

class IA
{
private:
	string pseudo = "Automate";
	vector<vector<int>> historique;
public:
	vector<int> jouerAleatoire();
	vector<int> jouerReflechi(Board grille);
	bool horizontalBoat();
	vector<int> posBoat();
};
