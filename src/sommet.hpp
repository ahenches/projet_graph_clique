#include <iostream>
#include <set> //Ne pas oublier !
#include <string>

#ifndef _SOMMET_H
#define _SOMMET_H

class Sommet {
    private:
    int num;
    std::set<Sommet> listeAdj;
    
    public:
    Sommet();
    Sommet(int numero);
    bool operator<(const Sommet& rhs) const; // overload l'operateur d'ordre
    void ajouterVoisin(Sommet &s);
    int getNum();
    std::set<Sommet> getListeAdj();
    
    std::string print();

    
};



#endif //_SOMMET_H