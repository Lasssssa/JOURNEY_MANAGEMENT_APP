//----------------Interface de la classe <Collection> (fichier Collection.h)----------------//

#if !defined COLLECTION_H
#define COLLECTION_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Cellule.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------//
// Rôle de la classe <Collection>
// Description :
//------------------------------------------------------------------------//

class Collection
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-----------------------------------------------------------------Méthodes publiques
    void AjouterDebut(Trajet *unTrajet);
    // Mode d'emploi : Ajoute un trajet au début de la collection
    // Contrat : Aucun

    void AjouterFin(Trajet *unTrajet);
    // Mode d'emploi : Ajoute un trajet à la fin de la collection
    // Contrat : Aucun

    void Afficher();
    // Mode d'emploi : Affiche les éléments de l'ensemble
    // Contrat : Aucun

    void Rechercher(char *villeDepart, char *villeArrivee);
    // Mode d'emploi : Affiche les trajets correspondant à la recherche
    // Contrat : Aucun
    //---------------------------------------------------------------Surcharge d'opérateurs

    //-----------------------------------------------------Constructeurs - Destructeur
    Collection(Collection const &unCollection);
    // Mode d'emploi (constructeur de copie) :
    // Contrat :

    Collection();
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~Collection();
    // Mode d'emploi :
    // Contrat :

    void RechercheSimple(char *villeDepart, char *villeArrivee);

    void RechercheComplexe(char *villeDepart, char *villeArrivee);
    //------------------------------------------------------------------ PRIVE
protected:
    //-----------------------------------------------------------Méthodes protégées
    // type méthode ( liste des paramètres );
    // Mode d'emploi :
    // Contrat :

    //-------------------------------------------------------------Attributs protégés
    Cellule *head;
    Cellule *tail;
};

//-------------------------------- Autres définitions dépendantes de <Classe>

#endif // !defined CLASSE_H
