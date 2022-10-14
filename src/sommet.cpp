#include "sommet.hpp"

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

void Sommet::ajouterVoisin(Sommet &voisin)
{
    //this->listeAdj.insert(voisin);
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
        printString += to_string(it->num) + "  ";  //On additionne toutes les notes
    }
    // cout << printString << endl;
    // cout << this->listeAdj.size() << endl;
    return printString;

}