main : lectureEcriture.o
			g++ -Wall -o main.out main.cpp src/graphe.cpp src/sommet.cpp src/statistique.cpp lectureEcriture.o 
# graphe.o : src/graphe.cpp
# 			g++ -Wall -o graphe.o -c src/graphe.cpp src/sommet.cpp -O
# sommet.o : src/sommet.cpp
# 			g++ -Wall -o sommet.o -c src/sommet.cpp -O
lectureEcriture.o : src/lectureEcriture.cpp
			g++ -Wall -o lectureEcriture.o -c src/lectureEcriture.cpp -O