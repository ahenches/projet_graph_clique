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
    sommets.resize (nSommet);
    Sommet s;
    for(int i = 0; i < nSommet; i++)
    {
        s = Sommet(i);
        sommets[i] = s;
    }
    nbSommet = nSommet;
}

void Graphe::genererArcsAleatoires(float prob)
{
    srand(time(nullptr));
    for(long unsigned int i = 0; i < sommets.size(); i++)
    {
        for(long unsigned int j = 0; j < i; j++)
        {
            if (((float)rand() / (float)RAND_MAX) > prob) 
            {
                ajouterArc(i, j);
            }
        }
        for(long unsigned int j = i+1; j < sommets.size(); j++)
        {
            if (((float)rand() / (float)RAND_MAX) > prob) 
            {
                ajouterArc(i, j);
            }
        }
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