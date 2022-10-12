#include "sommet.hpp"

/**
 * Sommet implementation
 */

Sommet::Sommet(int numero)
{
    num = numero; // pas sur de garder ça vu qu'on l'a déja dans graphe.
}

void Sommet::ajouterVoisin(Sommet &voisin)
{
    this->listeAdj.push_back(voisin);
    // cout << this->listeAdj.size() << endl;
}

string Sommet::print()
{
    string printString("");
    for(auto it = listeAdj.begin() ; it != listeAdj.end() ; ++it)
    {   
        printString += to_string(it->num) + "  ";  //On additionne toutes les notes
    }
    // cout << printString << endl;
    // cout << this->listeAdj.size() << endl;
    return printString;

}