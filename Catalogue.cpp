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

//----------------------------------------------------- Méthodes publiques


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

void Catalogue::ExporterTrajets() {

    //CREATION DU FICHIER

    string nomDuFichier = "";

    cout << "-----------------------------------------" << endl;
    cout << "EXPORTATION DES TRAJETS" << endl;
    cout << "Comment souhaitez-vous nommer votre fichier ?" << endl;
    cin >> nomDuFichier;
    nomDuFichier = nomDuFichier + ".scar";
    ofstream fichier(nomDuFichier, ios::out);
    fichier << c->GetTaille() << endl;
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
        string nbTotalTrajet = "";
        getline(fichier, nbTotalTrajet);
        int nbTrajet = stoi(nbTotalTrajet);
        int choix = menuImport();
        switch (choix) {
            case 1:
                importerTrajetDepuisFichier(nbTrajet, fichier);
                break;
            case 2:
                importerTrajetsSelonType(fichier, nbTrajet);
                break;
            case 3:
                importerTrajetsSelonVille(fichier, nbTrajet);
                break;
            case 4:
                importerTrajetsSelonIntervalle(fichier, nbTrajet);
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

void Catalogue::importerTrajetDepuisFichier(int nbTrajet, ifstream &fichier, bool trajetSimple, bool trajetCompose, const string & villeDepart,const string & villeArrivee, int n, int m)
{

    stringstream ss;
    string ligne = "";
    string type = "";

    for(int i=0 ; i<n ;i++)
    {
        skipTrajet(fichier);
    }
    m = (m == 0) ? nbTrajet : m+1;
    for(int i=n ; i<m ;i++)
    {
        getline(fichier, ligne);
        ss = stringstream(ligne);
        getline(ss, type, ';');
        if(type == "S" && trajetSimple){
            importerTrajetSimple(ss, villeDepart, villeArrivee);
        }
        else if(type == "C"){
            importTrajetCompose(ss, villeDepart, villeArrivee, trajetCompose, fichier);
        }
    }
}
/**
 * Permet d'importer des trajets selon leur type
 * @param fichier
 * @param nbTrajet
 */
void Catalogue::importerTrajetsSelonType(ifstream &fichier, int nbTrajet){
    int type = menuTypeImport();
    switch (type) {
        case 1:
            importerTrajetDepuisFichier(nbTrajet, fichier, true, false);
            break;
        case 2:
            importerTrajetDepuisFichier(nbTrajet, fichier, false, true);
            break;
        case 3:
            importerTrajetDepuisFichier(nbTrajet, fichier);
            break;
        default:
            cout << "Erreur de saisie" << endl;
            break;
    }
}
/**
 * Permet d'importer des trajets selon leur ville de départ et/ou d'arrivée
 * @param fichier
 * @param nbTrajet
 */
void Catalogue::importerTrajetsSelonVille(ifstream &fichier, int nbTrajet){
    int type = menuVilleImport();
    string ville = "";
    string depart = "";
    string arrive = "";
    switch (type) {
        case 1:
            cout << "Choix de la ville de départ : " << endl;
            cin >> ws;
            getline(cin, ville);
            importerTrajetDepuisFichier(nbTrajet, fichier, true, true,ville);
            break;
        case 2:
            cout << "Choix de la ville d'arrivée : " << endl;
            cin >> ws;
            getline(cin, ville);
            importerTrajetDepuisFichier(nbTrajet, fichier, true, true,"",ville);
            break;
        case 3:
            cout << "Choix de la ville de départ : " << endl;
            cin >> ws;
            getline(cin, ville);
            depart = ville;
            cout << "Choix de la ville d'arrivée : " << endl;
            cin >> ws;
            getline(cin, ville);
            arrive = ville;
            importerTrajetDepuisFichier(nbTrajet, fichier,true,true,depart,arrive);
            break;
        default:
            cout << "Erreur de saisie" << endl;
            break;
    }
}

/**
 * Permet d'importer un intervalle de trajets
 * @param fichier
 * @param nbTrajets
 */
void Catalogue::importerTrajetsSelonIntervalle(ifstream &fichier, int nbTrajets){
    int n ;
    int m ;
    cout << "------------------------------------------" << endl;
    cout << "IMPORTATION SELON UN INTERVALLE DE TRAJETS" << endl;
    cout << "Choix de l'intervalle de trajets à importer" << endl;
    cout << "Le fichier contient " << nbTrajets << " trajets" << endl;
    cout << "Vous pouvez importer de 1 à " << nbTrajets << " trajets" << endl;
    cout << "L'intervalle est : [n,m] avec n <= m avec au maximum : [0,nbTrajet-1]" << endl;
    do{
        cout << "Choix de n : " << endl;
        cin >> n;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            n = 0;
        }
        cout << "Choix de m : " << endl;
        cin >> m;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            m = 0;
        }
    }while(n > m || n < 0 || m >= nbTrajets);
    importerTrajetDepuisFichier(nbTrajets, fichier, true, true, "", "", n, m);

}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

