#include "statistique.hpp"

void compteCheminDistanceDeux(Graphe graphe)
{
    vector<Sommet> sommets = graphe.getSommets();
    Sommet sommmetDepart, sommetMilieu;
    set<Sommet> voisinsSomDepart, voisinsSomMilieu, listeSommetsArrivee;
    int nbCheminLongDeux;

    nbCheminLongDeux = 0;

    for (auto s : sommets)
    {
        sommmetDepart = s;
        voisinsSomDepart = sommmetDepart.getListeAdj();

        cout << "Voisin depart "  << sommmetDepart.getNum() << " : ";
            print(voisinsSomDepart);

        for(auto voisinDepart : voisinsSomDepart)
        {
            voisinsSomMilieu = voisinDepart.getListeAdj();
            
            
            cout <<endl<< "\t voisins  milieu " << voisinDepart.getNum() <<" : " ;
            print(voisinDepart.getListeAdj());
            
            set_difference(voisinsSomMilieu.begin(), voisinsSomMilieu.end(),
                            voisinsSomDepart.begin(),voisinsSomDepart.end(),
                            inserter(listeSommetsArrivee, listeSommetsArrivee.begin()));
           
            
            cout <<endl<< "\tliste arrivee : ";
            print(listeSommetsArrivee);
            cout << endl;
            nbCheminLongDeux  += static_cast<int>(listeSommetsArrivee.size());
            
        }
    }
    cout << "Le nombre de chemin de longueur 2 du graphe est : " << nbCheminLongDeux << endl;
}

void print (set<Sommet> s)
{
    cout << "{";
    for(auto i : s)
    {
        cout << i.getNum() << " ";
    }
    cout << "}";
}