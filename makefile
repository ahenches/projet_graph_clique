FLAGS=-std=c++17 -g -Wall
LIB=-Iinclude
CC=g++



main.out : lectureEcriture.o histogram.o statistique.o main.cpp src/graphe.cpp src/sommet.cpp
			$(CC)  $(FLAGS) -o $@ $(LIB) $^
# graphe.o : src/graphe.cpp
# 			$(CC) -Wall -o graphe.o -c src/graphe.cpp src/sommet.cpp -O
# sommet.o : src/sommet.cpp
# 			$(CC) -Wall -o sommet.o -c src/sommet.cpp -O
histogram.o : src/histogram.cpp
			$(CC) $(FLAGS) -o $@ $(LIB)  -c src/histogram.cpp -O
statistique.o : src/statistique.cpp
			$(CC) $(FLAGS) -o $@ $(LIB)  -c src/statistique.cpp -O
lectureEcriture.o : src/LectureEcriture.cpp
			$(CC) $(FLAGS) -o $@ -c src/LectureEcriture.cpp -O
