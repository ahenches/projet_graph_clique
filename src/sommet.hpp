#include <iostream>
#include <vector> //Ne pas oublier !
#include <string>

using namespace std;

#ifndef _SOMMET_H
#define _SOMMET_H

class Sommet {
    private:
    int num;
    vector<Sommet> listeAdj;
    
    public:
    Sommet();
    Sommet(int numero);
    void ajouterVoisin(Sommet &s);
    string print();
};

#endif //_SOMMET_H