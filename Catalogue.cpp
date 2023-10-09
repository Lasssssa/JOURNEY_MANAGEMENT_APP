//-------------------Réalisation de la classe <Catalogue> (fichier Catalogue.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste de paramètres )
// Algorithme :
// Présentation de l'algorithme
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(){
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    c = new Collection();
}

Catalogue::~Catalogue(){
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
    delete c;
}

void Catalogue::Afficher(){
    c->Afficher();
}

void Catalogue::AjouterTrajet(Trajet* unTrajet){
    c->AjouterFin(unTrajet);
}

void Catalogue::Menu() {
    int choix;
    do {
        cout << "1. Ajouter un trajet" << endl;
        cout << "2. Afficher le catalogue" << endl;
        cout << "3. Rechercher un trajet" << endl;
        cout << "4. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            choix = 0;
        }
        switch (choix) {
            case 1:
//                AjouterTrajet();
                break;
            case 2:
//                Afficher();
                break;
            case 3:
//                RechercherTrajet();
                break;
            case 4:
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