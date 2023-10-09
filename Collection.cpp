//-------------------Réalisation de la classe <Collection> (fichier Collection.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string.h>
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
Collection::Collection()
{
    head = new Cellule;
    // tail=new Cellule;
    head->t = NULL;
    head->suivant = NULL;
    tail = head; // à ce stade la tête et la queue sont les mêmes
}

void Collection::AjouterFin(Trajet *unTrajet)
{
    Cellule *temp = new Cellule;
    temp->t = NULL;
    temp->suivant = NULL;

    tail->t = unTrajet;
    tail->suivant = temp;

    tail = temp;
    //la dernière cellule pointe tjrs vers null et ne contient aucun trajet
}

void Collection::RechercheSimple(char *villeDepart, char *villeArrivee)
{
    // on parcours la collection
    Cellule *courante = head;

    while (courante->suivant != NULL)
    {
        if (strcmp(courante->t->getVilleDepart(), villeDepart) == 0 && strcmp(courante->t->getVilleArrivee(), villeArrivee) == 0)
        {
            cout << "Le trajet de " << villeDepart << " à " << villeArrivee << "existe";
            return;
        }
        courante = courante->suivant;
    }
    cout << "Le trajet de " << villeDepart << " à " << villeArrivee << "n'existe pas";
    return;
}

void Collection::RechercheComplexe(char *villeDepart, char *villeArrivee)
{

}

void Collection::Afficher()
{   
    Cellule* courante=head;
    while (courante->suivant!=NULL)
    {
        courante->t->Afficher(); // pour appliquer une méthode sur un pointeur on utilise des flêches
        courante=courante->suivant;
    }
    
}

//-------------------------------------------- Constructeurs - destructeur
// Collection::Collection ( const Collection & unCollection )
// Algorithme :
// Présentation de l'algorithme
//{
// #if defined (MAP) // MAP : Mise au point
//    cout << "Appel au constructeur de copie de <Collection>" << endl;
// #endif
//    // Code du constructeur de copie
//} //----- Fin de Collection (constructeur de copie)

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées