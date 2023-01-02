#include "graphe.hpp"
#include <unistd.h>

using namespace std;

/**
 * @brief Construct a new Graphe:: Graphe object
 * 
 * @param oriente true si le graphe est oriente sinon false
 */
Graphe::Graphe(){};

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

/**
 * @brief Genere aleatoirement les arcs du graphe 
 * 
 */
void Graphe::genererArcsAleatoires()
{
    // calcul de la probabilite pour generer un arc 
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
                if(estOriente)// si le graphe est oriente on ajoute un arc
                {
                    ajouterArc(i, j);
                }
                else // s il est non oriente on ajoute une arete
                {
                    ajouterArete(i,j);
                }
            }
        }
        // On ne peut pas une boucle sur un sommet (on saute le sommet i)
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

/**
 * @brief Ajoute un sommet au graphe
 * 
 * @param num le numero du sommet a ajouter
 * @return true le sommet a bien etait ajoute
 * @return false le sommet n a pas ete correctement ajoute
 */
bool Graphe::ajouterSommet(int num)
{
    Sommet s(num);
    sommets[num] = s;
    nbSommet++;

    return true;
}

/**
 * @brief Ajoute un arc au graphe entre 2 sommets
 * 
 * @param sourceNum un sommet du graphe, le sommet source de l arc
 * @param destinationNum un sommet du graphe, le sommet destinnation de l arc 
 */
void Graphe::ajouterArc(int sourceNum, int destinationNum)
{
    sommets[sourceNum].ajouterVoisin(destinationNum);
    nbArcs+=  1;
}

/**
 * @brief Ajoute 2 arcs (1 arete) au graphe entre 2 sommets
 * 
 * @param s1Num un sommet extremite de l arete
 * @param s2Num un sommet extremite de l arete
 */
void Graphe::ajouterArete(int s1Num, int s2Num)
{
    ajouterArc(s1Num, s2Num);
    ajouterArc(s2Num, s1Num);
}

/*
    Affichage
*/

/**
 * @brief Retourne un string contenant l affichage du graphe
 * 
 * @return string contient les affichages des sommets et les donnees sur le graphe
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

/**
 * @brief Verifie si une arete existe dans le graphe (non oriente)
 * 
 * @param sommet1 sommet extremite de l arete
 * @param sommet2 sommet extremite de l arete
 * @return true l arete entre le sommet1 et sommet2 existe dans le graphe
 * @return false l arete n existe pas
 */
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

/**
 * @brief Retourne tous les degres existants du graphe
 * 
 * @return vector<int> les degres du graphe
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

/**
 * @brief Retourne le degre maximal du graphe
 * 
 * @return int le degre maximal du graphe
 */
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

/**
 * @brief Compte le nombre de chemins de longueur 2
 * 
 * @return int le nombre de chemins de longueur 2
 */
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

/**
 * @brief Retourne les sommets a distance 2 du sommet donne en parametre
 * Pour cela :
 * on considere 3 sommets pour un chemin de longueur 2 :
 *       - le sommet source (sommet de depart)
 *       - le sommet du milieu
 *       - le sommet d arrivee
 *       Pour trouver les sommets d arrivee :
 *       1. on stocke la liste d adjacence du sommet de depart
 *       2. on parcours les voisins du sommet de depart
 *       3. on recupere la liste d adjacence de chacun (sommet du milieu)
 *       4. on soustrait a la liste d adjacence du sommet du milieu celle du sommet de depart 
 *       5. on stocke la liste des sommets restants dans la listes des sommets d arrivee
 *       6. on verifie que le sommet de depart n est pas dans cette liste si c est le cas on l enleve
 *
 * @param sommet Le sommet source des chemins de longueur 2
 * @return vector<int> Les sommets a distance 2 du sommet source
 */
