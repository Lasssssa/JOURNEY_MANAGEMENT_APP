//-------------------Réalisation de la classe <Catalogue> (fichier Catalogue.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
//Include pour string
#include <string>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    c = new Collection;
}

Catalogue::~Catalogue()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete c;
}

void Catalogue::Afficher()
{
    c->Afficher();
    cout << "Appuyez sur Entrer pour continuer" << endl;
    cin.get();
    cin.ignore();
}

void Catalogue::AjouterTrajet(Trajet* unTrajet)
{
    c->AjouterFin(unTrajet);
}

void Catalogue::Menu()
{
    int choix;
    do {
        printMenu();
        cin >> choix;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            choix = 0;
        }
        switch (choix) {
            case 1:
                ajoutTrajet();
                break;
            case 2:
                Afficher();
                break;
            case 3:
                RechercherTrajet();
                break;
            case 4:
                ImporterTrajets();
                break;
            case 5:
                menuExport();
                break;
            case 6:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Erreur de saisie" << endl;
                break;
        }
    } while (choix != 6);
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void Catalogue::RechercherTrajet()
{
    string depart = "";
    string arrivee = "";
    cout << "------------------------------------------" << endl;
    cout << "RECHERCHE D'UN TRAJET" << endl;
    cout << "Choix de la ville de départ : " << endl;
    cin >> ws;
    getline(cin, depart);
    cout << "Choix de la ville d'arrivée : " << endl;
    getline(cin, arrivee);
//    c->RechercheSimple(depart, arrivee);
    c->RechercheComplexe(depart, arrivee);
    cout << "Appuyez sur entrée pour continuer" << endl;
    cout << "------------------------------------------" << endl;
    cin.get();
    cin.ignore();
}

void Catalogue::printMenu()
{
    cout << "------------------------------------------" << endl;
    cout << "BIENVENUE DANS LE CATALOGUE DE TRAJET" << endl;
    cout << "QUE VOULEZ VOUS FAIRE ?" << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Ajouter un trajet" << endl;
    cout << "2. Afficher le catalogue" << endl;
    cout << "3. Rechercher un trajet" << endl;
    cout << "4. Importer des trajets" << endl;
    cout << "5. Exporter des trajets" << endl;
    cout << "6. Quitter" << endl;
    cout << "Votre choix : ";
}

void Catalogue::ajoutTrajetSimple()
{
    string depart = "";
    string arrivee = "";
    string moyen = "";
    cout << "------------------------------------------" << endl;
    cout << "AJOUT D'UN TRAJET SIMPLE" << endl;
    cout << "Choix de la ville de départ : " << endl;
    cin >> ws;
    getline(cin, depart);
    cout << "Choix de la ville d'arrivée : " << endl;
    getline(cin, arrivee);
    cout << "Choix du moyen de transport : " << endl;
    getline(cin, moyen);
    c->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
}

void Catalogue::ajoutTrajet()
{
    int choix;
    do{
        printAjoutTrajet();
        cin >> choix;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            choix = 0;
        }
        switch (choix) {
            case 1:
                ajoutTrajetSimple();
                break;
            case 2:
                ajoutTrajetCompose();
                break;
            case 3:
                break;
            default:
                cout << "Erreur de saisie" << endl;
                break;
        }
    }while(choix != 3);
}

void Catalogue::printAjoutTrajet()
{
    cout << "------------------------------------------" << endl;
    cout << "1. Ajouter un trajet simple" << endl;
    cout << "2. Ajouter un trajet composé" << endl;
    cout << "3. Retour" << endl;
    cout << "Votre choix : ";
}

void Catalogue::ajoutTrajetCompose()
{
    int choice = 1 ;
    string depart = "";
    string arrivee = "";
    string moyen = "";
    cout << "------------------------------------------" << endl;
    cout << "Ajout d'un trajet composé" << endl;
    cout << "Choix de la ville de départ : " << endl;
    cin >> ws;
    getline(cin, depart);
    cout << "Choix du premier arrêt : " << endl;
    getline(cin, arrivee);
    cout << "Choix du moyen de transport : " << endl;
    getline(cin, moyen);
    Collection* listeTrajet = new Collection();
    listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
    cout << "Choix de l'arrêt suivant : " << endl;
    depart = arrivee;
    getline(cin, arrivee);
    cout << "Choix du moyen de transport : " << endl;
    getline(cin, moyen);
    listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
    while(choice != 0){
        depart = arrivee;
        cout << "Choix de l'arrêt suivant (0 pour terminer) : " << endl;
        getline(cin, arrivee);
        if(arrivee == "0"){
            choice = 0;
        } else {
            cout << "Choix du moyen de transport : " << endl;
            getline(cin, moyen);
            listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
        }
    }
    TrajetCompose *trajetCompose = new TrajetCompose(listeTrajet);
    c->AjouterFin(trajetCompose);
}

void Catalogue::ExporterTrajets() {

    //CREATION DU FICHIER

    string nomDuFichier = "";

    cout << "-----------------------------------------" << endl;
    cout << "EXPORTATION DES TRAJETS" << endl;
    cout << "Comment souhaitez-vous nommer votre fichier ?" << endl;
    cin >> nomDuFichier;
    nomDuFichier = nomDuFichier + ".scar";
    ofstream fichier(nomDuFichier, ios::out);
    fichier << c->GetTaille() << ";" << c->GetTaille() << endl;
    Cellule *current = c->GetHead();
    while (current != nullptr) {
        current->t->Ecrire(fichier);
        current = current->suivant;
    }
    fichier.close();
}

