#include "sommet.hpp"

using namespace std;

/**
 * Sommet implementation
 */
Sommet::Sommet()
{

}

Sommet::Sommet(int numero)
{
    num = numero; // pas sur de garder ça vu qu'on l'a déja dans graphe.
}

bool Sommet::operator<(const Sommet& rhs) const 
{
    return num < rhs.num;
};

void Sommet::ajouterVoisin(Sommet &voisin)
{
    listeAdj.insert(voisin);
    // cout << this->listeAdj.size() << endl;
}


int Sommet::getNum()
{
    return num;
}

set<Sommet> Sommet::getListeAdj()
{
    return listeAdj;
}

string Sommet::print()
{
    string printString("");
    for(auto it = listeAdj.begin() ; it != listeAdj.end() ; ++it)
    {   
        printString += to_string(it->num) + "  "; 
    }
    // cout << printString << endl;
    // cout << this->listeAdj.size() << endl;
    return printString;

}