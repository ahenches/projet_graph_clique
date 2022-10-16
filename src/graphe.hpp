#ifndef _GRAPHE_H
#define _GRAPHE_H

#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "sommet.hpp"


class Graphe {

    private:
    int nbSommet;
    bool estOriente;

    public: 
    std::vector<Sommet> sommets;
    Graphe(bool oriente);
    Graphe(bool oriente, int nbSommet);
    void genererArcsAleatoires(float prob);
    bool ajouterSommet(int num);
    void ajouterArc(int source, int destination);
    void ajouterArete(int s1, int s2);

    std::string print();
    void coucou(std::vector<int> chien);

    std::vector<int> calculerDegres();

    int getNbSommet();
    bool getEstOriente();
    std::vector<Sommet> getSommets();

    
};


#endif //_GRAPHE_H