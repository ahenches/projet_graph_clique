/**
 * Project Untitled
 */
#include <iostream>
#include <vector> //Ne pas oublier !
#include <string>


#ifndef _SOMMET_H
#define _SOMMET_H

class Sommet {
    private:
    int num;
    std::vector<Sommet> listeAdj;
    
    public:
    Sommet(int numero);
    void ajouterVoisin(Sommet &s);
    std::string print();
};

#endif //_SOMMET_H