//
// Created by alexi on 16/12/2023.
//

#include "parcours.h"
#include "verification.h"
#include "initialisation.h"
#include <stdio.h>

listeProposition tetePremisse(listeProposition l){
    if (!videPremisse(l)){
        return l;
    } else {
        return NULL;
    }
}


listeProposition conclusionRegle(listeProposition l){
    if (videPremisse(l)) {
        return NULL;
    } else {
        Proposition *p = tetePremisse(l);
        while (videPremisse((p->suivant)->suivant)){
            p = p->suivant;
        }
        return p;
    }
}


BC teteBase(BC l){
    if(videBase(l)){
        return NULL;
    }else{
        return l;
    }
}

