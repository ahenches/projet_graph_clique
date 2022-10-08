/**
 * Project Untitled
 */


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
    // std::cout << this->listeAdj.size() << std::endl;
}

std::string Sommet::print()
{
    std::string printString("");
    for(auto it = listeAdj.begin() ; it != listeAdj.end() ; ++it)
    {   
        printString += std::to_string(it->num) + "  ";  //On additionne toutes les notes
    }
    // std::cout << printString << std::endl;
    // std::cout << this->listeAdj.size() << std::endl;
    return printString;

}