#include "initialisation.h"
#include "declaration.h"


Proposition creerRegleVide(){
    Proposition nouvelleProp;
    nouvelleProp.suivant = NULL;
    nouvelleProp.idProposition = NULL;
    return nouvelleProp;
}

Regle creerBaseVide(){
    Regle nouvelleRegle;
    nouvelleRegle.suivant = NULL;
    nouvelleRegle.LProposition = NULL;
    return nouvelleRegle;
}









