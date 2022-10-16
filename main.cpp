#include <iostream>
#include <vector>

//#include "src/histogram.hpp"
#include "src/graphe.hpp"
#include "src/sommet.hpp"
#include "src/LectureEcriture.hpp"
#include "src/statistique.hpp"


int main()
{

    Graphe g(true, 12);
    // cout << g.print();
    // g.ajouterArete(0, 1);
    // cout << g.print();
    // g.ajouterArc(0, 2);


    g.genererArcsAleatoires(0.25);
    // cout << g.print();
    std::vector<int> degres = g.calculerDegres();
    // std::cout << g.getNbSommet() << std::endl;
    //dessinerHistogrammeDegres(g.getNbSommet(), degres, "degrés");// Pour tester décommenter "#include "src/histogram.hpp"" et cette ligne

    
    Graphe graphe(true, 3);
    graphe.ajouterArete(0, 1);
    //graphe.ajouterArc(0, 2);
    //graphe.ajouterArc(2, 0);
    graphe.ajouterArete(0,2);
    cout << graphe.print();
    compteCheminDistanceDeux(graphe);
    compteCheminDistanceDeux(g);
    
    
    // ecriture(g);
    // lecture ();
    //Mon test
    //string fichier("./fichiers/facebook_combined.txt");
    //string fichier("./fichiers/lastfm_asia_target.csv");
    //string fichier("./fichiers/graphe1.txt");
    //lecture(fichier);

    return 0;
}
