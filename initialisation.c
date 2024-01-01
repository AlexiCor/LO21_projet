#include <stdlib.h>
#include "initialisation.h"
#include "declaration.h"


listeProposition creerRegleVide(){
    listeProposition nouvelleProp;
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









