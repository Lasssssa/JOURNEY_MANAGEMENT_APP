//-------------------Réalisation de la classe <Catalogue> (fichier Catalogue.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

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
                ExporterTrajets();
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
    char depart[100];
    char arrivee[100];
    cout << "------------------------------------------" << endl;
    cout << "RECHERCHE D'UN TRAJET" << endl;
    cout << "Choix de la ville de départ : " << endl;
    cin >> ws;
cin.getline(depart,100);
    cout << "Choix de la ville d'arrivée : " << endl;
    cin.getline(arrivee,100);
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
    char depart[100];
    char arrivee[100];
    char moyen[100];
    cout << "------------------------------------------" << endl;
    cout << "AJOUT D'UN TRAJET SIMPLE" << endl;
    cout << "Choix de la ville de départ : " << endl;
    cin >> ws;
    cin.getline(depart,100);
    cout << "Choix de la ville d'arrivée : " << endl;
    cin.getline(arrivee,100);
    cout << "Choix du moyen de transport : " << endl;
    cin.getline(moyen,100);
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
    char depart[100];
    char arrivee[100];
    char moyen[100];
    cout << "------------------------------------------" << endl;
    cout << "Ajout d'un trajet composé" << endl;
    cout << "Choix de la ville de départ : " << endl;
    cin >> ws;
    cin.getline(depart,100);
    cout << "Choix du premier arrêt : " << endl;
    cin.getline(arrivee,100);
    cout << "Choix du moyen de transport : " << endl;
    cin.getline(moyen,100);
    Collection* listeTrajet = new Collection();
    listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
    cout << "Choix de l'arrêt suivant : " << endl;
    strcpy(depart, arrivee);
    cin.getline(arrivee,100);
    cout << "Choix du moyen de transport : " << endl;
    cin.getline(moyen,100);
    listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
    while(choice != 0){
        strcpy(depart, arrivee);
        cout << "Choix de l'arrêt suivant (0 pour terminer) : " << endl;
        cin.getline(arrivee,100);
        if(strcmp(arrivee, "0") == 0){
            choice = 0;
        } else {
            cout << "Choix du moyen de transport : " << endl;
            cin.getline(moyen,100);
            listeTrajet->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
        }
    }
    TrajetCompose *trajetCompose = new TrajetCompose(listeTrajet);
    c->AjouterFin(trajetCompose);
}

void Catalogue::ExporterTrajets() {

}

void Catalogue::ImporterTrajets() {
    cout << "------------------------------------------" << endl;
    cout << "IMPORTATION DE TRAJETS" << endl;
    cout << "Choix du fichier à importer : " << endl;
    cout << "Voici les fichiers disponibles : " << endl;
    system("ls *.scar");
    char nomFichier[100];
    cin >> ws;
    cin.getline(nomFichier,100);
    cout << "Importation du fichier " << nomFichier << endl;
    ifstream fichier(nomFichier, ios::in);
    if(fichier) {
        char premierLigne[300];
        fichier.getline(premierLigne,20);
        int nbTrajetsSimple = atoi(strtok(premierLigne, ";"));
        int nbTrajetsCompose = atoi(strtok(NULL, ";"));
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
    char ligne[300];
    while(fichier.getline(ligne, 300)){
        char* type = strtok(ligne, ";");
        if(strcmp(type,"S")==0){
            char *depart = strtok(NULL, ";");
            char *arrivee = strtok(NULL, ";");
            char *moyen = strtok(NULL, ";");
            c->AjouterFin(new TrajetSimple(depart, arrivee, moyen));
        }else if(strcmp(type,"C")==0){
            char* nbLigne = strtok(NULL, ";");
            int nbTrajet = atoi(nbLigne);
            Collection* listeTrajet = new Collection();
            for(int i = 0; i < nbTrajet; i++)
            {
                fichier.getline(ligne, 300);
                strtok(ligne, ";");
                char *depart = strtok(NULL, ";");
                char *arrivee = strtok(NULL, ";");
                char *moyen = strtok(NULL, ";");
                cout << "Ajout du trajet simple : " << depart << " " << arrivee << " " << moyen << endl;
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