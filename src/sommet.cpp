#include "sommet.hpp"

using namespace std;

Sommet::Sommet(){}

/**
 * @brief Constructeur du sommet
 */
Sommet::Sommet(int numero)
{
    num = numero;
}

/**
 * @brief Ajoute un voisin au sommet dans sa liste d adjacence
 * 
 * @param voisin numero du sommet voisin a ajouter
 * @return ** void 
 */
void Sommet::ajouterVoisin(int voisin)
{
    listeAdj.insert(voisin);
}

/*
    Getter / Setter
*/

/**
 * @brief Modifie le numero du sommet
 * 
 * @param numero nouveau numero du sommet
 * @return ** void 
 */
void Sommet::setNum(int numero)
{
    num = numero;
}

/**
 * @brief Retourne le numero du sommet
 * 
 * @return const int numero du sommet
 */
const int Sommet::getNum()
{
    return num;
}

/**
 * @brief Retourne la liste d adjacence du sommet
 * 
 * @return set<int>& la liste d adjacence du sommet
 */
set<int>& Sommet::getListeAdj()
{
    return listeAdj;
}

/*
    Affichage
*/

/**
 * @brief Retourne un string pour afficher le sommet
 * 
 * @return string Le string contenant le numero du sommet et sa liste d adjacence pour afficher le sommet
 */
string Sommet::print()
{
    string printString(to_string(num)+": ");
    for(auto voisin: listeAdj)
    {
        printString += to_string(voisin) + "  "; 
    }
    return printString;
}