#include <iostream>
#include <set> //Ne pas oublier !
#include <string>

using namespace std;

#ifndef _SOMMET_H
#define _SOMMET_H

class Sommet {
    private:
    int num;
    set<Sommet> listeAdj;
    
    public:
    Sommet();
    Sommet(int numero);
    bool operator<(const Sommet& rhs) const; // overload l'operateur d'ordre
    void ajouterVoisin(Sommet &s);
    int getNum();
    set<Sommet>getListeAdj();
    string print();

    
};



#endif //_SOMMET_H