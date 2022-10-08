/**
 * Project Untitled
 */

#ifndef _GRAPHE_H
#define _GRAPHE_H

#include <map>
#include <string>
#include <iostream>

#include "sommet.hpp"

class Graphe {

    private:
    int nbSommet;
    bool estOriente;

    public: 
    std::vector<Sommet> sommets;
    Graphe(bool oriente);
    Graphe(bool oriente, int nbSommet);
    // void rechercheSommet(Sommet sommet);
    bool ajouterSommet(int num);
    void ajouterArc(int source, int destination);
    void ajouterArete(int s1, int s2);

    std::string print();
};


#endif //_GRAPHE_H