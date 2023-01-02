#ifndef DEF_LECTUREECRITURE
#define DEF_LECTUREECRITURE

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include "./graphe.hpp"

Graphe lectureFichierBDD(std::string nomFichier, char separateur, bool estUnfichierCSV, int nbSommet, bool oriente);
Graphe lecture(std::string nomFichier);
void ecriture(Graphe graphe,std::string nomFichier);
std::vector<int> decoupeChaine(std::string chaine, char delimiteur);

#endif