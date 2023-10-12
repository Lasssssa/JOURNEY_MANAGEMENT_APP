CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11 -DMAP
# version initiale sans variable
# règle explicite pour la reliure
EXE = prog
OBJ =  main.o Catalogue.o Collection.o Trajet.o TrajetCompose.o TrajetSimple.o
GCC = g++

$(EXE) : $(OBJ) # dépendance
	$(GCC) -o $(EXE) $(OBJ) # commande
# règle explicite pour la compilation de main.cpp
main.o : main.cpp # dépendance
	$(GCC) -c main.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de Catalogue.cpp
Catalogue.o : Catalogue.h Catalogue.cpp # dépendance
	$(GCC) -c Catalogue.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de Collection
Collection.o : Collection.h Collection.cpp # dépendance
	$(GCC) -c Collection.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de Trajet.cpp
Trajet.o : Trajet.h Trajet.cpp # dépendance
	$(GCC) -c Trajet.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de TrajetCompose
Trajetcompose.o : TrajetCompose.h TrajetCompose.cpp # dépendance
	$(GCC) -c TrajetCompose.cpp $(CPPFLAGS) # commande
# règle explicite pour la compilation de TrajetSimple
Trajetsimple.o : TrajetSimple.h TrajetSimple.cpp # dépendance
	$(GCC) -c TrajetSimple.cpp $(CPPFLAGS) # commande
clean:
	rm -f $(EXE) $(OBJ)
