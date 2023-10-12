//----------------Interface de la classe <Catalogue> (fichier Catalogue.h)----------------//

#if !defined CATALOGUE_H
#define CATALOGUE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Collection.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------//
// Rôle de la classe <Catalogue>
// Description :
//------------------------------------------------------------------------//

class Catalogue
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques

    void Afficher();
    // Mode d'emploi : Affiche le contenu du catalogue
    // Contrat :

    void AjouterTrajet(Trajet* unTrajet);
    // Mode d'emploi : Ajoute un trajet au catalogue
    // Contrat :

    void Menu();

    void RechercherTrajet();

//---------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------Constructeurs - Destructeur
    Catalogue ( Catalogue const & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    // Contrat :

    Catalogue ( );
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées
    // type méthode ( liste des paramètres );
    // Mode d'emploi :
    // Contrat :

    void printMenu();
    // Mode d'emploi : Affiche le menu du catalogue
    // Contrat : Aucun

    void printAjoutTrajet();
    // Mode d'emploi : Affiche le menu d'ajout de trajet
    // Contrat : Aucun

    void ajoutTrajet();
    // Mode d'emploi : Menu d'ajout de trajet
    // Contrat : Aucun

    void ajoutTrajetSimple();
    // Mode d'emploi : Ajoute un trajet simple au catalogue
    // Contrat : Aucun

    void ajoutTrajetCompose();
    // Mode d'emploi : Ajoute un trajet composé au catalogue
    // Contrat : Aucun

//-------------------------------------------------------------Attributs protégés
    Collection *c;

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H
