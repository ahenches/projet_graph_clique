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

vector<set<int>> Graphe::cliqueMaximaleBronKerbosch()
{
    set<int>potentielleClique, sommetsTraites, candidatsClique, cliqueMax;
    vector<set<int>> cliqueMaxMarquees;

    for(int i=0; i< nbSommet; i++)
    {
        candidatsClique.insert(i);
    }
    algoBronKerbosh(potentielleClique,candidatsClique,sommetsTraites, cliqueMaxMarquees, 0);

    return cliqueMaxMarquees;
}

void Graphe::algoBronKerboshPivot(set<int> r_potentielleClique, set<int> p_candidatsClique, set<int> x_sommetsTraites, vector<set<int>>& cliqueMaxMarquees)
{
    cout << "VALEUR candidats" << endl;
    for (auto val : p_candidatsClique)
        cout << val << endl;
    cout << "VALEUR clique" << endl;
    for (auto val : r_potentielleClique)
        cout << val << endl;

    Sommet pivot, sommetV;
    int numPivot;
    set<int>::iterator it;
    set<int> pUnionX, pDiffVoisinPivot, pInterVoisinV, xInterVoisinV, r_interV;

    

    
    
    if (p_candidatsClique.empty() && x_sommetsTraites.empty())
    {
        cout << "MARQUEE" << endl;
        for (auto val : r_potentielleClique)
            cout << val << endl;
        cliqueMaxMarquees.push_back(r_potentielleClique);
        return;
    }

    srand(time(nullptr));

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
    while (p_candidatsClique.size() != 0)
    {
        int v = *p_candidatsClique.begin();
        cout << "NOW  :: " << v << endl << endl;
        sommetV = sommets[v];
        
        set_intersection(p_candidatsClique.begin(), p_candidatsClique.end(),
                        sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        inserter(pInterVoisinV, pInterVoisinV.begin()));
        
        set_intersection(x_sommetsTraites.begin(), x_sommetsTraites.end(),
                        sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        inserter(xInterVoisinV, xInterVoisinV.begin()));
        r_interV = r_potentielleClique;
        r_interV.insert(v);
        algoBronKerboshPivot(r_interV, pInterVoisinV, xInterVoisinV, cliqueMaxMarquees);
        // r_potentielleClique
        p_candidatsClique.erase(v);
        x_sommetsTraites.insert(v);
    }
}
void Graphe::algoBronKerbosh(set<int> r_potentielleClique, set<int> p_candidatsClique, set<int> x_sommetsTraites, vector<set<int>>& cliqueMaxMarquees, int niveau)
{
    cout << "DEPTH : " << niveau << endl;
    cout << "avec :: " << endl << endl;
    cout << "VALEUR candidats : {";
    for (auto val : p_candidatsClique)
        cout << val+1 << " ";
    cout << "}" << endl;

    cout << "VALEUR clique : {";
    for (auto val : r_potentielleClique)
        cout << val+1 << " ";
    cout << "}" << endl;

    cout << "VALEUR traites : {";
    for (auto val : x_sommetsTraites)
        cout << val+1 << " ";
    cout << "}" << endl;

    Sommet sommetV;
    // int numPivot;
    // set<int>::iterator it;
    set<int> r_interV, p_interVoisinV, x_interVoisinV, sommetV_listADJ;

    set<int> p_candidatsClique_Copy = p_candidatsClique;

    // algorithme BronKerbosch1(R, P, X)
    // si P et X sont vides alors
    //     déclarer R clique maximale
    // pour tout sommet v de P faire
    //     BronKerbosch1(R ⋃ {v}, P ⋂ N(v), X ⋂ N(v))
    //     P := P \ {v}
    //     X := X ⋃ {v}

    
    
    if (p_candidatsClique.empty() && x_sommetsTraites.empty())
    {
        cout << "MARQUEE : {";
        for (auto val : r_potentielleClique)
            cout << val+1 << " ";
        cout << "}" << endl;
        cliqueMaxMarquees.push_back(r_potentielleClique);
        return ;
    }

    while (p_candidatsClique.size() != 0)
    {
        int v = *p_candidatsClique_Copy.begin();
        
        
        cout << endl << endl << "NOW  :: (" << niveau << ")" << v+1 << endl << endl;
        usleep(microseconds);

        

        
        sommetV = sommets[v];
        sommetV_listADJ = sommetV.getListeAdj();
        
        set_intersection(p_candidatsClique.begin(), p_candidatsClique.end(),
                        sommetV_listADJ.begin(), sommetV_listADJ.end(),
                        inserter(p_interVoisinV, p_interVoisinV.begin()));
        
        set_intersection(x_sommetsTraites.begin(), x_sommetsTraites.end(),
                        sommetV_listADJ.begin(), sommetV_listADJ.end(),
                        inserter(x_interVoisinV, x_interVoisinV.begin()));

        r_interV = r_potentielleClique;
        // r_interV.insert(r_potentielleClique.begin(), r_potentielleClique.end());
        r_interV.insert(v);
        algoBronKerbosh(r_interV, p_interVoisinV, x_interVoisinV, cliqueMaxMarquees, niveau+1);
        // r_potentielleClique
        p_candidatsClique.erase(v);
        // p_candidatsClique_Copy.erase(p_candidatsClique_Copy.begin());
        x_sommetsTraites.insert(v);
        cout << endl << "FIN  :: (" << niveau << ")" << v+1 << endl;
        cout << "TAILLE candidats : ";
        cout << p_candidatsClique.size() << " ";
    }
    cout << "FIN DE FONCTION " << niveau << endl;
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

