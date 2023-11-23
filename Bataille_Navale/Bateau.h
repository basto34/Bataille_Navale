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
    void setHorizontal(bool c); 
    int getNbCases(); 
    int getX(); 
    int getY(); 
    void setX(int c); 
    void setY(int c);
};
