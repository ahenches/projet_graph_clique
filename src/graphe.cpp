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
    set<int> listeDistanceDeux;
    int nbCheminLongDeux;

    nbCheminLongDeux = 0;

    for (Sommet sommetDepart : sommetsGraphe)
    {
        listeDistanceDeux = distanceDeuxDuSommet(sommetDepart.getNum());
        nbCheminLongDeux += listeDistanceDeux.size();
    }
    return nbCheminLongDeux;
}
set<int> Graphe::distanceDeuxDuSommet(int sommet)
{
    set<int> listeAdjSomDepart, listeAdjSomMilieu, listeSommetsArrivee;
    Sommet sommetCourant;
    sommetCourant = getSommet(sommet);
    listeAdjSomDepart = sommetCourant.getListeAdj();
    for(int voisinCourant : listeAdjSomDepart)
    {
        listeAdjSomMilieu = getSommet(voisinCourant).getListeAdj();
                    
        set_difference(listeAdjSomMilieu.begin(), listeAdjSomMilieu.end(),
                        listeAdjSomDepart.begin(),listeAdjSomDepart.end(),
                        inserter(listeSommetsArrivee, listeSommetsArrivee.begin()));
    }
    if (listeSommetsArrivee.find(sommet) != listeSommetsArrivee.end())
    {
        listeSommetsArrivee.erase(sommet);
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
/*
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
        cout << "\t\tMARQUEE : {";
        for (auto val : r_potentielleClique)
            cout << val+1 << " ";
        cout << "}" << endl;
        cliqueMaxMarquees.push_back(r_potentielleClique);
        return ;
    }

    while (p_candidatsClique_Copy.size() != 0)
    {
        int v = *p_candidatsClique_Copy.begin();
        
        
        cout << endl << endl << "NOW  :: (" << niveau << ")" << v+1 << endl << endl;
        usleep(microseconds);

        sommetV = sommets[v];
        sommetV_listADJ = sommetV.getListeAdj();
        // cout << endl << "\t\t $$$$ LISTE ADJ  : " ;
        // for (auto i : sommetV_listADJ)
        //     cout << i+1 << " ";
        // cout << endl;
        // cout << endl << "\t\t $$$$ p_candidatsClique  : " ;
        // for (auto i : p_candidatsClique)
        //     cout << i+1 << " ";
        // cout << endl;

        // cout << endl << "\t\t $$$$ p_interVoisinV  : " ;
        // for (auto i : p_interVoisinV)
        //     cout << i+1 << " ";
        // cout << endl;

        

        set_intersection(sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        p_candidatsClique.begin(), p_candidatsClique.end(),
                        inserter(p_interVoisinV, p_interVoisinV.begin()));
        
        set_intersection(x_sommetsTraites.begin(), x_sommetsTraites.end(),
                        sommetV.getListeAdj().begin(), sommetV.getListeAdj().end(),
                        inserter(x_interVoisinV, x_interVoisinV.begin()));


        // cout << endl << "\t\t $$$$ p_interVoisinV  : " ;
        // for (auto i : p_interVoisinV)
        //     cout << i+1 << " ";
        // cout << endl;

        r_interV = r_potentielleClique;
        r_interV.insert(v);
        algoBronKerbosh(std::move(r_interV), std::move(p_interVoisinV), std::move(x_interVoisinV), cliqueMaxMarquees, niveau+1);
        p_candidatsClique.erase(p_candidatsClique.begin());
        p_candidatsClique_Copy.erase(p_candidatsClique_Copy.begin());

        x_sommetsTraites.insert(v);
        cout << endl << "FIN  :: (" << niveau << ")" << v+1 << endl;
    }
    cout << endl << "FIN DE FONCTION " << endl;
    cout << "\tDEPTH : " << niveau << endl;
    cout << "\tavec :: " << endl << endl;
    cout << "\tVALEUR candidats : {";
    for (auto val : p_candidatsClique)
        cout << val+1 << " ";
    cout << "}" << endl;

    cout << "\tVALEUR clique : {";
    for (auto val : r_potentielleClique)
        cout << val+1 << " ";
    cout << "}" << endl;

    cout << "\tVALEUR traites : {";
    for (auto val : x_sommetsTraites)
        cout << val+1 << " ";
    cout << "}" << endl;
}
*/

bool Graphe::estAreteDansGraphe(int sommet1, int sommet2)
{
    bool areteExiste;
    set<int> listeADJ;

    areteExiste = false;
    listeADJ = sommets[sommet1].getListeAdj();

    if(listeADJ.find(sommet2) != listeADJ.end())
    {
        areteExiste = true;
    }
    return areteExiste;
}


Graphe Graphe::sousGrapheGi(int sommet)
{
    set<int> voisinsN1, voisinsN2, listeSommetsGraphe;
    Graphe gi(false);

    voisinsN1 = sommets[sommet].getListeAdj();
    voisinsN2 = distanceDeuxDuSommet(sommet);

    listeSommetsGraphe.insert(sommet);
    set_union(voisinsN1.begin(), voisinsN1.end(),
                voisinsN2.begin(), voisinsN2.end(),
                inserter(listeSommetsGraphe,listeSommetsGraphe.begin()));

    for(int s : listeSommetsGraphe)
    {
        gi.ajouterSommet(s);
    }
/*
    for(int x : voisinsN1){
        for(int y1 : voisinsN1)
        {
            if (x != y1)
            {
                if(estAreteDansGraphe(x,y1))
                {
                    gi.ajouterArete(x,y1);
                }
            }
        }
        for(int y2 : voisinsN2)
        {
            if (x != y2)
            {
                if(!estAreteDansGraphe(x,y2))
                {
                    gi.ajouterArete(x,y2);
                }
            }
        }
    }*/
    for(int x : voisinsN2){
        for(int y : voisinsN2)
        {
            if (x != y)
            {
                if(estAreteDansGraphe(x,y))
                {
                    gi.ajouterArete(x,y);
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