/**
 * Permet d'importer un trajet simple à partir d'un fichier
 * @param ss : ligne du fichier
 * @param villeDepart : ville de départ à importer
 * @param villeArrivee : ville d'arrivée à importer
 */
void Catalogue::importerTrajetSimple(stringstream & ss, const string &villeDepart, const string &villeArrivee) {
    string depart = "";
    string moyen = "";
    string arrivee = "";
    getline(ss, depart, ';');
    getline(ss, moyen, ';');
    getline(ss, arrivee, ';');
    //Suppression des espaces
    depart.erase(depart.find_last_not_of(" \t\r\n") + 1);
    moyen.erase(moyen.find_last_not_of(" \t\r\n") + 1);
    arrivee.erase(arrivee.find_last_not_of(" \t\r\n") + 1);
    //Ajout du trajet simple au catalogue si les villes correspondent
    if(villeDepart != "" && villeArrivee != ""){
        if(depart == villeDepart && arrivee == villeArrivee){
            c->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
        }
    }else if(villeDepart != ""){
        if(depart == villeDepart){
            c->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
        }
    }else if(villeArrivee != ""){
        cout << "villeArrivee : " << villeArrivee << endl;
        if(arrivee == villeArrivee){
            c->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
        }
    }else{
        c->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
    }
}

/**
 * Menu principal du catalogue / Fonctionnement du catalogue
 */
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

/**
 * Affiche le menu du catalogue : Affichage

 */
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

/**
 * Ajoute un trajet simple au catalogue
 */
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

/**
 * Menu d'ajout de trajet
 */
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

/**
 * Affiche le menu d'ajout de trajet
 */
void Catalogue::printAjoutTrajet()
{
    cout << "------------------------------------------" << endl;
    cout << "1. Ajouter un trajet simple" << endl;
    cout << "2. Ajouter un trajet composé" << endl;
    cout << "3. Retour" << endl;
    cout << "Votre choix : ";
}

/**
 * Ajoute un trajet composé au catalogue
 */
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

/**
 * Permet d'importer un trajet composé à partir d'un fichier
 * @param ss : ligne du fichier
 * @param villeDepart : ville de départ à importer
 * @param villeArrivee : ville d'arrivée à importer
 * @param trajetCompose : si on importe un trajet composé ou non
 * @param fichier : fichier à importer
 */
void Catalogue::importTrajetCompose(stringstream & ss, const string &villeDepart, const string &villeArrivee,bool trajetCompose, ifstream &fichier) {
    string nbLigne;
    string departPremier;
    string arriveeDernier;
    getline(ss, nbLigne, ';');
    getline(ss, departPremier, ';');
    getline(ss, arriveeDernier, ';');
    nbLigne.erase(nbLigne.find_last_not_of(" \t\r\n") + 1);
    departPremier.erase(departPremier.find_last_not_of(" \t\r\n") + 1);
    arriveeDernier.erase(arriveeDernier.find_last_not_of(" \t\r\n") + 1);
    int nbTrajet = stoi(nbLigne);
    if(trajetCompose){
        if(villeDepart != "" && villeArrivee != ""){
            if(departPremier == villeDepart && arriveeDernier == villeArrivee){
                AjouterTrajetComposeFromFile(fichier, nbTrajet, departPremier, arriveeDernier);
            }else{
                skipLines(fichier, nbTrajet);
            }
        }else if(villeDepart != ""){
            if(departPremier == villeDepart){
                AjouterTrajetComposeFromFile(fichier, nbTrajet, departPremier, arriveeDernier);
            }else{
                skipLines(fichier, nbTrajet);
            }
        }else if(villeArrivee != ""){
            if(arriveeDernier == villeArrivee){
                AjouterTrajetComposeFromFile(fichier, nbTrajet, departPremier, arriveeDernier);
            }else{
                skipLines(fichier, nbTrajet);
            }
        }else{
            AjouterTrajetComposeFromFile(fichier, nbTrajet, departPremier, arriveeDernier);
        }
    }else{
        skipLines(fichier, nbTrajet);
    }
}

