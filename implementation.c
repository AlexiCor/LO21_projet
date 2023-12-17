#include "implementation.h"
#include "declaration.h"
#include "verification.h"

listeProposition ajoutProposition(int e, listeProposition l) {
    Proposition nouvelleProp = creerRegleVide();
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
       Proposition nouvelleProp = creerRegleVide();
       nouvelleProp->idProposition = e;
       conclusionRegle(l)->suivant=nouvelleProp;
   }

    return l;
}

BC ajoutRegle(Regle r, BC l){
    if(videBase(l)){
        l=r;
    }else{
        Regle p = teteBase(l);
        while(videPremisse(suivant(p))==0){
            p=suivant(p);
        }
        r=suivant(p);
    }
    return l;
}