#include <iostream>
#include <vector>

#include "src/histogram.hpp"
#include "src/graphe.hpp"
#include "src/sommet.hpp"
#include "src/LectureEcriture.hpp"
using namespace std;

// set<int> test(set<int>& set_1, set<int>& set_2)
// {
//     set<int> ret;
//     set_intersection(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(), 
//                      std::inserter(ret, ret.begin()));

//     return ret;
// }

int main()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 1 ere partie /////////////////////////////////////////////////////////////////

    cout << "////////////////////////////////////////////////////////////////////////" << endl;
    cout << "///////////////////////// 1ère partie /////////////////////////////////" << endl << endl;
    
    /////////////////////// Initialistations des graphes //////////////////////////

    cout << "///////////////////// Initialisation des graphes ////////////////////" << endl << endl;
   
    /// Lecture des fichiers de la base de données de Stanford

    string fichierFacebook, fichierEmailEu, fichierLastFmAsia;

    fichierFacebook = "./fichiers/facebook_combined.txt";
    fichierEmailEu = "./fichiers/email-Eu-core.txt";
    fichierLastFmAsia = "./fichiers/lastfm_asia_edges.csv";

    Graphe grapheFacebook = lectureFichierBDD(fichierFacebook,' ', false, NB_SOMMET_FACEBOOK, NON_ORIENTE);
    cout << "\tCopie du graphe Facebook dans un autre fichier"<< endl;
    ecriture(grapheFacebook, "copie_graphe_facebook");

    Graphe grapheEmailEu = lectureFichierBDD(fichierEmailEu,' ', false, NB_SOMMET_EMAIL_EU, ORIENTE);
    cout << "\tCopie du graphe Email EU dans un autre fichier"<< endl;
    ecriture(grapheEmailEu, "copie_graphe_email_eu"); 

    Graphe grapheLastFM = lectureFichierBDD(fichierLastFmAsia,',', true,NB_SOMMET_LASTFM, NON_ORIENTE);
    cout << "\tCopie du graphe Last FM dans un autre fichier"<< endl;
    ecriture(grapheLastFM, "copie_graphe_lastfm_asia");

    /// Graphes Aleatoires

    /// Premier graphe
    cout << "Premier graphe Aleatoire " << endl;
    Graphe grapheAleatoire1 (ORIENTE, NB_SOMMET_ALEA_1);
    grapheAleatoire1.genererArcsAleatoires();
    ecriture(grapheAleatoire1, "graphe_aleatoire_1");

    /// Deuxieme graphe
    cout << "Deuxieme graphe Aleatoire " << endl;
    Graphe grapheAleatoire2 (NON_ORIENTE, NB_SOMMET_ALEA_2);
    grapheAleatoire2.genererArcsAleatoires();
    ecriture(grapheAleatoire2,"graphe_aleatoire_2");

    /// Troisieme graphe
    cout << "Troisieme graphe Aleatoire " << endl;
    Graphe grapheAleatoire3 (NON_ORIENTE, NB_SOMMET_ALEA_3);
    grapheAleatoire3.genererArcsAleatoires();
    ecriture(grapheAleatoire3, "graphe_aleatoire_3");

    //////////////////////////// Lecture des graphes deja enregistres //////////////////////
/* 
    cout << "//////////////// Lecture des graphes déjà enregistrés /////////////////" << endl << endl;
    Graphe grapheFacebook = lecture("copie_graphe_facebook.txt");
    Graphe grapheEmailEu = lecture("copie_graphe_email_eu.txt");
    Graphe grapheLastFM = lecture("copie_graphe_lastfm_asia.txt");
    Graphe grapheAleatoire1 = lecture("graphe_aleatoire_1.txt");
    Graphe grapheAleatoire2 = lecture("graphe_aleatoire_2.txt");
    Graphe grapheAleatoire3 = lecture("graphe_aleatoire_3.txt");
 */

    /////////////////////////// Données sur les graphes ////////////////////////////////////

    /// Degre Max
    
    cout << "//////////////// Degré maximum des graphes /////////////////" << endl << endl;
    cout << "\tLe degré maximum du graphe Facebook est : " << grapheFacebook.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Email EU est : " << grapheEmailEu.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Lastfm est : " << grapheLastFM.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Aleatoire 1 est : " << grapheAleatoire1.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Aleatoire 2 est : " << grapheAleatoire2.calculerDegreMax() << endl;
    cout << "\tLe degré maximum du graphe Aleatoire 3 est : " << grapheAleatoire3.calculerDegreMax() << endl << endl;


    /// Graphique des degres
/* 
    dessinerHistogrammeDegres(grapheFacebook.getNbSommet(), grapheFacebook.calculerDegres(), "degrés Facebook");
    dessinerHistogrammeDegres(grapheEmailEu.getNbSommet(), grapheEmailEu.calculerDegres(), "degrés Email EU" );
    dessinerHistogrammeDegres(grapheLastFM.getNbSommet(), grapheLastFM.calculerDegres(), "degrés LastFM");
    dessinerHistogrammeDegres(grapheAleatoire1.getNbSommet(), grapheAleatoire1.calculerDegres(), "degrés Aleatoire 1");
    dessinerHistogrammeDegres(grapheAleatoire2.getNbSommet(), grapheAleatoire2.calculerDegres(), "degrés Aleatoire 2");
    dessinerHistogrammeDegres(grapheAleatoire3.getNbSommet(), grapheAleatoire3.calculerDegres(), "degrés Aleatoire 3");


    /// Nombre de chemins de longueur 2

    cout << "//////////////// Nombre de chemin de longueur 2 /////////////////" << endl << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Facebook est : " << grapheFacebook.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Email EU est : " << grapheEmailEu.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Lastfm est : " << grapheLastFM.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 1 est : " << grapheAleatoire1.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 2 est : " << grapheAleatoire2.compteCheminDistanceDeux() << endl;
    cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 3 est : " << grapheAleatoire3.compteCheminDistanceDeux() << endl << endl;
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 2 eme partie /////////////////////////////////////////////////////////////////
/* 
    cout << "////////////////////////////////////////////////////////////////////////" << endl;
    cout << "///////////////////////// 2ème partie /////////////////////////////////" << endl << endl;

    Graphe petitGraphe(false, 8);
    petitGraphe.genererArcsAleatoires();

    cout << "Petit graphe :" << endl;
    cout << petitGraphe.print() << endl << endl;

    /// Cliques Maximales
    
    vector<set<int>> cliquesMaxPetitGraphe, cliquesMaxGrapheAleatoire;

    cout << "/////////////////////// Cliques Maximales /////////////////////////////" << endl << endl;
    
    /// Exemple sur le premier graphe
    cout << "\tExemple sur le petit graphe " << endl;
    cout << "\tCliques maximales : " << endl;
    cliquesMaxPetitGraphe = petitGraphe.cliqueMaximaleBronKerbosch();
    
    /// Affichage des cliques
    for (auto clique : cliquesMaxPetitGraphe)
    {
        cout << "\t";
        for (int i : clique)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl << "\tIl y a "<< cliquesMaxPetitGraphe.size() << " cliques maximales" << endl << endl;
    
    /// Exemple sur le deuxième graphe 
    cout << endl << "\tExemple sur un graphe aléatoire " << endl;
    cout << "\tCliques maximales : " << endl;
    cliquesMaxGrapheAleatoire = grapheAleatoire3.cliqueMaximaleBronKerbosch();
    
    /// Affichage des cliques 
    for (auto clique : cliquesMaxGrapheAleatoire)
    {
        cout << "\t[ ";
        for (int i : clique)
        {
            cout << i << " ";
        }
        cout << "]"<< endl;
    }
    cout << endl <<"\tIl y a "<< cliquesMaxGrapheAleatoire.size() << " cliques maximales" << endl << endl;
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 3 eme partie /////////////////////////////////////////////////////////////////
/* 
    cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "////////////////////////////////////////////// 3ème partie //////////////////////////////////////////////" << endl << endl;

    cout << "/////////////////////////// Ensemble indépendant Maximal /////////////////////////////" << endl << endl;

    vector<set<int>> cliquesMax;
    map<int, Sommet>::iterator itr;
    for(itr = petitGraphe.getSommets().begin(); itr != petitGraphe.getSommets().end(); itr++)
    {
        Graphe gi = petitGraphe.sousGrapheGi(itr->first);
        cout << "Graphe G"<<itr->first << endl;
        cout << gi.print() <<endl;

        Graphe complementaireGi = gi.complementaireGraphe();
        cout << "Complementaire graphe G"<<itr->first << endl;
        cout << complementaireGi.print() <<endl;

        cout << "Ensemble independant maximal de G" << itr->first <<" : " << endl;
        cliquesMax = complementaireGi.cliqueMaximaleBronKerbosch();
        for (auto clique : cliquesMax)
        {
            cout << "\t[ ";
            for (int i : clique)
            {
                cout << i << " ";
            }
            cout << "]"<< endl;
        }
        cout << endl<< "//////////////////////////////////////////////////////////" << endl;
    }

 */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// Fin ///////////////////////////////////////////////////////////////////////
    return 0;
}