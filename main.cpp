#include <iostream>
#include <vector>

//#include "src/histogram.hpp"
#include "src/graphe.hpp"
#include "src/sommet.hpp"
#include "src/LectureEcriture.hpp"
using namespace std;

set<int> test(set<int>& set_1, set<int>& set_2)
{
    set<int> ret;
    set_intersection(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(), 
                     std::inserter(ret, ret.begin()));

    return ret;
}

int main()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 1 ere partie /////////////////////////////////////////////////////////////////

    cout << "////////////////////////////////////////////////////////////////////////" << endl;
    cout << "///////////////////////// 1ère partie /////////////////////////////////" << endl << endl;
    /////////////////////// Initialistations des graphes //////////////////////////
/*
    cout << "///////////////////// Initialisation des graphes ////////////////////" << endl << endl;
    /// Lecture des fichiers de la base de données de Stanford
        // A executer qu'une fois ou pour reinitialiser

    string fichierFacebook, fichierEmailEu, fichierLastFmAsia;

    fichierFacebook = "./fichiers/facebook_combined.txt";
    fichierEmailEu = "./fichiers/email-Eu-core.txt";
    fichierLastFmAsia = "./fichiers/lastfm_asia_edges.csv";

    Graphe grapheFacebook = lectureFichierBDD(fichierFacebook,' ', false);
    cout << "\tCopie du graphe dans un autre fichier"<< endl;
    ecriture(grapheFacebook);

    Graphe grapheEmailEu = lectureFichierBDD(fichierEmailEu,' ', false);
    cout << "\tCopie du graphe dans un autre fichier"<< endl;
    ecriture(grapheEmailEu); 

    Graphe grapheLastFM = lectureFichierBDD(fichierLastFmAsia,',', true);
    cout << "\tCopie du graphe dans un autre fichier"<< endl;
    ecriture(grapheLastFM);

    /// Graphes Aleatoires
        // A executer qu'une fois ou pour reinitialiser

    int nbSommet, estOriente;

    /// Premier graphe
    cout << "Premier graphe Aleatoire " << endl;
    cout << "\tEntrez le nombre de sommets de votre graphe : " << endl;
    cin >> nbSommet; 

    cout << "\tVotre graphe est il orienté ? " << endl << "\tTapez 0 pour non ou 1 pour oui" << endl;
    cin >> estOriente;

    Graphe grapheAleatoire1 (estOriente, nbSommet);
    grapheAleatoire1.genererArcsAleatoires();
    ecriture(grapheAleatoire1);

    /// Deuxieme graphe
    cout << "Deuxieme graphe Aleatoire " << endl;
    cout << "\tEntrez le nombre de sommets de votre graphe : " << endl;
    cin >> nbSommet; 

    cout << "\tVotre graphe est il orienté ? " << endl << "\tTapez 0 pour non ou 1 pour oui" << endl;
    cin >> estOriente;

    Graphe grapheAleatoire2 (estOriente, nbSommet);
    grapheAleatoire2.genererArcsAleatoires();
    ecriture(grapheAleatoire2);
*/

    //////////////////////////// Lecture des graphes deja enregistres //////////////////////

    cout << "//////////////// Lecture des graphes déjà enregistrés /////////////////" << endl << endl;
    Graphe grapheFacebook = lecture("copie_graphe_facebook.txt");
    Graphe grapheEmailEu = lecture("copie_graphe_email_eu.txt");
    Graphe grapheLastFM = lecture("copie_graphe_lastfm_asia.txt");
    Graphe grapheAleatoire1 = lecture("graphe_aleatoire_1.txt");
    Graphe grapheAleatoire2 = lecture("graphe_aleatoire_2.txt");


    /////////////////////////// Données sur les graphes ////////////////////////////////////

    /// Degre Max
    
    cout << "//////////////// Degré maximum des graphes /////////////////" << endl << endl;
    cout << "\tLe degré maximum du graphe Facebook est : " << grapheFacebook.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Email EU est : " << grapheEmailEu.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Lastfm est : " << grapheLastFM.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Aleatoire 1 est : " << grapheAleatoire1.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Aleatoire 2 est : " << grapheAleatoire2.calculerDegreMax() << endl << endl;


    /// Graphique des degres