vector<int> Graphe::distanceDeuxDuSommet(int sommet)
{
    set<int> listeAdjSomDepart, listeAdjSomMilieu;
    vector<int>listeSommetsArrivee;
    Sommet sommetCourant;

    sommetCourant = getSommet(sommet);
    listeAdjSomDepart = sommetCourant.getListeAdj(); //Etape 1
    listeAdjSomDepart.insert(sommet); //Etape 6 (permet d enlever le sommet des le depart)

    for(int voisinCourant : listeAdjSomDepart) //Etape 2
    {
        listeAdjSomMilieu = getSommet(voisinCourant).getListeAdj(); //Etape 3
                            
        set_difference(listeAdjSomMilieu.begin(), listeAdjSomMilieu.end(),
                        listeAdjSomDepart.begin(),listeAdjSomDepart.end(),
                        inserter(listeSommetsArrivee, listeSommetsArrivee.begin())); //Etape 4 et 5
    }    
    return listeSommetsArrivee;
}

/**
 * @brief Retourne les cliques maximales du graphe grace a l algoritme de Bron Kerbosch avec pivot
 * 
 * @return vector<set<int>> les cliques maximales du graphe
 */
vector<set<int>> Graphe::cliqueMaximaleBronKerbosch()
{
    set<int>potentielleClique, sommetsTraites, candidatsClique, cliqueMax;
    vector<set<int>> cliqueMaxMarquees;

    // P (candidats) = tous les sommets du graphe
    map<int, Sommet>::iterator itr;
    for(itr = sommets.begin(); itr != sommets.end(); itr++)    {
        candidatsClique.insert(itr->first);
    }
    algoBronKerboschPivot(potentielleClique,candidatsClique,sommetsTraites, cliqueMaxMarquees);

    return cliqueMaxMarquees;
}

/**
 * @brief Application de l algorithme de Bron Kerbosch avec pivot
 * BronKerbosch(R,P,X):
 *    if P and X are both empty:
 *        report R as a maximal clique
 *    choose a pivot vertex u in P ⋃ X
 *    for each vertex v in P \ N(u):
 *        BronKerbosch(R ⋃ {v}, P ⋂ N(v), X ⋂ N(v))
 *        P := P \ {v}
 *        X := X ⋃ {v}
 * source : https://iq.opengenus.org/bron-kerbosch-algorithm/
 * 
 * @param r_potentielleClique clique potentielle
 * @param p_candidatsClique sommets candiadats pour la clique
 * @param x_sommetsTraites sommets deja traites
 * @param cliqueMaxMarquees Pointeur des cliques maximales du graphe
 */
void Graphe::algoBronKerboschPivot(set<int> r_potentielleClique, set<int> p_candidatsClique, set<int> x_sommetsTraites, vector<set<int>>& cliqueMaxMarquees)
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
        algoBronKerboschPivot(std::move(r_interV), std::move(pInterVoisinV), std::move(xInterVoisinV), cliqueMaxMarquees);
        
        // P = P \ v
        p_candidatsClique.erase(v);

        // X = X U v
        x_sommetsTraites.insert(v);
    }
}

/**
 * @brief Retourne le graphe complementaire du graphe
 * 
 * @return Graphe le graphe complementaire
 */
Graphe Graphe::complementaireGraphe()
{
    Graphe retGraphe(false); // graphe complementaire
    
    retGraphe.getSommets() = sommets;
    Sommet s1;
    int s2;
    map<int, Sommet>::iterator itr;
    for(itr = sommets.begin(); itr != sommets.end(); itr++)
    {
        retGraphe.getSommets()[itr ->first].getListeAdj().clear(); 
        s1 = itr ->second;
        map<int, Sommet>::iterator itr2;
        for(itr2 = sommets.begin(); itr2 != sommets.end(); itr2++)
        {
            s2 = itr2 ->first;
            if(s2 != s1.getNum() && !estAreteDansGraphe(s1.getNum(), s2)) // si les deux sommets de l arete sont differents ET que l arrete ne est pas dans le graphe 
                retGraphe.getSommets()[s1.getNum()].ajouterVoisin(s2); // on ajoute cette arete au graphe complementaire
            else
            {
                // do nothing
            }
        }
    }
    return retGraphe;
}

