//----------------Interface de la classe <TrajetSimple> (fichier TrajetSimple.h)----------------//

#if !defined TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------//
// Rôle de la classe <TrajetSimple>
// Description :
//------------------------------------------------------------------------//

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques
    virtual void Afficher();
    // Mode d'emploi : Affiche les éléments de l'ensemble
    // Contrat : Aucun
    //
    virtual string & getVilleDepart();
    // Mode d'emploi : Renvoi la ville de départ
    // Contrat : Aucun
    //
    virtual string & getVilleArrivee();
    // Mode d'emploi : Renvoi la ville d'arrivée
    // Contrat : Aucun

    virtual void Ecrire(ofstream& fichier);

    TrajetSimple* Copie();
//---------------------------------------------------------------Surcharge d'opérateurs
    //
//-----------------------------------------------------Constructeurs - Destructeur
    TrajetSimple ( TrajetSimple const & unTrajetSimple );
//    Mode d'emploi (constructeur de copie) :
//    Contrat :

    TrajetSimple (const string & villeDepartConstruct,const string & villeArriveeConstruct, const string & moyenTransportConstruct);
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

     virtual ~TrajetSimple ( );
    // Mode d'emploi :
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées
    // type méthode ( liste des paramètres );
    // Mode d'emploi :
    // Contrat :

//-------------------------------------------------------------Attributs protégés
    string villeDepart;
    string villeArrivee;
    string moyenTransport;

};

//-------------------------------- Autres définitions dépendantes de <Classe>

#endif // !defined CLASSE_H
