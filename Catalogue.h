//----------------Interface de la classe <Catalogue> (fichier Catalogue.h)----------------//

#if !defined CATALOGUE_H
#define CATALOGUE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include <fstream>

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

    void RechercherTrajet();

    void ExporterTrajets();

    void ImporterTrajets();

    void ExporterTrajetsDansFichier(ofstream &fichier, bool simple, bool compose);

    void ExporterTrajetssSelonType(ofstream &fichier);

    void ExporterTrajetssSelonVille(ofstream &fichier);

    void ExporterTrajetssSelonIntervalle(ofstream &fichier);

    void importerTrajetDepuisFichier(int nbTrajet, ifstream &fichier, bool trajetSimple= true,
                             bool trajetCompose= true, const string & villeDepart = "",
                             const string & villeArrivee = "", int n = 0, int m = 0);

    void importerTrajetsSelonType(ifstream &fichier, int nbTrajet);

    void importerTrajetsSelonVille(ifstream &fichier, int nbTrajet);

    void importerTrajetsSelonIntervalle(ifstream &fichier, int nbTrajets);

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

    void Menu();

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées

    int menuTypeExport();

    int menuTypeImport();

    int menuVilleImport();

    int menuVilleExport();

    int menuImport();
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

    int menuExport();

    void EcrireVilleDepartArrivee(ofstream &fichier, string villeDepart, string villeArrivee);

    void AjouterTrajetComposeFromFile(ifstream &fichier, int nbTrajet, const string & villeDepart, const string & villeArrivee);

    void skipLines(ifstream &fichier, int nbLines);

    void skipTrajet(ifstream &fichier);

    void importerTrajetSimple(stringstream& ss, const string &villeDepart, const string &villeArrivee);

    void importTrajetCompose(stringstream& ss, const string &villeDepart, const string &villeArrivee,bool trajetCompose, ifstream &fichier);
//-------------------------------------------------------------Attributs protégés
    Collection *c;

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H
