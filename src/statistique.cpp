#include "statistique.hpp"


void compteCheminDistanceDeux(Graphe graphe)
{
    vector<Sommet> sommets = graphe.getSommets();
    Sommet sommmetDepart, sommetMilieu;
    set<Sommet> voisinsSomDepart, voisinsSomMilieu;
    int nbCheminLongDeux;

    nbCheminLongDeux = 0;

    for (auto s : sommets)
    {
        sommmetDepart = s;
        voisinsSomDepart = sommmetDepart.getListeAdj();

        for(auto voisinDepart : voisinsSomDepart)
        {
            voisinsSomMilieu = voisinDepart.getListeAdj();

            for(auto voisinMilieu : voisinsSomMilieu)
            {
                if(!(voisinsSomDepart.contains(voisinMilieu)))
                {
                    nbCheminLongDeux++;
                }
            }
        }
    }
    cout << "Le nombre de chemin de longueur 2 du graphe est : " << nbCheminLongDeux << endl;
}
