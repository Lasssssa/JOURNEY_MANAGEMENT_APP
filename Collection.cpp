//-------------------Réalisation de la classe <Collection> (fichier Collection.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Collection.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Collection::Méthode ( liste de paramètres )
// Algorithme :
// Présentation de l'algorithme
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Collection::Collection ( ){
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
    head = nullptr;
    tail = nullptr;
} //----- Fin de Collection

Collection::~Collection ( ){
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
    Cellule* current = head;
    while(current != nullptr){
        Cellule* next = current->suivant;
        delete current->t;
        delete current;
        current = next;
    }
} //----- Fin de ~Collection

void Collection::AjouterDebut(Trajet* unTrajet){
#ifdef MAP
    cout << "Appel à la méthode AjouterDebut de <Collection>" << endl;
#endif
    Cellule* newCellule = new Cellule;
    newCellule->t = unTrajet;
    newCellule->suivant = head;
    head = newCellule;
    if(tail == nullptr){
        tail = newCellule;
    }
} //----- Fin de AjouterDebut

void Collection::AjouterFin(Trajet* unTrajet){
#ifdef MAP
    cout << "Appel à la méthode AjouterFin de <Collection>" << endl;
#endif
    Cellule* newCellule = new Cellule;
    newCellule->t = unTrajet;
    newCellule->suivant = nullptr;
    if(tail != nullptr){
        tail->suivant = newCellule;
    }
    tail = newCellule;
    if(head == nullptr){
        head = newCellule;
    }
} //----- Fin de AjouterFin


Cellule* Collection::GetHead(){
    return head;
}

Cellule* Collection::GetTail(){
    return tail;
}

void Collection::Afficher(){
    Cellule* current = head;
    while(current != nullptr){
        current->t->Afficher();
        current = current->suivant;
    }
}

void Collection::Rechercher(char* villeDepart, char* villeArrivee){
    cout << "Recherche de trajets" << endl;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées