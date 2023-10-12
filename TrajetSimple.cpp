//-------------------Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* villeDepartConstruct, const char* villeArriveeConstruct, const char* moyenTransportConstruct) : Trajet()
{
#if defined (MAP) // MAP : Mise au point
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    villeDepart = new char[strlen(villeDepartConstruct)+1];
    strcpy(villeDepart,villeDepartConstruct);
    villeArrivee = new char[strlen(villeArriveeConstruct)+1];
    strcpy(villeArrivee,villeArriveeConstruct);
    moyenTransport = new char[strlen(moyenTransportConstruct)+1];
    strcpy(moyenTransport,moyenTransportConstruct);


} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ()
{
#if defined (MAP) // MAP : Mise au point
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] villeDepart;
    delete [] villeArrivee;
    delete [] moyenTransport;
} //----- Fin de ~TrajetSimple

void TrajetSimple::Afficher()
{
    cout << "De " << villeDepart << " à " << villeArrivee << " en " << moyenTransport << endl;
}

char* TrajetSimple::getVilleDepart()
{
    return villeDepart;
}

char* TrajetSimple::getVilleArrivee()
{
    return villeArrivee;
}

TrajetSimple* TrajetSimple::Copie()
{
    return new TrajetSimple(villeDepart,villeArrivee,moyenTransport);
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées