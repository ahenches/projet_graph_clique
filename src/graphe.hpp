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


class Graphe {

    private:
    int nbSommet;
    bool estOriente;
    int nbArcs;

    public: 
    std::vector<Sommet> sommets;
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
    std::vector<std::set<int>> cliqueMaximaleBronKerbosch();
    void algoBronKerboshPivot(std::set<int> r_potentielleClique, std::set<int> p_candidatsClique, std::set<int> x_sommetsTraites, std::vector<std::set<int>>& cliqueMaxMarquees);
    void algoBronKerbosh(std::set<int> r_potentielleClique, std::set<int> p_candidatsClique, std::set<int> x_sommetsTraites, std::vector<std::set<int>>& cliqueMaxMarquees, int niveau);


    int getNbSommet();
    bool getEstOriente();
    int getNbArcs();
    std::vector<Sommet>& getSommets();
    Sommet& getSommet(int i);
    void test();


    
};


#endif //_GRAPHE_H