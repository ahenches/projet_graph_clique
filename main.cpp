#include <iostream>
#include <vector>
#include <cstring>

#include "src/histogram.hpp"
#include "src/graphe.hpp"
#include "src/sommet.hpp"
#include "src/lectureEcriture.hpp"

using namespace std;

int main(int argc, char * argv[])
{
    /////////////////////// Initialistations des graphes //////////////////////////

    cout << "///////////////////// Initialisation des graphes ////////////////////" << endl << endl;
	Graphe grapheFacebook, grapheEmailEu, grapheLastFM, grapheAleatoire1, grapheAleatoire2, grapheAleatoire3;
    /// Lecture des fichiers de la base de données de Stanford
	if (argc != 3)
	{
		printf("Nombre inadéquat d'arguments");
		return 1;
	}
	else if (strcmp(argv[1], "read") != 0 && strcmp(argv[1], "Read") != 0 && strcmp(argv[1], "r") != 0)
	{
		string fichierFacebook, fichierEmailEu, fichierLastFmAsia;

		fichierFacebook = "./fichiers/facebook_combined.txt";
		fichierEmailEu = "./fichiers/email-Eu-core.txt";
		fichierLastFmAsia = "./fichiers/lastfm_asia_edges.csv";

		grapheFacebook = lectureFichierBDD(fichierFacebook,' ', false, NB_SOMMET_FACEBOOK, NON_ORIENTE);
		cout << "\tCopie du graphe Facebook dans un autre fichier"<< endl;
		ecriture(grapheFacebook, "copie_graphe_facebook");

		grapheEmailEu = lectureFichierBDD(fichierEmailEu,' ', false, NB_SOMMET_EMAIL_EU, ORIENTE);
		cout << "\tCopie du graphe Email EU dans un autre fichier"<< endl;
		ecriture(grapheEmailEu, "copie_graphe_email_eu"); 

		grapheLastFM = lectureFichierBDD(fichierLastFmAsia,',', true,NB_SOMMET_LASTFM, NON_ORIENTE);
		cout << "\tCopie du graphe Last FM dans un autre fichier"<< endl;
		ecriture(grapheLastFM, "copie_graphe_lastfm_asia");

		/// Graphes Aleatoires

		/// Premier graphe
		cout << "Premier graphe Aleatoire " << endl;
		grapheAleatoire1 = Graphe(ORIENTE, NB_SOMMET_ALEA_1);
		grapheAleatoire1.genererArcsAleatoires();
		ecriture(grapheAleatoire1, "graphe_aleatoire_1");

		/// Deuxieme graphe
		cout << "Deuxieme graphe Aleatoire " << endl;
		grapheAleatoire2 = Graphe(NON_ORIENTE, NB_SOMMET_ALEA_2);
		grapheAleatoire2.genererArcsAleatoires();
		ecriture(grapheAleatoire2,"graphe_aleatoire_2");

		/// Troisieme graphe
		cout << "Troisieme graphe Aleatoire " << endl;
		grapheAleatoire3 = Graphe(NON_ORIENTE, NB_SOMMET_ALEA_3);
		grapheAleatoire3.genererArcsAleatoires();
		ecriture(grapheAleatoire3, "graphe_aleatoire_3");
	}
	else 	
	{
		//////////////////////////// Lecture des graphes deja enregistres //////////////////////
		cout << "//////////////// Lecture des graphes déjà enregistrés /////////////////" << endl << endl;
		Graphe grapheFacebook = lecture("copie_graphe_facebook.txt");
		Graphe grapheEmailEu = lecture("copie_graphe_email_eu.txt");
		Graphe grapheLastFM = lecture("copie_graphe_lastfm_asia.txt");
		Graphe grapheAleatoire1 = lecture("graphe_aleatoire_1.txt");
		Graphe grapheAleatoire2 = lecture("graphe_aleatoire_2.txt");
		Graphe grapheAleatoire3 = lecture("graphe_aleatoire_3.txt");
	}

	cout << "Petit graphe :" << endl;
	
	Graphe petitGraphe(false, 8);
	petitGraphe.genererArcsAleatoires();
	cout << petitGraphe.print() << endl << endl;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 1 ere partie /////////////////////////////////////////////////////////////////

	if (strcmp(argv[2], "partie1") == 0 || strcmp(argv[2], "Partie1") == 0 || strcmp(argv[2], "1") == 0)
	{ 
		cout << "////////////////////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////// 1ère partie /////////////////////////////////" << endl << endl;
		

		/////////////////////////// Données sur les graphes ////////////////////////////////////

		/// Degre Max
		cout << "//////////////// Degré maximum des graphes /////////////////" << endl << endl;
		cout << "\tLe degré maximum du graphe Facebook est : " << grapheFacebook.calculerDegreMax() << endl;
		cout << "\tLe degré maximum du graphe Email EU est : " << grapheEmailEu.calculerDegreMax() << endl;
		cout << "\tLe degré maximum du graphe Lastfm est : " << grapheLastFM.calculerDegreMax() << endl;
		cout << "\tLe degré maximum du graphe Aleatoire 1 est : " << grapheAleatoire1.calculerDegreMax() << endl;
		cout << "\tLe degré maximum du graphe Aleatoire 2 est : " << grapheAleatoire2.calculerDegreMax() << endl;
		cout << "\tLe degré maximum du graphe Aleatoire 3 est : " << grapheAleatoire3.calculerDegreMax() << endl << endl;


		/// Graphique des degres
		dessinerHistogrammeDegres(grapheFacebook.getNbSommet(), grapheFacebook.calculerDegres(), "degrés Facebook");
		dessinerHistogrammeDegres(grapheEmailEu.getNbSommet(), grapheEmailEu.calculerDegres(), "degrés Email EU" );
		dessinerHistogrammeDegres(grapheLastFM.getNbSommet(), grapheLastFM.calculerDegres(), "degrés LastFM");
		dessinerHistogrammeDegres(grapheAleatoire1.getNbSommet(), grapheAleatoire1.calculerDegres(), "degrés Aleatoire 1");
		dessinerHistogrammeDegres(grapheAleatoire2.getNbSommet(), grapheAleatoire2.calculerDegres(), "degrés Aleatoire 2");
		dessinerHistogrammeDegres(grapheAleatoire3.getNbSommet(), grapheAleatoire3.calculerDegres(), "degrés Aleatoire 3");


		/// Nombre de chemins de longueur 2

		cout << "//////////////// Nombre de chemin de longueur 2 /////////////////" << endl << endl;
		cout << "\tLe nombre de chemin de longueur 2 du graphe Facebook est : " << grapheFacebook.compteCheminDistanceDeux() << endl;
		cout << "\tLe nombre de chemin de longueur 2 du graphe Email EU est : " << grapheEmailEu.compteCheminDistanceDeux() << endl;
		cout << "\tLe nombre de chemin de longueur 2 du graphe Lastfm est : " << grapheLastFM.compteCheminDistanceDeux() << endl;
		cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 1 est : " << grapheAleatoire1.compteCheminDistanceDeux() << endl;
		cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 2 est : " << grapheAleatoire2.compteCheminDistanceDeux() << endl;
		cout << "\tLe nombre de chemin de longueur 2 du graphe Aleatoire 3 est : " << grapheAleatoire3.compteCheminDistanceDeux() << endl << endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 2 eme partie /////////////////////////////////////////////////////////////////
	else if (strcmp(argv[2], "partie2") == 0 || strcmp(argv[2], "Partie2") == 0 || strcmp(argv[2], "2") == 0)
	{
		cout << "////////////////////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////// 2ème partie /////////////////////////////////" << endl << endl;

		/// Cliques Maximales
		
		vector<set<int>> cliquesMaxPetitGraphe, cliquesMaxGrapheAleatoire;

		cout << "/////////////////////// Cliques Maximales /////////////////////////////" << endl << endl;
		
		/// Exemple sur le premier graphe
		cout << "\tExemple sur le petit graphe " << endl;
		cout << "\tCliques maximales : " << endl;
		cliquesMaxPetitGraphe = petitGraphe.cliqueMaximaleBronKerbosch();
		
		/// Affichage des cliques
		for (auto clique : cliquesMaxPetitGraphe)
		{
			cout << "\t";
			for (int i : clique)
			{
				cout << i << " ";
			}
			cout << endl;
		}
		cout << endl << "\tIl y a "<< cliquesMaxPetitGraphe.size() << " cliques maximales" << endl << endl;
		
		/// Exemple sur le deuxième graphe 
		cout << endl << "\tExemple sur un graphe aléatoire " << endl;
		cout << "\tCliques maximales : " << endl;
		cliquesMaxGrapheAleatoire = grapheAleatoire3.cliqueMaximaleBronKerbosch();
		
		/// Affichage des cliques 
		for (auto clique : cliquesMaxGrapheAleatoire)
		{
			cout << "\t[ ";
			for (int i : clique)
			{
				cout << i << " ";
			}
			cout << "]"<< endl;
		}
		cout << endl <<"\tIl y a "<< cliquesMaxGrapheAleatoire.size() << " cliques maximales" << endl << endl;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////// 3 eme partie /////////////////////////////////////////////////////////////////
	else if (strcmp(argv[2], "partie3") == 0 || strcmp(argv[2], "Partie3") == 0 || strcmp(argv[2], "3") == 0)
	{
		cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "////////////////////////////////////////////// 3ème partie //////////////////////////////////////////////" << endl << endl;

		cout << "/////////////////////////// Ensemble indépendant Maximal /////////////////////////////" << endl << endl;

		vector<set<int>> cliquesMax;
		map<int, Sommet>::iterator itr;
		for(itr = petitGraphe.getSommets().begin(); itr != petitGraphe.getSommets().end(); itr++)
		{
			Graphe gi = petitGraphe.sousGrapheGi(itr->first);
			cout << "Graphe G"<<itr->first << endl;
			cout << gi.print() <<endl;

			Graphe complementaireGi = gi.complementaireGraphe();
			cout << "Complementaire graphe G"<<itr->first << endl;
			cout << complementaireGi.print() <<endl;

			cout << "Ensemble independant maximal de G" << itr->first <<" : " << endl;
			cliquesMax = complementaireGi.cliqueMaximaleBronKerbosch();
			for (auto clique : cliquesMax)
			{
				cout << "\t[ ";
				for (int i : clique)
				{
					cout << i << " ";
				}
				cout << "]"<< endl;
			}
			cout << endl<< "//////////////////////////////////////////////////////////" << endl;
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// Fin ///////////////////////////////////////////////////////////////////////
    return 0;
}
