VERS=-std=c++17
FLAGS=-g -Wall
LIB=-Iinclude
CC=g++



main.out :  main.cpp src/graphe.cpp src/sommet.cpp lectureEcriture.o histogram.o
			$(CC) $(FLAGS) $(VERS) -o $@ $(LIB) $^
# graphe.o : src/graphe.cpp
# 			$(CC) -Wall -o graphe.o -c src/graphe.cpp src/sommet.cpp -O
# sommet.o : src/sommet.cpp
# 			$(CC) -Wall -o sommet.o -c src/sommet.cpp -O
histogram.o : src/histogram.cpp
			$(CC) $(VERS) -o $@ $(LIB) -c src/histogram.cpp -O
lectureEcriture.o : src/LectureEcriture.cpp
			$(CC) $(FLAGS) $(VERS) -o $@ -c src/LectureEcriture.cpp -O
