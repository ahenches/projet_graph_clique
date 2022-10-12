#ifndef DEF_LECTUREECRITURE
#define DEF_LECTUREECRITURE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "./graphe.hpp"

using namespace std;

class LectureEcriture
{
    public :
    void lectureFichierBDD(string nomFichier);
    void lecture(string nomFichier);
    void ecriture();
    vector<int> decoupeChaine(string chaine, char delimiteur);
};

#endif