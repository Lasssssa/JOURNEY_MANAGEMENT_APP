//----------------Interface de la classe <Trajet> (fichier Trajet.h)----------------//

#if !defined TRAJET_H
#define TRAJET_H

//-------------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------//
// Rôle de la classe <Trajet>
// Description :
//------------------------------------------------------------------------//

class Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques
    virtual void Afficher() = 0;
    // Mode d'emploi : Affiche les éléments de l'ensemble
    // Contrat : Aucun
    //
    virtual char* getVilleDepart() = 0;
    // Mode d'emploi : Renvoi la ville de départ
    // Contrat : Aucun
    //
    virtual char* getVilleArrivee() = 0;
    // Mode d'emploi : Renvoi la ville d'arrivée
    // Contrat : Aucun
    //
    virtual Trajet* Copie() = 0;
//---------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------Constructeurs - Destructeur
    Trajet ( Trajet const & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    // Contrat :

    Trajet ( );
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~Trajet ( );
    // Mode d'emploi :
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées
    // type méthode ( liste des paramètres );
    // Mode d'emploi :
    // Contrat :

//-------------------------------------------------------------Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Classe>

#endif // !defined CLASSE_H
