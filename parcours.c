//
// Created by alexi on 16/12/2023.
//

#include "parcours.h"
#include "verification.h"
#include <stdio.h>

Proposition tetePremisse(listeProposition l){
    if (!videPremisse(l)){
        return l;
    } else {
        return NULL;
    }
}


Proposition conclusionRegle(listeProposition l){
    if (videPremisse(l)) {
        return NULL;
    } else {
        Proposition p = tetePremisse(l);
        while (videPremisse((p.suivant).suivant)){
            p = p.suivant;
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

