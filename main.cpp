# include <iostream>

# include "./src/graphe.hpp"
# include "./src/sommet.hpp"
#include "./src/LectureEcriture.hpp"

using namespace std;

int main()
{
    
    Graphe g(true, 3);
    cout << g.print();
    g.ajouterArete(0, 1);
    cout << g.print();
    g.ajouterArc(0, 2);
    cout << g.print();
    
    ecriture(g);
    lecture ();
    //Mon test
    //string fichier("./fichiers/facebook_combined.txt");
    //string fichier("./fichiers/lastfm_asia_target.csv");
    //string fichier("./fichiers/graphe1.txt");
    //lecture(fichier);

    return 0;
}
