#ifndef DEF_LECTUREECRITURE
#define DEF_LECTUREECRITURE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include "./graphe.hpp"

using namespace std;

void lectureFichierBDD(string nomFichier);
void lecture();
void ecriture(Graphe graphe);
vector<int> decoupeChaine(string chaine, char delimiteur);

#endif