//-------------------Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher()
{
    cout << "------------Trajet composé--------------" << endl;
    listeTrajets->Afficher();
    cout << "----------------------------------------" << endl;

}

string & TrajetCompose::getVilleDepart()
{
    return this->listeTrajets->GetHead()->t->getVilleDepart();
}

string & TrajetCompose::getVilleArrivee()
{
    return this->listeTrajets->GetTail()->t->getVilleArrivee();
}

void TrajetCompose::Ecrire(ofstream& fichier)
{
    fichier << "C;" << this->listeTrajets->GetTaille() << ";" << listeTrajets->GetHead()->t->getVilleDepart() << ";" << listeTrajets->GetTail()->t->getVilleArrivee() << endl;
    Cellule* current = listeTrajets->GetHead();
    while(current != nullptr){
        current->t->Ecrire(fichier);
        current = current->suivant;
    }
    
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(Collection* newListeTrajets) : Trajet()
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    listeTrajets = newListeTrajets;
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose (){
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete listeTrajets;
} //----- Fin de ~TrajetCompose

TrajetCompose* TrajetCompose::Copie()
// Algorithme : On parcourt la liste de trajets et on copie chaque trajet dans une nouvelle liste
// On retourne un nouveau trajet composé avec la nouvelle liste
{
    Collection* newListeTrajets = new Collection();
    Cellule* current = listeTrajets->GetHead();
    while(current != nullptr){
        Trajet* currentTrajet = current->t;
        newListeTrajets->AjouterFin(currentTrajet->Copie());
        current = current->suivant;
    }
    return new TrajetCompose(newListeTrajets);
}
//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes protégées