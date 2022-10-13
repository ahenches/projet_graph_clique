#ifndef _GRAPHE_H
#define _GRAPHE_H

#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "./sommet.hpp"

using namespace std;

class Graphe {

    private:
    int nbSommet;
    bool estOriente;

    public: 
    vector<Sommet> sommets;
    Graphe(bool oriente);
    Graphe(bool oriente, int nbSommet);
    // void rechercheSommet(Sommet sommet);
    void genererArcsAleatoires(float prob);
    bool ajouterSommet(int num);
    string print();
    void ajouterArc(int source, int destination);
    void ajouterArete(int s1, int s2);
    int getNbSommet();
    bool getEstOriente();
    vector<Sommet> getSommets();

    
};


#endif //_GRAPHE_H