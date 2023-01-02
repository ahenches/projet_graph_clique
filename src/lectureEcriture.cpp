#include "lectureEcriture.hpp"

using namespace std;

/**
 * @brief Lecture d un fichier provenant de la base de donnees contenant un graphe
 * 
 * @param nomFichier nom du fichier de la base de donnees
 * @param separateur le separateur dans le fichier 
 * @param estUnfichierCSV si 1 le fichier est une extension csv sinon 0
 * @param nbSommet le nombre de sommet du graphe
 * @param oriente si 1 le graphhe est oriente sinon 0
 * @return retourne le graphe lu dans le fichier
 */
Graphe lectureFichierBDD(string nomFichier, char separateur, bool estUnfichierCSV, int nbSommet, bool oriente)
{
    int sommetSource, sommetDest;
    string ligneAvantDecoupe;
    vector <int> ligneDecoupee;
    ifstream fichier(nomFichier.c_str());  //Ouverture en lecture du fichier

    if(fichier)
    {
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

/**
 * @brief Lecture d un fichier contenant un graphe
 * 
 * @param nomFichier le nom du fichier a lire
 * @return le graphe contenu dans le fichier
 */
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

/**
 * @brief Ecriture d un graphe dans un fichier
 * 
 * @param graphe graphe a ecrire dans le fichier
 * @param nomFichier le nom du fichier dans lequel on copie le graphe
 * @return ** void 
 */
void ecriture(Graphe graphe,string nomFichier)
{
    string cheminFichier;
    map<int,Sommet> sommetsGraphe;
    set<int>listeAdjSommet;
    Sommet sommetSource, sommetDest;
    int  nbVoisin;

    cheminFichier = "./fichiers/";
    cheminFichier = cheminFichier + nomFichier + ".txt";
    ofstream fichier(cheminFichier.c_str()); // Ouverture en ecriture

    if(fichier)
    {
        //Ecriture nbSommet et oriente ou non
        fichier << graphe.getNbSommet() << endl;
        fichier << graphe.getEstOriente() << endl;

        //Ecriture des listes d adjacence
        sommetsGraphe = graphe.getSommets();
        map<int, Sommet>::iterator itr;
        for(itr = sommetsGraphe.begin(); itr != sommetsGraphe.end(); itr++)
        {
            sommetSource = itr -> second;
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

/**
 * @brief Decoupe une chaine de caractere
 * 
 * @param chaine La chaine a decouper
 * @param delimiteur le caractere qui separe les elements de la chaine
 * @return ** vector<int> contenant les elements de la chaine
 */
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
