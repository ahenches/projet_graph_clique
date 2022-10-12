# include <iostream>

# include "./src/graphe.hpp"
# include "./src/sommet.hpp"
#include "./src/LectureEcriture.hpp"

using namespace std;

int main()
{
    /*
    Graphe g(true, 3);
    cout << g.print();
    g.ajouterArete(0, 1);
    cout << g.print();
    g.ajouterArc(0, 2);
    cout << g.print();
    cout << "Hello World" << endl;
    // cout << "main function\n";
    */
   
    //Mon test
    string fichier("./fichiers/facebook_combined.txt");
    LectureEcriture lc;
    lc.lectureFichierBDD(fichier);

    return 0;
}
