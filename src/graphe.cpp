#include "graphe.hpp"

/**
 * Graphe implementation
 */

Graphe::Graphe(bool oriente)
{
    estOriente = oriente;
}
Graphe::Graphe(bool oriente, int nSommet)
{
    estOriente = oriente;
    for(int i = 0; i < nSommet; i++)
    {
        ajouterSommet(i);
    }
}

// /**
//  * @param sommet
//  */
// void Graphe::rechercheSommet(Sommet sommet)
// {

// }

/**
 * @param sommet
 */
bool Graphe::ajouterSommet(int num)
{
    Sommet s(num);
    sommets.push_back(s);
    nbSommet++;

    return true;
}

string Graphe::print()
{
    string printString;
    int i = 0;
    cout << sommets.size() << endl;
    for(auto it = sommets.begin() ; it != sommets.end() ; ++it)
    {
        printString += to_string(i) + ":" + it->print() + "\n";
        i++;
    }
    // cout << "'" << printString << "'" <<endl;
    return printString;
}

void Graphe::ajouterArc(int sourceNum, int destinationNum)
{
    sommets[sourceNum].ajouterVoisin(sommets[destinationNum]);
    // potentielle verif    
}

void Graphe::ajouterArete(int s1Num, int s2Num)
{
    ajouterArc(s1Num, s2Num);
    ajouterArc(s2Num, s1Num);
}