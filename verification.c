
#include "verification.h"
#include "parcours.h"
#include <stdio.h>
#include <stdbool.h>

bool testProposition(int idProp, listeProposition l){
    if(videPremisse(l) || idProp == conclusionRegle(l)){
        return false;
    } else {
        if (testProposition(idProp, l->suivant) || tetePremisse(l).idProposition == idProp){
            return false;
        } else {
            return true;
        }
    }
}


bool videPremisse(listeProposition l){
    if (l == NULL){
        return true;
    } else {
        return false;
    }
}


bool videBase(BC l){
    if (l == NULL){
        return true;
    } else {
        return false;
    }
}

