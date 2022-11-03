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
                if(estOriente)
                {
                    ajouterArc(i, j);
                }
                else 
                {
                    ajouterArete(i,j);
                }
            }
        }
        for(long unsigned int j = i+1; j < sommets.size(); j++)
        {
            if (((float)rand() / (float)RAND_MAX) < prob) 
            {
                if(estOriente)
                {
                    ajouterArc(i, j);
                }
                else 
                {
                    ajouterArete(i,j);
                }
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
    nbArcs+=  1;
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

int Graphe::calculerDegreMax()
{
    int degreMax;
    vector<int> degres;

    degres = calculerDegres();
    degreMax = (int)degres.size() - 1;

    while(degres[degreMax] == 0 && degreMax >= 0 )
    {
        degreMax --;
    }
    return degreMax;
}

int Graphe::compteCheminDistanceDeux()
{
    vector<Sommet> sommetsGraphe = getSommets();
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
           
            nbCheminLongDeux  += static_cast<int>(listeSommetsArrivee.size());
            if (listeSommetsArrivee.find(sommetDepart.getNum()) != listeSommetsArrivee.end())
            {
                nbCheminLongDeux -= 1;
            }
            listeSommetsArrivee.clear();
        }
    }
    return nbCheminLongDeux;
}

set<int> Graphe::cliqueMaximaleBronKerbosch()
{
    set<int>potentielleClique, sommetsTraites, candidatsClique, cliqueMax;

    for(int i=0; i< nbSommet; i++)
    {
        candidatsClique.insert(i);
    }
   cliqueMax =  algoBronKerbosh(potentielleClique,candidatsClique,sommetsTraites);

    return cliqueMax;

    
}

set<int> Graphe::algoBronKerbosh(set<int> r_potentielleClique, set<int> p_candidatsClique, set<int> x_sommetsTraites )
{
    Sommet pivot, sommetV;
    int numPivot;
    set<int>::iterator it;
    set<int> pUnionX, pDiffVoisinPivot, pInterVoisinV, xInterVoisinV;

    srand(time(nullptr));

    if (p_candidatsClique.empty() && x_sommetsTraites.empty())
    {
        //cliqueMax = r_potentielleClique;
        return r_potentielleClique;
    }

    // Choix du pivot
    set_union(p_candidatsClique.begin(), p_candidatsClique.end(),
                x_sommetsTraites.begin(),x_sommetsTraites.end(),
                inserter(pUnionX, pUnionX.begin()));
    
    it = pUnionX.begin();
    advance(it,rand()%pUnionX.size());
    numPivot = *it;
    pivot = sommets[numPivot];

    set_difference(p_candidatsClique.begin(), p_candidatsClique.end(),
                    pivot.getListeAdj().begin(), pivot.getListeAdj().end(),
                    inserter(pDiffVoisinPivot, pDiffVoisinPivot.begin()));
    
    for(int v : pDiffVoisinPivot)
    {
        sommetV = sommets[v];
        
        set_intersection(p_candidatsClique.begin(), p_candidatsClique.end(),
                        sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        inserter(pInterVoisinV, pInterVoisinV.begin()));
        
        set_intersection(x_sommetsTraites.begin(), x_sommetsTraites.end(),
                        sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        inserter(xInterVoisinV, xInterVoisinV.begin()));
        r_potentielleClique.insert(v);
        algoBronKerbosh(r_potentielleClique,pInterVoisinV, xInterVoisinV);
        p_candidatsClique.erase(v);
        x_sommetsTraites.insert(v);
    }
    
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