void Catalogue::ImporterTrajets() {
    cout << "------------------------------------------" << endl;
    cout << "IMPORTATION DE TRAJETS" << endl;
    cout << "Choix du fichier à importer : " << endl;
    cout << "Voici les fichiers disponibles : " << endl;
    system("ls *.scar");
    string nomFichier = "";
    cin >> ws;
    getline(cin, nomFichier);
    cout << "Importation du fichier " << nomFichier << endl;
    ifstream fichier(nomFichier, ios::in);
    stringstream ss;
    if(fichier) {
        string premierLigne = "";

        getline(fichier, premierLigne);
        ss = stringstream(premierLigne);
        string nbTrajetSimple = "";
        string nbTrajetCompose = "";
        getline(ss, nbTrajetSimple, ';');
        getline(ss, nbTrajetCompose, ';');
        int nbTrajetsSimple = stoi(nbTrajetSimple);
        int nbTrajetsCompose = stoi(nbTrajetCompose);
        int choix = menuImport();
        switch (choix) {
            case 1:
                importerTousTrajets(fichier);
                break;
            case 2:
                importerTrajetsSelonType(fichier);
                break;
            case 3:
                importerTrajetsSelonVille(fichier);
                break;
            case 4:
                importerTrajetsSelonIntervalle(fichier);
                break;
            default:
                cout << "Erreur de saisie" << endl;
                break;
        }
        fichier.close();
    } else {
        cout << "Erreur lors de l'ouverture du fichier" << endl;
    }
}


void Catalogue::importerTousTrajets(ifstream &fichier) {
    stringstream ss;
    string ligne = "";
    string type = "";
    string depart = "";
    string moyen = "";
    string arrivee = "";
    while(getline(fichier, ligne)){
        ss = stringstream(ligne);
        getline(ss, type, ';');
        if(type == "S"){
            getline(ss, depart, ';');
            getline(ss, moyen, ';');
            getline(ss, arrivee, ';');
            depart.erase(depart.find_last_not_of(" \t\r\n") + 1);
            moyen.erase(moyen.find_last_not_of(" \t\r\n") + 1);
            arrivee.erase(arrivee.find_last_not_of(" \t\r\n") + 1);
            c->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
        }else if(type == "C"){
            string nbLigne ;
            getline(ss, nbLigne, ';');
            int nbTrajet = stoi(nbLigne);
            Collection* listeTrajet = new Collection();
            for(int i = 0; i < nbTrajet; i++)
            {
                getline(fichier, ligne);
                ss = stringstream(ligne);
                getline(ss, type, ';');
                getline(ss, depart, ';');
                getline(ss, moyen, ';');
                getline(ss, arrivee, ';');
                type.erase(type.find_last_not_of(" \t\r\n") + 1);
                depart.erase(depart.find_last_not_of(" \t\r\n") + 1);
                moyen.erase(moyen.find_last_not_of(" \t\r\n") + 1);
                arrivee.erase(arrivee.find_last_not_of(" \t\r\n") + 1);
                listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
            }
            TrajetCompose *trajetCompose = new TrajetCompose(listeTrajet);
            c->AjouterFin(trajetCompose);
        }
    }
}

int Catalogue::menuTypeImport(){
    cout << "------------------------------------------" << endl;
    cout << "1. Importer tous les trajets simples" << endl;
    cout << "2. Importer tous les trajets composés" << endl;
    cout << "3. Importer tous les trajets" << endl;
    cout << "--> Votre choix : ";
    int choix;
    cin >> choix;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        choix = 0;
    }
    return choix;
}

void Catalogue::importerTrajetsSelonType(ifstream &fichier){
    int type = menuTypeImport();
}

void Catalogue::importerTrajetsSelonVille(ifstream &fichier){

}

void Catalogue::importerTrajetsSelonIntervalle(ifstream &fichier){

}


int Catalogue::menuImport() {
    cout << "------------------------------------------" << endl;
    cout << "1. Importer tous les trajets" << endl;
    cout << "2. Importer selon un type de trajet" << endl;
    cout << "3. Importer selon une ville de départ et/ou une ville d'arrivée" << endl;
    cout << "4. Importer selon un intervalle de ville de départ et/ou une ville d'arrivée" << endl;
    cout << "--> Votre choix : ";
    int choix;
    cin >> choix;
    if(cin.fail()){
        cin.clear();
        cin.ignore();
        choix = 0;
    }
    return choix;
}


void Catalogue::menuExport() {
    cout << "-----------------------------------------" << endl;
    cout << "1. Exporter tous les trajets" << endl;
    cout << "2. Exporter selon le type de trajets" << endl;
    cout << "3. Exporter selon la ville de départ et/ou la ville d'arrivée" << endl;
    cout << "4. Exporter selon une selection de trajets" << endl;
    cout << "5. Retour" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Votre choix : ";
    int choix;
    cin >> choix;
    switch (choix) {
        case 1:
            Catalogue::ExporterTrajets();
            break;
        case 2:
            //exporter selon le type de trajets
            break;
        case 3:
            //exporter selon la ville de départ et/ou la ville d'arrivée
            break;
        case 4:
            //exporter selon une selection de trajets
            break;
        case 5:
            //retour
            break;
        default:
            cout << "Erreur de saisie" << endl;
            break;
    }
}