/**
 * Permet de sauter un trajet dans un fichier
 * Skip une seule ligne pour un trajet simple ou plusieurs lignes pour un trajet composé
 * @param fichier
 */
void Catalogue::skipTrajet(ifstream &fichier) {
    string ligne = "";
    getline(fichier, ligne);
    stringstream ss = stringstream(ligne);
    string type = "";
    getline(ss, type, ';');
    if(type == "C"){
        string nbLigne;
        getline(ss, nbLigne, ';');
        nbLigne.erase(nbLigne.find_last_not_of(" \t\r\n") + 1);
        int nbTrajet = stoi(nbLigne);
        skipLines(fichier, nbTrajet);
    }
}


/**
 * Permet de sauter un certain nombre de ligne dans un fichier
 * @param fichier
 * @param nbLines
 */
void Catalogue::skipLines(ifstream &fichier, int nbLines) {
    string ligne = "";
    for (int i = 0; i < nbLines; i++) {
        getline(fichier, ligne);
    }
}

/**
 * Ajoute un trajet composé au catalogue à partir d'un fichier
 * @param fichier
 * @param nbTrajet
 * @param villeDepart
 * @param villeArrivee
 */
void Catalogue::AjouterTrajetComposeFromFile(ifstream &fichier, int nbTrajet, const string &villeDepart,const string &villeArrivee) {
    //Déclaration des variables
    string ligne = "";
    string type = "";
    string depart = "";
    string moyen = "";
    string arrivee = "";
    stringstream ss;

    //Création de la liste de trajet
    Collection *listeTrajet = new Collection();
    for (int i = 0; i < nbTrajet; i++) {
        getline(fichier, ligne);
        ss = stringstream(ligne);
        //Récupération des données
        getline(ss, type, ';');
        getline(ss, depart, ';');
        getline(ss, moyen, ';');
        getline(ss, arrivee, ';');
        //Suppression des espaces
        type.erase(type.find_last_not_of(" \t\r\n") + 1);
        depart.erase(depart.find_last_not_of(" \t\r\n") + 1);
        moyen.erase(moyen.find_last_not_of(" \t\r\n") + 1);
        arrivee.erase(arrivee.find_last_not_of(" \t\r\n") + 1);
        //Ajout du trajet simple à la liste
        listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
    }
    //Ajout du trajet composé au catalogue
    TrajetCompose *trajetCompose = new TrajetCompose(listeTrajet);
    c->AjouterFin(trajetCompose);
}

/*
 * Menu d'importation par type
 * Permet de choisir si on importe les trajets simples, les trajets composés ou les deux
 */
int Catalogue::menuTypeImport(){
    int choix;
    do{
        cout << "------------------------------------------" << endl;
        cout << "1. Importer tous les trajets simples" << endl;
        cout << "2. Importer tous les trajets composés" << endl;
        cout << "3. Importer tous les trajets" << endl;
        cout << "--> Votre choix : ";
        cin >> choix;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            choix = 0;
        }
    }while(choix < 1 || choix > 3);
    return choix;
}

/*
 * Menu d'importation par ville
 * Permet de choisir si on importe selon la ville de départ, la ville d'arrivée ou les deux
 */
int Catalogue::menuVilleImport(){
    int choix;
    do{
        cout << "------------------------------------------" << endl;
        cout << "1. Importer selon une ville de départ" << endl;
        cout << "2. Importer selon une ville d'arrivée " << endl;
        cout << "3. Importer selon une ville de départ et d'arrivée" << endl;
        cout << "--> Votre choix : ";
        cin >> choix;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            choix = 0;
        }
    }while(choix < 1 || choix > 3);
    return choix;
}

/**
 * Menu d'importation globale :
 * Permet de choisir le type d'importation
 * @return
 */
int Catalogue::menuImport() {
    int choix;
    do{
        cout << "------------------------------------------" << endl;
        cout << "1. Importer tous les trajets" << endl;
        cout << "2. Importer selon un type de trajet" << endl;
        cout << "3. Importer selon une ville de départ et/ou une ville d'arrivée" << endl;
        cout << "4. Importer selon un intervalle de ville de départ et/ou une ville d'arrivée" << endl;
        cout << "--> Votre choix : ";
        cin >> choix;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            choix = 0;
        }
    }while(choix < 1 || choix > 4);
    return choix;
}

/*
 * Menu d'exportation
 */
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