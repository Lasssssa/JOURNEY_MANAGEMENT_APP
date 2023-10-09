#include <iostream>

//Initial commit : 1
#include "Catalogue.h"

using namespace std;

int main(){

    Catalogue* catalogue = new Catalogue();
    cout << "Bienvenue dans le catalogue de trajets" << endl;
    catalogue->Menu();
    delete catalogue;

    return 0;
}