#include "graphe.hpp"

/**
 * Implémentation Graphe
 */


using namespace std;

/*
    Construction Graphe
*/

Graphe::Graphe(bool oriente)
{
    estOriente = oriente;
}

Graphe::Graphe(bool oriente, int nSommet)
{
    estOriente = oriente;
    sommets.resize (nSommet);
    Sommet s;
    for(int i = 0; i < nSommet; i++)
    {
        s = Sommet(i);
        sommets[i] = s;
    }
    nbSommet = nSommet;
    nbArcs =0;
}

void Graphe::genererArcsAleatoires()
{
    float prob;
    srand(time(nullptr));
    prob = (float)rand() / (float)RAND_MAX;
    cout << "\tLa probabilité des arcs est : " << prob << endl;

    for(long unsigned int i = 0; i < sommets.size(); i++)
    {
        for(long unsigned int j = 0; j < i; j++)
        {
            if (((float)rand() / (float)RAND_MAX) < prob) 
            {
                ajouterArc(i, j);
            }
        }
        for(long unsigned int j = i+1; j < sommets.size(); j++)
        {
            if (((float)rand() / (float)RAND_MAX) < prob) 
            {
                ajouterArc(i, j);
            }
        }
    }
}

bool Graphe::ajouterSommet(int num)
{
    Sommet s(num);
    sommets.push_back(s);
    nbSommet++;

    return true;
}

void Graphe::ajouterArc(int sourceNum, int destinationNum)
{
    sommets[sourceNum].ajouterVoisin(destinationNum);
    nbArcs++;
    // potentielle verif    
}

void Graphe::ajouterArete(int s1Num, int s2Num)
{
    ajouterArc(s1Num, s2Num);
    ajouterArc(s2Num, s1Num);
}

/*
    Affichage
*/
string Graphe::print()
{
    string printString;
    for(Sommet sommet : sommets)
    {
        printString += sommet.print() + "\n";
    }
    return printString;
}

/*
    Calculs
*/
vector<int> Graphe::calculerDegres()
{
    vector<int> retDegres(nbSommet);
    int degreSommet;
    for(long unsigned int i = 0; i < sommets.size(); i++)
    {
        degreSommet = sommets[i].getListeAdj().size();
        retDegres[degreSommet]++;
    }
    return retDegres;
}

void Graphe::compteCheminDistanceDeux()
{
    vector<Sommet> sommetsGraphe = getSommets();
    int sommetMilieu;
    set<int> listeAdjSomDepart, listeAdjSomMilieu, listeSommetsArrivee;
    int nbCheminLongDeux;

    nbCheminLongDeux = 0;

    for (Sommet sommetDepart : sommetsGraphe)
    {
        for(int voisinCourant : sommetDepart.getListeAdj())
        {
            listeAdjSomMilieu = getSommet(voisinCourant).getListeAdj();
                        
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

/*
    Getter / Setter
*/

int Graphe::getNbSommet()
{
    return nbSommet;
}

bool Graphe::getEstOriente()
{
    return estOriente;
}
    
int Graphe::getNbArcs()
{
    return nbArcs;
}

vector<Sommet>& Graphe::getSommets()
{
    return sommets;
}

Sommet& Graphe::getSommet(int num)
{
    return sommets[num];
}

void Graphe::test()
{
    cout << sommets[0].getNum() << endl;
    sommets[0].setNum(5);
    cout << sommets[0].getNum() << endl;
}

