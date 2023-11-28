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
                menuExport();
                break;
            case 6:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Erreur de saisie" << endl;
                break;
        }
    } while (choix != 4);
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
    cout << "4. Importer les trajets" << endl;
    cout << "5. Exporter les trajets" << endl;
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

    //CREATION DU FICHIER

    char nomDuFichier[100];

    cout << "-----------------------------------------" << endl;
    cout << "EXPORTATION DES TRAJETS" << endl;
    cout << "Comment souhaitez-vous nommer votre fichier ?" <<endl;
    cin >> nomDuFichier;
    strcat(nomDuFichier,".scar");
    ofstream fichier(nomDuFichier,ios::out);
    
    Cellule* current = c->GetHead();
    while(current != nullptr){
        current->t->Ecrire(fichier);
        current = current->suivant;
    }


    fichier.close();


}

void Catalogue::ImporterTrajets() {

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