#include "LectureEcriture.hpp"

void lectureFichierBDD(string nomFichier)
{
    int nbSommet, sommetSource, sommetDest;
    bool oriente;
    string ligneAvantDecoupe;
    vector <int> ligneDecoupee;
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
           ligneDecoupee = decoupeChaine(ligneAvantDecoupe,' ');
           
            sommetSource = ligneDecoupee[0];
            sommetDest = ligneDecoupee[1];
            //cout << sommetSource << " destination : " << sommetDest << endl;
        
            if(oriente){
                graphe.ajouterArc(sommetSource,sommetDest);
            }
            else{
                graphe.ajouterArete(sommetSource,sommetDest);
            }
        }

        cout << graphe.print();
    }
    else // Probleme ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
    }
}


void lecture()
{
    int nbSommet, sommetSource, sommetDest, indice;
    bool oriente;
    string ligneAvantDecoupe, tmp;
    vector <int> ligneDecoupee;
    string nomFichier, cheminFichier;
    
    cheminFichier = "./fichiers/";
    cout << "Entrez le nom du fichier (avec l'extension) que vous voulez lire : " << endl;
    cin >> nomFichier;

    cheminFichier = cheminFichier + nomFichier;
    ifstream fichier(cheminFichier.c_str());  //Ouverture en lecture

    if(fichier)
    {
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
        cout << graphe.print();
    }
    else // Probleme ouverture du fichier
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture" << endl;
    }
}

void ecriture(Graphe graphe)
{
    string nomFichier, cheminFichier;
    vector<Sommet> sommetsGraphe;
    set<Sommet>listeAdjSommet;
    Sommet sommetSource, sommetDest;
    int  nbVoisin;

    cheminFichier = "./fichiers/";
    cout << "Entrez le nom du fichier pour stocké le graphe : " << endl;
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
                    fichier << voisinCourant.getNum() << " ";
                }
                fichier << endl;
            }
        }
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