//-------------------Réalisation de la classe <Trajet> (fichier Trajet.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste de paramètres )
// Algorithme :
// Présentation de l'algorithme
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( )
{
#if defined (MAP) // MAP : Mise au point
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#if defined (MAP) // MAP : Mise au point
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées