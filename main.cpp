#include <iostream>
#include <vector>

//#include "src/histogram.hpp"
#include "src/graphe.hpp"
#include "src/sommet.hpp"
#include "src/LectureEcriture.hpp"
#include "src/statistique.hpp"


int main()
{    
    Graphe graphe(true, 2);
    // graphe.ajouterArete(0, 1);
    for (Sommet sommet : graphe.getSommets())
    {
        cout << sommet.print() << endl;
        for(int voisin : sommet.getListeAdj())
        {
            cout << "\t\t" << voisin << endl;
        }
    }
    graphe.ajouterArc(0, 1);
    for (Sommet sommet : graphe.getSommets())
    {
        cout << sommet.print() << endl;
        for(int voisin : sommet.getListeAdj())
        {
            cout << "\t\t" << voisin << endl;
        }
    }
    graphe.ajouterArc(1, 0);
    for (Sommet sommet : graphe.getSommets())
    {
        cout << sommet.print() << endl;
        for(int voisin : sommet.getListeAdj())
        {
            cout << "\t\t" << voisin << endl;
        }
    }
    return 0;
}
