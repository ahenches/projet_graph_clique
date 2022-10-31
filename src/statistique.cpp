#include "statistique.hpp"

void compteCheminDistanceDeux(Graphe graphe)
{
    vector<Sommet> sommetsGraphe = graphe.getSommets();
    int sommetMilieu;
    set<int> listeAdjSomDepart, listeAdjSomMilieu, listeSommetsArrivee;
    int nbCheminLongDeux;

    nbCheminLongDeux = 0;

    for (Sommet sommetDepart : sommetsGraphe)
    {
        for(int voisinCourant : sommetDepart.getListeAdj())
        {
            listeAdjSomMilieu = graphe.getSommet(voisinCourant).getListeAdj();
                        
            set_difference(listeAdjSomMilieu.begin(), listeAdjSomMilieu.end(),
                            listeAdjSomDepart.begin(),listeAdjSomDepart.end(),
                            inserter(listeSommetsArrivee, listeSommetsArrivee.begin()));
           
           // cout << endl;
            nbCheminLongDeux  += static_cast<int>(listeSommetsArrivee.size());
            if (listeSommetsArrivee.find(sommetDepart.getNum()) != listeSommetsArrivee.end())
            {
                nbCheminLongDeux -= 1;
            }
            listeSommetsArrivee.clear();
        }
    }
    cout << "Le nombre de chemin de longueur 2 du graphe est : " << nbCheminLongDeux << endl;
}
