# projet_graph_clique
Détection de communautés dans des réseaux sociaux

Librairie utilisée : 
Sciplot qui est une sur-couche de gnuplot 
gnuplot est donc à installer avec pour Debian :
$ sudo apt install gnuplot

CentOS & Fedora(pas testé ..) :
$ sudo yum install gnuplot 
ou
$ sudo dnf install gnuplot


Option de Compilation : "make" dans le répertoire source
$ make
"g++ -g -Wall -std=c++17 -o lectureEcriture.o -c src/lectureEcriture.cpp -O"
"g++ -std=c++17 -o histogram.o -Iinclude -c src/histogram.cpp -O"
"g++ -g -Wall -std=c++17 -o main.out -Iinclude main.cpp src/graphe.cpp src/sommet.cpp lectureEcriture.o histogram.o"


Pour lancer le programme nouvellement compilé : 
$ main.out "Arg1" "Arg2"
avec Arg1 comme (Create, create, c) pour générer les graphes aléatoires
		  ou (read, Read, r) pour lire les fichiers créés contenant les graphes aléatoires (à utiliser après les avoir généré).
	(Les graphes données issus de la base de données sont stockés différement de comment ils sont téléchargés.)
et Arg2 comme (partieX, PartieX, X) (avec X comme 1 ou 2 ou 3) pour choisir la partie désirée dans le sujet.
exemple : 
$ ./main.out c 1
$ ./main.out r 2
$ ./main.out c 3 détruit les graphes aléatoires précedemment créés avec ./main.out c 1

A noter lors de l'execution de la première partie, le seuil choisit pour generer les graphes aléatoirement peut varier d'une execution à l'autre. Ainsi, pour l'exécution de l'algorithme du calcul des chemins de longueur 2 cela peut prendre de 1 seconde à 10-15mins Le premier graphe aléatoire ayant le plus de sommet c'est celui ci qui coûtera le plus de temps d'exécution.


 
