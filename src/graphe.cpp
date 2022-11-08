#include "graphe.hpp"

#include <unistd.h>

unsigned int microseconds = 2000000;

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
    sommets[num] = s;
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
    map<int, Sommet>::iterator itr;
    for(itr = sommets.begin(); itr != sommets.end(); itr++)
    {
        Sommet s = itr ->second;
        printString += s.print() + "\n";
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
    map<int, Sommet> sommetsGraphe = getSommets();
    vector<int> listeDistanceDeux;
    int nbCheminLongDeux;

    nbCheminLongDeux = 0;

    map<int, Sommet>::iterator itr;
    for(itr = sommets.begin(); itr != sommets.end(); itr++)
    {
        Sommet sommetDepart = itr -> second;
        listeDistanceDeux = distanceDeuxDuSommet(sommetDepart.getNum());
        nbCheminLongDeux += listeDistanceDeux.size();
    }
    return nbCheminLongDeux;
}
vector<int> Graphe::distanceDeuxDuSommet(int sommet)
{
    set<int> listeAdjSomDepart, listeAdjSomMilieu;
    vector<int>listeSommetsArrivee;
    Sommet sommetCourant;

    sommetCourant = getSommet(sommet);
    listeAdjSomDepart = sommetCourant.getListeAdj();
    listeAdjSomDepart.insert(sommet);

    for(int voisinCourant : listeAdjSomDepart)
    {
        listeAdjSomMilieu = getSommet(voisinCourant).getListeAdj();
                            
        set_difference(listeAdjSomMilieu.begin(), listeAdjSomMilieu.end(),
                        listeAdjSomDepart.begin(),listeAdjSomDepart.end(),
                        inserter(listeSommetsArrivee, listeSommetsArrivee.begin()));
    }    
    
    return listeSommetsArrivee;
}

vector<set<int>> Graphe::cliqueMaximaleBronKerbosch()
{
    set<int>potentielleClique, sommetsTraites, candidatsClique, cliqueMax;
    vector<set<int>> cliqueMaxMarquees;

    // P (candidats) = tous les sommets du graphe
    for(int i=0; i< nbSommet; i++)
    {
        candidatsClique.insert(i);
    }
    algoBronKerboshPivot(potentielleClique,candidatsClique,sommetsTraites, cliqueMaxMarquees);

    return cliqueMaxMarquees;
}

void Graphe::algoBronKerboshPivot(set<int> r_potentielleClique, set<int> p_candidatsClique, set<int> x_sommetsTraites, vector<set<int>>& cliqueMaxMarquees)
{
    Sommet pivot, sommetV;
    int numPivot;
    set<int>::iterator it;
    set<int> pUnionX, pDiffVoisinPivot, pInterVoisinV, xInterVoisinV, r_interV;
    
    if (p_candidatsClique.empty() && x_sommetsTraites.empty())
    {
        cliqueMaxMarquees.push_back(r_potentielleClique);
        return;
    }
    // Choix du pivot
    srand(time(nullptr));

    // P U X
    set_union(p_candidatsClique.begin(), p_candidatsClique.end(),
                x_sommetsTraites.begin(),x_sommetsTraites.end(),
                inserter(pUnionX, pUnionX.begin()));
    
    it = pUnionX.begin();
    advance(it,rand()%pUnionX.size());
    numPivot = *it;
    pivot = sommets[numPivot];

    // P \ Voisin(pivot)
    set_difference(p_candidatsClique.begin(), p_candidatsClique.end(),
                    pivot.getListeAdj().begin(), pivot.getListeAdj().end(),
                    inserter(pDiffVoisinPivot, pDiffVoisinPivot.begin()));
    
    for (int v : pDiffVoisinPivot)
    {
        sommetV = sommets[v];
        
        // P ⋂ Voisin(v)
        set_intersection(p_candidatsClique.begin(), p_candidatsClique.end(),
                        sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        inserter(pInterVoisinV, pInterVoisinV.begin()));
        
        // X ⋂ Voisin(v)
        set_intersection(x_sommetsTraites.begin(), x_sommetsTraites.end(),
                        sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        inserter(xInterVoisinV, xInterVoisinV.begin()));
        // R U v
        r_interV = r_potentielleClique;
        r_interV.insert(v);

        // Appel recursif
        algoBronKerboshPivot(std::move(r_interV), std::move(pInterVoisinV), std::move(xInterVoisinV), cliqueMaxMarquees);
        
        // P = P \ v
        p_candidatsClique.erase(v);

        // X = X U v
        x_sommetsTraites.insert(v);
    }
}

bool Graphe::estAreteDansGraphe(int sommet1, int sommet2)
{
    bool areteExiste;
    set<int> listeADJS1;

    areteExiste = false;
    listeADJS1 = sommets[sommet1].getListeAdj();

    if(listeADJS1.find(sommet2) != listeADJS1.end())
    {
        areteExiste = true;
    }
    return areteExiste;
}


Graphe Graphe::sousGrapheGi(int sommet)
{
    vector<int> voisinsD2Tmp;
    set<int>  voisinsD1, voisinsD2, listeSommetsGraphe, listeVi, listeN1, listeN2;
    Graphe gi(false);
    
    map<int, Sommet>::iterator itr;
    for(itr = sommets.lower_bound(sommet); itr != sommets.end(); itr++)
    {
        listeVi.insert(itr ->first);
    }
    
    voisinsD1 = sommets[sommet].getListeAdj();
    voisinsD2Tmp = distanceDeuxDuSommet(sommet);

    for(int v : voisinsD2Tmp)
    {
        voisinsD2.insert(v);
    }

    set_intersection(listeVi.begin(), listeVi.end(),
                    voisinsD1.begin(), voisinsD1.end(),
                    inserter(listeN1,listeN1.begin()));

    set_intersection(listeVi.begin(), listeVi.end(),
                    voisinsD2.begin(), voisinsD2.end(),
                    inserter(listeN2,listeN2.begin()));


    listeSommetsGraphe.insert(sommet);
    set_union(listeN1.begin(), listeN1.end(),
                listeN2.begin(), listeN2.end(),
                inserter(listeSommetsGraphe,listeSommetsGraphe.begin()));

    for(int s : listeSommetsGraphe)
    {
        gi.ajouterSommet(s);
    }

    for( int x : listeSommetsGraphe)
    {
        for(int y : listeSommetsGraphe)
        {
            if(x != y)
            {
                if(listeN1.find(x) != listeN1.end() && listeN1.find(y) != listeN1.end())
                {
                    if(estAreteDansGraphe(x,y))
                    {
                        gi.ajouterArete(x,y);
                    }
                }
                else if(listeN2.find(x) != listeN2.end() && listeN2.find(y) != listeN2.end())
                {
                    if(estAreteDansGraphe(x,y))
                    {
                        gi.ajouterArete(x,y);
                    }
                } 
                else if(listeN1.find(x) != listeN1.end() && listeN2.find(y) != listeN2.end())
                {
                    if(!estAreteDansGraphe(x,y))
                    {
                        gi.ajouterArete(x,y);
                    }
                }
            }
        }
    }

    return gi;
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

map<int,Sommet>& Graphe::getSommets()
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

