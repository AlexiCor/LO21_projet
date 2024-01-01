#include <stdlib.h>
#include "initialisation.h"
#include "declaration.h"
#include <stdio.h>


listeProposition creerLPropositionVide(){
    listeProposition nouvelleProp = (listeProposition)malloc(sizeof(Proposition)); //IMPORTANT
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









