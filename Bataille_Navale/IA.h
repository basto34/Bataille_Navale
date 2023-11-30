#pragma once
#include<iostream>
#include<vector>
#include"Bateau.h"
using namespace std;

class IA
{
private:
	string pseudo = "Automate";
public:
	vector<int> jouerAleatoire(int longueur, int largeur);
};