/**
 * @brief Retourne un sous graphe gi du graphe qui suit la construction suivante :
 * Graph Gi, i ∈ [n], is the graph with vertex set {vi} ∪ Ni(vi) ∪ N2i (vi) and edges:
 *   1. xy ∈ Gi, if x ∈ Ni(vi), y ∈ Ni(vi) and xy ∈ E
 *   2. xy ∈ Gi, if x ∈ N2i (vi), y ∈ N2i (vi) and xy ∈ E
 *   3. xy ∈ Gi, if x ∈ Ni(vi), y ∈ N2i (vi) and xy /∈ E.
 * source : Hermelin, Manoussakis. “Efficient enumeration of maximal induced bicliques,” Discrete Applied Mathematics,2021.
 * @param sommet le sommet i dans la definition precedente
 * @return Graphe le sous graphe genere 
 */
Graphe Graphe::sousGrapheGi(int sommet)
{
    vector<int> voisinsD2Tmp;
    // liste des voisins a distance 1 (respectivement 2) du sommet donne en parametre
    set<int> voisinsD1, voisinsD2;
    //listes des sommets du sous graphe
    set<int> listeSommetsGraphe;
    //liste des sommets superieur et egal au sommet donnee en parametre (les sommets du graphe etant ordonnes)
    set<int> listeVi;
    //liste des sommets dans Vi ET dans VoisinsD1 (repectivement voisinsD2)
    set<int> listeN1, listeN2;
    //sous graphe que l on retourne 
    Graphe gi(false);
    
    map<int, Sommet>::iterator itr;
    for(itr = sommets.lower_bound(sommet); itr != sommets.end(); itr++)
    {
        listeVi.insert(itr ->first);
    }
    
    voisinsD1 = sommets[sommet].getListeAdj();
    voisinsD2Tmp = distanceDeuxDuSommet(sommet);

    //conversion vector vers set
    for(int v : voisinsD2Tmp)
    {
        voisinsD2.insert(v);
    }
    // Construction de listeN1
    set_intersection(listeVi.begin(), listeVi.end(),
                    voisinsD1.begin(), voisinsD1.end(),
                    inserter(listeN1,listeN1.begin()));
    // Construction de la listeN2
    set_intersection(listeVi.begin(), listeVi.end(),
                    voisinsD2.begin(), voisinsD2.end(),
                    inserter(listeN2,listeN2.begin()));

    // Construction des sommets du sous graphe
    listeSommetsGraphe.insert(sommet);
    set_union(listeN1.begin(), listeN1.end(),
                listeN2.begin(), listeN2.end(),
                inserter(listeSommetsGraphe,listeSommetsGraphe.begin()));
    for(int s : listeSommetsGraphe)
    {
        gi.ajouterSommet(s);
    }

    // AJout des arete dans le sous graphe 
    for( int x : listeSommetsGraphe)
    {
        for(int y : listeSommetsGraphe)
        {
            if(x != y) // deux sommets differents (pas de boucle)
            {
                if (estAreteDansGraphe(x,y))
                {
                    if(listeN1.find(x) != listeN1.end() && listeN1.find(y) != listeN1.end()) // condition 1
                    {
                        gi.ajouterArete(x,y);   
                    }
                    else if(listeN2.find(x) != listeN2.end() && listeN2.find(y) != listeN2.end()) // condition 2
                    {
                        gi.ajouterArete(x,y);
                    }
                }
                else 
                {
                    if(listeN1.find(x) != listeN1.end() && listeN2.find(y) != listeN2.end()) // condition 3
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

/**
 * @brief Retourne le nombre de sommets du graphe
 * 
 * @return int le nombre de sommets du graphe
 */
int Graphe::getNbSommet()
{
    return nbSommet;
}

/**
 * @brief Retourne un booleen representant si le graphe est oriente ou non
 * 
 * @return true le graphe est oriente
 * @return false le graphe est non oriente
 */
bool Graphe::getEstOriente()
{
    return estOriente;
}

 /**
  * @brief Retourne le nombre d arcs du graphe
  * 
  * @return * int le nombre d arcs du graphe
  */
int Graphe::getNbArcs()
{
    return nbArcs;
}

/**
 * @brief Retourne tous les sommets du graphes
 * 
 * @return map<int,Sommet>& Les sommets du graphe 
 */
map<int,Sommet>& Graphe::getSommets()
{
    return sommets;
}

/**
 * @brief Retourne un sommet du graphe
 * 
 * @param num le numero du sommet a retourner
 * @return Sommet& le sommet du graphe 
 */
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
