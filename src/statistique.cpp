#include "statistique.hpp"

void compteCheminDistanceDeux(Graphe graphe)
{
    vector<Sommet> sommetsGraphe = graphe.getSommets();
    Sommet sommetDepart, sommetMilieu;
    set<Sommet> listeAdjSomDepart, listeAdjSomMilieu, listeSommetsArrivee;
    int nbCheminLongDeux;

    nbCheminLongDeux = 0;

    for (auto sommetCourant : sommetsGraphe)
    {
        sommetDepart = sommetCourant;
        listeAdjSomDepart = sommetDepart.getListeAdj();

        for(Sommet voisinCourant : listeAdjSomDepart)
        {
            sommetMilieu = voisinCourant;
            listeAdjSomMilieu = sommetMilieu.getListeAdj();
                        
            set_difference(listeAdjSomMilieu.begin(), listeAdjSomMilieu.end(),
                            listeAdjSomDepart.begin(),listeAdjSomDepart.end(),
                            inserter(listeSommetsArrivee, listeSommetsArrivee.begin()));
           
            print(listeSommetsArrivee);
            cout << endl;
            nbCheminLongDeux  += static_cast<int>(listeSommetsArrivee.size());
            if (listeSommetsArrivee.find(sommetDepart) != listeSommetsArrivee.end())
            {
                nbCheminLongDeux -= 1;
            }
            listeSommetsArrivee.clear();
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