//----------------Interface de la classe <TrajetCompose> (fichier TrajetCompose.h)----------------//

#if !defined TRAJETCOMPOSE_H
#define TRAJETCOMPOSE_H

//-------------------------------------------------------- Interfaces utilisées
#include "collection.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------//
// Rôle de la classe <TrajetCompose>
// Description :
//------------------------------------------------------------------------//

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques
    virtual void Afficher();
    // Mode d'emploi : Affiche les éléments de l'ensemble
    // Contrat : Aucun
    //
    virtual char* getVilleDepart();
    // Mode d'emploi : Renvoi la ville de départ
    // Contrat : Aucun
    //
    virtual char* getVilleArrivee();
    // Mode d'emploi : Renvoi la ville d'arrivée
    // Contrat : Aucun
    //

    TrajetCompose* Copie();

//---------------------------------------------------------------Surcharge d'opérateurs
    //
//-----------------------------------------------------Constructeurs - Destructeur
    TrajetCompose ( TrajetCompose const & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    // Contrat :

    TrajetCompose ( Collection* newListeTrajets);
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées
    // type méthode ( liste des paramètres );
    // Mode d'emploi :
    // Contrat :

//-------------------------------------------------------------Attributs protégés
    Collection* listeTrajets;

};

//-------------------------------- Autres définitions dépendantes de <Classe>

#endif // !defined CLASSE_H
