CPPFLAGS = -g -Wall -ansi -pedantic -std=c++11
EXE = prog
OBJ =  main.o Catalogue.o Collection.o Trajet.o TrajetCompose.o TrajetSimple.o
GCC = g++

all: $(EXE)

$(EXE): $(OBJ)
	$(GCC) -o $(EXE) $(OBJ) $(CPPFLAGS)

main.o: main.cpp
	$(GCC) -c main.cpp $(CPPFLAGS)

Catalogue.o: Catalogue.h Catalogue.cpp
	$(GCC) -c Catalogue.cpp $(CPPFLAGS)

Collection.o: Collection.h Collection.cpp
	$(GCC) -c Collection.cpp $(CPPFLAGS)

Trajet.o: Trajet.h Trajet.cpp
	$(GCC) -c Trajet.cpp $(CPPFLAGS)

TrajetCompose.o: TrajetCompose.h TrajetCompose.cpp
	$(GCC) -c TrajetCompose.cpp $(CPPFLAGS)

TrajetSimple.o: TrajetSimple.h TrajetSimple.cpp
	$(GCC) -c TrajetSimple.cpp $(CPPFLAGS)

clean:
	rm -f $(EXE) $(OBJ)

