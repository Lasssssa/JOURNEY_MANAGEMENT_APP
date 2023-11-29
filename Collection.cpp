//-------------------Réalisation de la classe <Collection> (fichier Collection.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Collection.h"
#include <cstring>

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
Collection::Collection ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
    head = nullptr;
    tail = nullptr;
} //----- Fin de Collection

Collection::~Collection ( )
// Algorithme : On parcours la collection
// On supprime le trajet courant
// On supprime la cellule courante
{
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

void Collection::AjouterDebut(Trajet* unTrajet)
// Algorithme : On crée une nouvelle cellule
// On ajoute le trajet à la cellule
// On ajoute la cellule au début de la collection
// Si la queue est nulle, on l'initialise à la cellule
{
    Cellule* newCellule = new Cellule;
    newCellule->t = unTrajet;
    newCellule->suivant = head;
    head = newCellule;
    if(tail == nullptr){
        tail = newCellule;
    }
} //----- Fin de AjouterDebut

void Collection::AjouterFin(Trajet* unTrajet)
// Algorithme : On crée une nouvelle cellule
// On ajoute le trajet à la cellule
// On ajoute la cellule à la fin de la collection
// Si la tête est nulle, on l'initialise à la cellule
{
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


Cellule* Collection::GetHead()
{
    return head;
}

Cellule* Collection::GetTail()
{
    return tail;
}

void Collection::Afficher()
{
    Cellule* current = head;
    while(current != nullptr){
        current->t->Afficher();
        current = current->suivant;
    }
}

int Collection::GetTaille(){
    int taille = 0;
    Cellule* current = head;
    while(current != nullptr){
        taille++;
        current = current->suivant;
    }
    return taille;
}

void Collection::RechercheSimple(const string & villeDepart, const string & villeArrivee)
// Algorithme : On parcours la collection
// Si la ville de départ et la ville d'arrivée du trajet courant sont les villes recherchées, on affiche le trajet
// Sinon, on parcours la collection à partir de la cellule suivante
{
    // on parcours la collection
    Cellule *courante = head;
    bool trouve = false;
    if(courante == NULL){
        cout << "La collection est vide" << endl;
        return;
    }
    while (courante->suivant != NULL)
    {
        if(courante->t->getVilleDepart() == villeDepart && courante->t->getVilleArrivee() == villeArrivee){
            courante->t->Afficher();
            trouve = true;
        }
        courante = courante->suivant;
    }
    if(courante->t->getVilleDepart() == villeDepart && courante->t->getVilleArrivee() == villeArrivee){
        courante->t->Afficher();
        trouve = true;
    }
    if(!trouve){
        cout << "Le trajet de " << villeDepart << " à " << villeArrivee << " n'existe pas" << endl;
    }
    return;
}

void Collection::RechercheComplexe(const string & villeDepart, const string & villeArrivee)
// Algorithme : On parcours la collection
// Si la ville de départ du trajet courant est la ville de départ recherchée, on crée une nouvelle collection
// On ajoute le trajet courant à la collection
// On appelle la méthode récursive avec la nouvelle collection
{
    Cellule *courante = head;
    while(courante != nullptr){
        if(courante->t->getVilleDepart()== villeDepart){
            Collection* collection = new Collection();
            collection->AjouterFin(courante->t->Copie());
            RechercheComplexeRecursive(head,courante, villeArrivee, collection);
            delete collection;
        }
        courante = courante->suivant;
    }
}

void RechercheComplexeRecursive(Cellule *head, Cellule *courante, const string & villeArrivee, Collection* collection)
// Algorithmes : On parcours la collection
// Si la ville d'arrivée du trajet courant est la ville d'arrivée recherchée, on affiche la collection
// Sinon, on parcours la collection à partir de la cellule suivante
{
    if(courante->t->getVilleArrivee() == villeArrivee){
        collection->Afficher();
        return;
    }
    Cellule* current = head;
    while(current != nullptr){
        if(current->t->getVilleDepart() == courante->t->getVilleArrivee()){
            if(!isPresent(current->t, collection)) {
                collection->AjouterFin(current->t->Copie());
                RechercheComplexeRecursive(head, current, villeArrivee, collection);
                collection->GetTail()->suivant = nullptr;
            }
        }
        current = current->suivant;
    }
}

bool isPresent(Trajet* t, Collection* collection)
// Algorithme : On parcours la collection
// Si la ville de départ et la ville d'arrivée du trajet courant sont les villes du trajet recherché, on retourne vrai
// Sinon, on parcours la collection à partir de la cellule suivante
// Si on a parcouru toute la collection sans trouver le trajet, on retourne faux
{
    Cellule* current = collection->GetHead();
    while(current != nullptr){
        if(current->t->getVilleDepart() == t->getVilleDepart() && current->t->getVilleArrivee() == t->getVilleArrivee()){
            return true;
        }
        current = current->suivant;
    }
    return false;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées