#include <stdlib.h>
#include "initialisation.h"
#include "declaration.h"


Proposition *creerRegleVide(){
    Proposition *nouvelleProp=(Proposition *)malloc(sizeof(Proposition));
    nouvelleProp->suivant = NULL;
    nouvelleProp->idProposition = 0;
    return nouvelleProp;
}

Regle *creerBaseVide(){
    Regle *nouvelleRegle=(Regle *)malloc(sizeof(Regle));
    nouvelleRegle->suivant = NULL;
    nouvelleRegle->LProposition = NULL;
    return nouvelleRegle;
}









