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

void Sommet::ajouterVoisin(Sommet& voisin)
{
    listeAdj.push_back(&voisin);

    // cout << "ajouterVoisin : " << print() << endl;
    // for(Sommet* voisin : getListeAdj())
    // {
    //     cout << "\t\tajouterVoisin : " << voisin->print() << endl;
    //     for(Sommet* voisinVoisin : voisin->getListeAdj())
    //     {
    //         cout << "\t\t\t\tajouterVoisin : " << voisinVoisin->print() << endl;
    //     }
    // }
    
    

    // listeAdj.insert(voisin);
    
    // cout << listeAdj.size() << endl;
    // cout << voisin.listeAdj.size() << endl;
}

// void Sommet::ajouterVoisin(Sommet &voisin)
// {
//     listeAdj.insert(voisin);
//     cout << listeAdj.size() << endl;
//     cout << voisin.listeAdj.size() << endl;
// }

void Sommet::setNum(int numero)
{
    num = numero;
}

int Sommet::getNum()
{
    return num;
}

vector<Sommet*>& Sommet::getListeAdj()
{
    return listeAdj;
}

string Sommet::print()
{
    string printString(to_string(num)+": ");
    for(Sommet* voisin: listeAdj)
    {   
        printString += to_string(voisin->num) + "  ";  //On additionne toutes les notes
    }
    return printString;
}