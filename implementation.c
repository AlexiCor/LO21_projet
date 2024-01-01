#include "implementation.h"
#include "declaration.h"
#include "verification.h"
#include "initialisation.h"
#include "parcours.h"
#include <stdlib.h>

listeProposition ajoutProposition(int e, listeProposition l) {
    Proposition *nouvelleProp = creerRegleVide();
    nouvelleProp->idProposition = e;

        if (!videPremisse(l)) {
            conclusionRegle(l)->suivant = nouvelleProp;
        } else {
            l = nouvelleProp;
        }


    return l;
}

listeProposition ajoutConlusion(int e, listeProposition l) {
   if(!videPremisse(l)){
       Proposition *nouvelleProp = creerRegleVide();
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
        while(videPremisse(p->suivant)==0){
            p=p->suivant;
        }
        p->suivant = nouvelleRegle;
    }
    return l;
}