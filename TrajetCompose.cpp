//-------------------Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher(){
//    cout << "Trajet de " << this->listeTrajets->GetHead->getVilleDepart() << " à " << this->listeTrajets->GetTail->getVilleArrivee() << " en " << moyenTransport << endl;
}

char* TrajetCompose::getVilleDepart(){
    return this->listeTrajets->GetHead()->t->getVilleDepart();
}

char* TrajetCompose::getVilleArrivee(){
    return this->listeTrajets->GetTail()->t->getVilleArrivee();
}




//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(Collection* newListeTrajets) : Trajet(){
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    listeTrajets = newListeTrajets;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose (){
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete listeTrajets;
} //----- Fin de ~TrajetCompose

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées