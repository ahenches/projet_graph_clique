#include <iostream>
#include <vector>

//#include "src/histogram.hpp"
#include "src/graphe.hpp"
#include "src/sommet.hpp"
#include "src/LectureEcriture.hpp"
using namespace std;

int main()
{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 1 ere partie /////////////////////////////////////////////////////////////////

    /////////////////////// Initialistations des graphes //////////////////////////
/*
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
  /*  
    Graphe grapheFacebook = lecture("copie_graphe_facebook.txt");
    Graphe grapheEmailEu = lecture("copie_graphe_email_eu.txt");
    Graphe grapheLastFM = lecture("copie_graphe_lastfm_asia.txt");
    Graphe grapheAleatoire1 = lecture("graphe_aleatoire_1.txt");
    Graphe grapheAleatoire2 = lecture("graphe_aleatoire_2.txt");


    /////////////////////////// Données sur les graphes ////////////////////////////////////

    /// Degre Max
    
    cout << "Le degré maximum du graphe Facebook est : " << grapheFacebook.calculerDegreMax() << endl;
    cout << "Le degré maximum du graphe Email EU est : " << grapheEmailEu.calculerDegreMax() << endl;
    cout << "Le degré maximum du graphe Lastfm est : " << grapheLastFM.calculerDegreMax() << endl;
    cout << "Le degré maximum du graphe Aleatoire 1 est : " << grapheAleatoire1.calculerDegreMax() << endl;
    cout << "Le degré maximum du graphe Aleatoire 2 est : " << grapheAleatoire2.calculerDegreMax() << endl << endl;


    /// Graphique des degres

    dessinerHistogrammeDegres(grapheFacebook.getNbSommet(), grapheFacebook.calculerDegres(), "degrés Facebook");
    dessinerHistogrammeDegres(grapheEmailEu.getNbSommet(), grapheEmailEu.calculerDegres(), "degrés Email EU" );
    dessinerHistogrammeDegres(grapheLastFM.getNbSommet(), grapheLastFM.calculerDegres(), "degrés LastFM");
    dessinerHistogrammeDegres(grapheAleatoire1.getNbSommet(), grapheAleatoire1.calculerDegres(), "degrés Aleatoire 1");
    dessinerHistogrammeDegres(grapheAleatoire2.getNbSommet(), grapheAleatoire2.calculerDegres(), "degrés Aleatoire 2");


    /// Nombre de chemins de longueur 2

    cout << "Le nombre de chemin de longueur 2 du graphe Facebook est : " << grapheFacebook.compteCheminDistanceDeux() << endl;
    cout << "Le nombre de chemin de longueur 2 du graphe Email EU est : " << grapheEmailEu.compteCheminDistanceDeux() << endl;
    cout << "Le nombre de chemin de longueur 2 du graphe Lastfm est : " << grapheLastFM.compteCheminDistanceDeux() << endl;
    cout << "Le nombre de chemin de longueur 2 du graphe Aleatoire 1 est : " << grapheAleatoire1.compteCheminDistanceDeux() << endl;
    cout << "Le nombre de chemin de longueur 2 du graphe Aleatoire 2 est : " << grapheAleatoire2.compteCheminDistanceDeux() << endl << endl;
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 2 eme partie /////////////////////////////////////////////////////////////////












/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 3 eme partie /////////////////////////////////////////////////////////////////








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// Fin //////////////////////////////////////////////////////////////////////


    Graphe g(false, 4);
    g.ajouterArete(0,1);
    g.ajouterArete(0,2);
    g.ajouterArete(1,2);
    g.ajouterArete(1,2);
    g.ajouterArete(2,3);

    set<int> clique = g.cliqueMaximaleBronKerbosch();

    for (int i : clique )
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}