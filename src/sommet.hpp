#ifndef _SOMMET_H
#define _SOMMET_H

#include <iostream>
#include <set> 
#include <string>
#include <vector>


class Sommet {
    private:
    std::set<int> listeAdj; //liste d adjacence du sommet
    int num; // numero du sommet

    public:
    Sommet();
    Sommet(int numero);

    void ajouterVoisin(int voisin);
    void setNum(int numero);
    const int getNum();
    std::set<int>& getListeAdj();    
    std::string print();
};

#endif //_SOMMET_H