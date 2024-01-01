#include "implementation.h"
#include "declaration.h"
#include "verification.h"
#include "initialisation.h"
#include "parcours.h"
#include <stdlib.h>
#include <stdio.h>

listeProposition ajoutProposition(int e, listeProposition l) {
    listeProposition nouvelleProp = creerLPropositionVide();
    nouvelleProp->idProposition = e;
    nouvelleProp->suivant=NULL;

        if (!videPremisse(l)) {
            printf("ajoutProposition0\n");
            conclusionRegle(l)->suivant = nouvelleProp;
            printf("ajoutProposition1\n");
        } else {
            printf("ajoutProposition2\n");
            l = nouvelleProp;
        }

    printf("ajoutProposition3,%d\n",e);
    return l;
}

listeProposition ajoutConlusion(int e, listeProposition l) {
   if(!videPremisse(l)){
       listeProposition nouvelleProp = creerLPropositionVide();
       nouvelleProp->idProposition = e;
       conclusionRegle(l)->suivant=nouvelleProp;
   }

    return l;
}

BC ajoutRegle(Regle r, BC l){
    Regle *nouvelleRegle = (Regle *)malloc(sizeof(Regle));
    nouvelleRegle->LProposition = r.LProposition;
    nouvelleRegle->suivant = NULL;

    if(videBase(l)){
        l=nouvelleRegle;
    }else{
        Regle *p = teteBase(l);
        while(!videBase(p->suivant)){
            p=p->suivant;
        }
        p->suivant = nouvelleRegle;
    }
    return l;
}