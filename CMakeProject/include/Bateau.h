#pragma once
#include<iostream>
using namespace std;

class Bateau {
private:
    int x, y;
    bool mort = 0;
    int touche = 0;
    int nbCases;
    bool horizontal;
public:
    Bateau(int x, int y) :x(x), y(y) {};
    Bateau() {};
    void setHorizontal(bool c); 
    int getNbCases(); 
    int getX(); 
    int getY(); 
    bool getHorizontal();
    void setX(int c); 
    void setY(int c);
    void setNbCases(int nb);
    bool isMort();
};
