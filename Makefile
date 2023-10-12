CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11 -DMAP
# version initiale sans variable
# règle explicite pour la reliure
EXE = prog
OBJ =  main.o Catalogue.o Collection.o Trajet.o TrajetCompose.o TrajetSimple.o

$(EXE) : $(OBJ) # dépendance
	g++ -o $(EXE) $(OBJ) # commande
# règle explicite pour la compilation de main.cpp
main.o : main.cpp # dépendance
	g++ -c main.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de Catalogue.cpp
Catalogue.o : Catalogue.h Catalogue.cpp # dépendance
	g++ -c Catalogue.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de Collection
Collection.o : Collection.h Collection.cpp # dépendance
	g++ -c Collection.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de Trajet.cpp
Trajet.o : Trajet.h Trajet.cpp # dépendance
	g++ -c Trajet.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de TrajetCompose
Trajetcompose.o : TrajetCompose.h TrajetCompose.cpp # dépendance
	g++ -c TrajetCompose.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de TrajetSimple
Trajetsimple.o : TrajetSimple.h TrajetSimple.cpp # dépendance
	g++ -c TrajetSimple.cpp $(CPPFLAGS) # commande
clean:
	rm -f $(EXE) $(OBJ)
