CPPFLAGS = -DMAP
# version initiale sans variable
# règle explicite pour la reliure
prog : main.o catalogue.o collection.o trajet.o trajetcompose.o trajetsimple.o # dépendance
	g++ -o prog main.o catalogue.o collection.o trajet.o trajetcompose.o trajetsimple.o # commande
# règle explicite pour la compilation de main.cpp
main.o : main.cpp # dépendance
	g++ -c main.cpp -g -Wall -ansi -pedantic -std=c++11 $(CPPFLAGS) # commande
# règle explicite pour la compilation de Catalogue.cpp
catalogue.o : Catalogue.h Catalogue.cpp # dépendance
	g++ -c Catalogue.cpp -g -Wall -ansi -pedantic -std=c++11 $(CPPFLAGS) # commande
# règle explicite pour la compilation de Collection
collection.o : Collection.h Collection.cpp # dépendance
	g++ -c Collection.cpp  -g -Wall -ansi -pedantic -std=c++11 $(CPPFLAGS) # commande
# règle explicite pour la compilation de Trajet.cpp
trajet.o : Trajet.h Trajet.cpp # dépendance
	g++ -c Trajet.cpp -Wall -g -ansi -pedantic -std=c++11 $(CPPFLAGS) # commande
# règle explicite pour la compilation de TrajetCompose
trajetcompose.o : TrajetCompose.h TrajetCompose.cpp # dépendance
	g++ -c TrajetCompose.cpp -g -Wall -ansi -pedantic -std=c++11 $(CPPFLAGS) # commande
# règle explicite pour la compilation de TrajetSimple
trajetsimple.o : TrajetSimple.h TrajetSimple.cpp # dépendance
	g++ -c TrajetSimple.cpp -g -Wall -ansi -pedantic -std=c++11 $(CPPFLAGS) # commande