/*
    dessinerHistogrammeDegres(grapheFacebook.getNbSommet(), grapheFacebook.calculerDegres(), "degrés Facebook");
    dessinerHistogrammeDegres(grapheEmailEu.getNbSommet(), grapheEmailEu.calculerDegres(), "degrés Email EU" );
    dessinerHistogrammeDegres(grapheLastFM.getNbSommet(), grapheLastFM.calculerDegres(), "degrés LastFM");
    dessinerHistogrammeDegres(grapheAleatoire1.getNbSommet(), grapheAleatoire1.calculerDegres(), "degrés Aleatoire 1");
    dessinerHistogrammeDegres(grapheAleatoire2.getNbSommet(), grapheAleatoire2.calculerDegres(), "degrés Aleatoire 2");


    /// Nombre de chemins de longueur 2

    cout << "//////////////// Nombre de chemin de longueur 2 /////////////////" << endl << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Facebook est : " << grapheFacebook.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Email EU est : " << grapheEmailEu.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Lastfm est : " << grapheLastFM.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 1 est : " << grapheAleatoire1.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 2 est : " << grapheAleatoire2.compteCheminDistanceDeux() << endl << endl;
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 2 eme partie /////////////////////////////////////////////////////////////////

    vector<set<int>> cliquesMaxPetitGraphe, cliquesMaxGrapheAleatoire;
    cout << "////////////////////////////////////////////////////////////////////////" << endl;
    cout << "///////////////////////// 2ème partie /////////////////////////////////" << endl << endl;

    Graphe petitGraphe(false, 6);
    petitGraphe.ajouterArete(0,1);
    petitGraphe.ajouterArete(0,2);
    petitGraphe.ajouterArete(0,4);
    petitGraphe.ajouterArete(1,2);
    petitGraphe.ajouterArete(1,3);
    petitGraphe.ajouterArete(1,5);
    petitGraphe.ajouterArete(2,3);
    petitGraphe.ajouterArete(2,5);
    petitGraphe.ajouterArete(3,4);
    petitGraphe.ajouterArete(3,5);
    //petitGraphe.ajouterArete(0,1);
    //petitGraphe.ajouterArete(0,2);
    //petitGraphe.ajouterArete(1,2);
    //petitGraphe.ajouterArete(1,3);

    cout << "Petit graphe :" << endl;
    cout << petitGraphe.print() << endl << endl;

    cout << "/////////////////////// Cliques Maximales /////////////////////////////" << endl << endl;
    cout << "\tExemple sur le petit graphe " << endl;

    cliquesMaxPetitGraphe = petitGraphe.cliqueMaximaleBronKerbosch();

    cout << "\tCliques maximales : " << endl;
    for (auto clique : cliquesMaxPetitGraphe)
    {
        cout << "\t";
        for (int i : clique)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl << "\tExemple sur un graphe aléatoire " << endl;
    cliquesMaxGrapheAleatoire = grapheAleatoire1.cliqueMaximaleBronKerbosch();

    cout << "\tCliques maximales : " << endl;
    for (auto clique : cliquesMaxGrapheAleatoire)
    {
        cout << "\t";
        for (int i : clique)
        {
            cout << i << " ";
        }
        cout << endl;
    }












/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 3 eme partie /////////////////////////////////////////////////////////////////








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// Fin //////////////////////////////////////////////////////////////////////

/*
    Graphe petitGraphe(false, 4);
    petitGraphe.ajouterArete(0,1);
    petitGraphe.ajouterArete(0,2);
    petitGraphe.ajouterArete(1,2);
    petitGraphe.ajouterArete(1,3);

    Graphe g(false, 6);
    g.ajouterArete(0,1);
    g.ajouterArete(0,2);
    g.ajouterArete(0,4);
    g.ajouterArete(1,2);
    g.ajouterArete(1,3);
    g.ajouterArete(1,5);
    g.ajouterArete(2,3);
    g.ajouterArete(2,5);
    g.ajouterArete(3,4);
    g.ajouterArete(3,5);

    // for (auto som : g.getSommets())
    // {
    //     cout << som.print() << endl;
    // }

    vector<set<int>> cliquesMax = g.cliqueMaximaleBronKerbosch();
    cout << "RESULTAT :: " << endl;
    for (auto clique : cliquesMax)
    {
        for (int i : clique)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
*/
    // set<int> i, aut, set_1, set_2;
    // i.insert(35);  
    // i.insert(36);  
    // i.insert(37);  
    // i.insert(38);  
    // // i.insert(39);  
    // // aut = i;
    // aut.insert(340);  
    // aut.insert(32);  
    // aut.insert(35);  
    // aut.insert(38);  
    // aut.insert(8);  
    // aut.insert(3);  
    // i.insert(3);  
    // set_1 = test(i, aut);
    // set_2 = test(aut, i);
    // for(auto x :set_1)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    // for(auto x :set_2)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    return 0;
}