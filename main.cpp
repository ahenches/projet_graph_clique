#include <iostream>
#include <vector>

// #include "src/histogram.hpp"
#include "src/graphe.hpp"
#include "src/sommet.hpp"
#include "src/LectureEcriture.hpp"
using namespace std;

int main()
{
    string fichierFacebook, fichierEmailEu, fichierLastFmAsia;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 1 ere partie /////////////////////////////////////////////////////////////////
/*
    /// Lecture des fichiers de la base de données de Stanford
        // A executer qu'une fois ou pour reinitialiser

    int nbSommet, estOriente;

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
    /// Lecture des graphes deja enregistres
    Graphe grapheFacebook = lecture("copie_graphe_facebook.txt");
    Graphe grapheEmailEu = lecture("copie_graphe_email_eu.txt");
    Graphe grapheLastFM = lecture("copie_graphe_lastfm_asia.txt");
    Graphe grapheAleatoire1 = lecture("graphe_aleatoire_1.txt");
    Graphe grapheAleatoire2 = lecture("graphe_aleatoire_2.txt");






















//    Graphe g(true, 12000);
    // cout << g.print();
    // g.ajouterArete(0, 1);
    // cout << g.print();
    // g.ajouterArc(0, 2);


    //g.genererArcsAleatoires(0.25);
     //cout << g.print();
    //std::vector<int> degres = g.calculerDegres();
    // std::cout << g.getNbSommet() << std::endl;
    // dessinerHistogrammeDegres(g.getNbSommet(), degres, "degrés");// Pour tester décommenter "#include "src/histogram.hpp"" et cette ligne

    
   /* Graphe graphe(true, 3);
    graphe.ajouterArete(0, 1);
    graphe.ajouterArete(0,2);
    graphe.ajouterArc(1,2);
    cout << graphe.print();*/
    //compteCheminDistanceDeux(g);
   // compteCheminDistanceDeux(g);
    
    
    // ecriture(g);
    // lecture ();
    //Mon test
   // string fichier("./fichiers/facebook_combined.txt");
    //string fichier("./fichiers/email-Eu-core.txt");
    /*string fichier("./fichiers/lastfm_asia_edges.csv");
    //string fichier("./fichiers/graphe1.txt");
    Graphe g1 = lectureFichierBDD(fichier,',', true);
    cout << g1.nbArcs << endl;
    ecriture(g1);
*/
    return 0;
}