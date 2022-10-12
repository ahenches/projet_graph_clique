#include "LectureEcriture.hpp"

void LectureEcriture::lectureFichierBDD(string nomFichier)
{
    int nbSommet, sommetSource, sommetDest;
    bool oriente;
    string ligneAvantDecoupe;
    vector<int> ligneDecoupee;
    ifstream fichier(nomFichier.c_str());  //Ouverture en lecture

    if(fichier)
    {
        //Nombre de sommets et oriente ou non
        cout << "Entrez le nombre de sommets de votre graphe : " << endl;
        cin >> nbSommet; 

        cout << "Votre graphe est il orienté ? " << endl << "Tapez 0 pour non ou 1 pour oui" << endl;
        cin >> oriente;

        if(oriente){
            cout << "Votre graphe a " << nbSommet << " sommet et est orienté" << endl; 
        }
        else {
            cout << "Votre graphe a " << nbSommet << " sommet et est non-orienté" << endl; 
        }

        //Création graphe 
        Graphe graphe(oriente,nbSommet);

        //Ajout arcs et aretes
        
        while(getline(fichier, ligneAvantDecoupe)) 
        {
           // ligneDecoupee = decoupeChaine(ligneAvantDecoupe,' ');
            stringstream ss(ligneAvantDecoupe);
            string sousChaine;
            while (getline(ss, sousChaine, ' '))
            {
                ligneDecoupee.push_back(stoi(sousChaine));
            }

            sommetSource = ligneDecoupee[0];
            sommetDest = ligneDecoupee[1];
            //cout << sommetSource << " destination : " << sommetDest << endl;
        
            if(oriente){
                graphe.ajouterArc(sommetSource,sommetDest);
            }
            else{
                graphe.ajouterArete(sommetSource,sommetDest);
            }
            ligneDecoupee.clear();
        }

        cout << graphe.print();


    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
    }
}

vector<int> decoupeChaine(string chaine, char delimiteur)
{
    vector<int> chaineDecoupee;
    stringstream ss(chaine);
    string sousChaine;
    while (getline(ss, sousChaine, delimiteur))
    {
        chaineDecoupee.push_back(stoi(sousChaine));
    }

    return chaineDecoupee;
}