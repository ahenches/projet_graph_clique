#ifndef DEF_LECTUREECRITURE
#define DEF_LECTUREECRITURE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include "./graphe.hpp"

Graphe lectureFichierBDD(std::string nomFichier);
Graphe lecture();
void ecriture(Graphe graphe);
std::vector<int> decoupeChaine(std::string chaine, char delimiteur);

#endif