#include "lectureEcriture.hpp"

using namespace std;

Graphe lectureFichierBDD(string nomFichier, char separateur, bool estUnfichierCSV)
{
    int nbSommet, sommetSource, sommetDest;
    bool oriente;
    string ligneAvantDecoupe;
    vector <int> ligneDecoupee;
    ifstream fichier(nomFichier.c_str());  //Ouverture en lecture du fichier

    if(fichier)
    {
        //Nombre de sommets et oriente ou non
        cout << "Fichier en cours de lecture : " << nomFichier << endl;
        cout << "\tEntrez le nombre de sommets de votre graphe : " << endl;
        cin >> nbSommet; 

        cout << "\tVotre graphe est il orienté ? " << endl << "\tTapez 0 pour non ou 1 pour oui" << endl;
        cin >> oriente;

        if(oriente){
            cout << "\tVotre graphe a " << nbSommet << " sommet et est orienté" << endl; 
        }
        else {
            cout << "\tVotre graphe a " << nbSommet << " sommet et est non-orienté" << endl; 
        }

        //Création graphe 
        Graphe graphe(oriente,nbSommet);

        //Ajout arcs 
        if (estUnfichierCSV) // Premiere ligne a passer
        {
            getline(fichier, ligneAvantDecoupe);
        }
        while(getline(fichier, ligneAvantDecoupe)) 
        {
           ligneDecoupee = decoupeChaine(ligneAvantDecoupe,separateur);
           
            sommetSource = ligneDecoupee[0];
            sommetDest = ligneDecoupee[1];
            if(oriente){
                graphe.ajouterArc(sommetSource,sommetDest);
            }
            else 
            {
                graphe.ajouterArete(sommetSource,sommetDest);
            }
        }
        cout << "\tLecture du fichier " << nomFichier << " terminée" << endl << endl;
        return graphe;
    }
    else // Probleme ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
        return NULL;
    }
}

Graphe lecture(string nomFichier)
{
    int nbSommet, sommetSource, sommetDest, indice;
    bool oriente;
    string ligneAvantDecoupe, tmp;
    vector <int> ligneDecoupee;
    string cheminFichier;
    
    cheminFichier = "./fichiers/";
    if (nomFichier == " ")
    {
        cout << "\tEntrez le nom du fichier (avec l'extension) que vous voulez lire : " << endl;
        cin >> nomFichier;
    }

    cheminFichier = cheminFichier + nomFichier;
    ifstream fichier(cheminFichier.c_str());  //Ouverture en lecture

    if(fichier)
    {
        cout << "\tFichier en cours de lecture : " << nomFichier<< endl;
        //Lecture des 2 premieres lignes pour le nombre de sommets et orienté ou non
        getline(fichier,tmp);
        nbSommet = stoi(tmp);

        getline(fichier,tmp);
        oriente = stoi(tmp);

        //Creation graphe
        Graphe graphe(oriente,nbSommet);

        //Ajout des arcs
        while(getline(fichier, ligneAvantDecoupe))
        {
            ligneDecoupee = decoupeChaine(ligneAvantDecoupe, ' ');

            sommetSource = ligneDecoupee[0];
            for(indice = 1; indice < static_cast<int>(ligneDecoupee.size()) ; indice++)
            {
                sommetDest = ligneDecoupee[indice];
                graphe.ajouterArc(sommetSource,sommetDest);
            }
        }
        cout << "\tLecture du fichier "<< cheminFichier << " terminée" << endl << endl;
        return graphe;
    }
    else // Probleme ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
        return NULL;
    }
}

void ecriture(Graphe graphe)
{
    string nomFichier, cheminFichier;
    vector<Sommet> sommetsGraphe;
    set<int>listeAdjSommet;
    Sommet sommetSource, sommetDest;
    int  nbVoisin;

    cheminFichier = "./fichiers/";
    cout << "\tEntrez le nom du fichier pour stocké le graphe : " << endl;
    cin >> nomFichier;

    cheminFichier = cheminFichier + nomFichier + ".txt";
    ofstream fichier(cheminFichier.c_str()); // Ouverture en ecriture

    if(fichier)
    {
        //Ecriture nbSommet et oriente ou non
        fichier << graphe.getNbSommet() << endl;
        fichier << graphe.getEstOriente() << endl;

        //Ecriture des listes d adjacence
        sommetsGraphe = graphe.getSommets();
        for (auto sommetCourant : sommetsGraphe)
        {
            sommetSource = sommetCourant;
            nbVoisin =  static_cast<int>(sommetSource.getListeAdj().size());
            if(nbVoisin > 0 ) //Le sommet a au moins 1 voisin
            {
                fichier << sommetSource.getNum() << " ";
                listeAdjSommet = sommetSource.getListeAdj();
                for(auto voisinCourant : listeAdjSommet)
                {
                    fichier << voisinCourant << " ";
                }
                fichier << endl;
            }
        }
        cout << "\tLe graphe a été enregistré dans le fichier " << cheminFichier << endl;
    }
    else //Probleme ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en ecriture" << endl;
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