//----------------Interface de la classe <Cellule> (fichier Cellule.h)----------------//

#if !defined CELLULE_H
#define CELLULE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------//
// Rôle de la structure <Cellule>
// Description :
//------------------------------------------------------------------------//

typedef struct Cellule{
    Trajet *t;
    Cellule *suivant;
}Cellule;

//-------------------------------- Autres définitions dépendantes de <Classe>

#endif // !defined CLASSE_H
