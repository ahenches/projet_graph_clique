VERS=-std=c++17
FLAGS=-g -Wall
LIB=-Iinclude
CC=g++



main.out :  main.cpp src/graphe.cpp src/sommet.cpp lectureEcriture.o histogram.o 
			$(CC) $(FLAGS) $(VERS) -o $@ $(LIB) $^ 
histogram.o : src/histogram.cpp
			$(CC) $(VERS) -o $@ $(LIB) -c src/histogram.cpp -O
lectureEcriture.o : src/lectureEcriture.cpp
			$(CC) $(FLAGS) $(VERS) -o $@ -c $^ -O
