//-------------------Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const string & villeDepartConstruct, const string & villeArriveeConstruct, const string & moyenTransportConstruct) : Trajet()
{
#if defined (MAP) // MAP : Mise au point
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    villeDepart = villeDepartConstruct;
    villeArrivee = villeArriveeConstruct;
    moyenTransport = moyenTransportConstruct;

} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ()
{
#if defined (MAP) // MAP : Mise au point
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple

void TrajetSimple::Afficher()
{
    cout << "De " << villeDepart << " à " << villeArrivee << " en " << moyenTransport << endl;
}

string & TrajetSimple::getVilleDepart()
{
    return villeDepart;
}

string & TrajetSimple::getVilleArrivee()
{
    return villeArrivee;
}

void TrajetSimple::Ecrire(ofstream& fichier)
{
    
    fichier << "S;" << villeDepart << ";" << moyenTransport << ";" << villeArrivee << endl;
}

TrajetSimple* TrajetSimple::Copie()
{
    return new TrajetSimple(villeDepart,villeArrivee,moyenTransport);
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées