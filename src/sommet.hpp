#ifndef _SOMMET_H
#define _SOMMET_H

#include <iostream>
#include <set> //Ne pas oublier !
#include <string>
#include <vector>



class Sommet {
    private:
    
    std::set<int> listeAdj;
    int num;

    public:
    
    Sommet();
    Sommet(int numero);

    // bool operator<(const Sommet& rhs) const; // overload l'operateur d'ordre

    void ajouterVoisin(int voisin);
    void setNum(int numero);
    const int getNum();
    // std::vector<Sommet>& getListeAdj();
    std::set<int>& getListeAdj();
    
    std::string print();

};




#endif //_SOMMET_H