#ifndef _GRAPHE_H
#define _GRAPHE_H

#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <sstream>
#include <set>
#include <algorithm>
#include "sommet.hpp"

#define NB_SOMMET_FACEBOOK 4039
#define NB_SOMMET_EMAIL_EU 1005
#define NB_SOMMET_LASTFM 7624
#define ORIENTE 1
#define NON_ORIENTE 0

class Graphe {

    private:
    int nbSommet;
    bool estOriente;
    int nbArcs;

    public: 
    std::map<int,Sommet> sommets;
    Graphe(bool oriente);
    Graphe(bool oriente, int nbSommet);
    void genererArcsAleatoires();
    bool ajouterSommet(int num);
    void ajouterArc(int source, int destination);
    void ajouterArete(int s1, int s2);

    std::string print();
    
    std::vector<int> calculerDegres();
    int calculerDegreMax();
    int compteCheminDistanceDeux();
    std::vector<int> distanceDeuxDuSommet(int sommet);
    std::vector<std::set<int>> cliqueMaximaleBronKerbosch();
    void algoBronKerboshPivot(std::set<int> r_potentielleClique, std::set<int> p_candidatsClique, std::set<int> x_sommetsTraites, std::vector<std::set<int>>& cliqueMaxMarquees);
    bool estAreteDansGraphe(int sommet1, int sommet2);
    Graphe sousGrapheGi(int sommet);


    int getNbSommet();
    bool getEstOriente();
    int getNbArcs();
    std::map<int,Sommet>& getSommets();
    Sommet& getSommet(int i);
    void test();


    
};


#endif //_GRAPHE_H