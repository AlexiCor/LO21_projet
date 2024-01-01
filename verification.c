
#include "verification.h"
#include "parcours.h"
#include <stdio.h>
#include <stdbool.h>

bool testProposition(int idProp, listeProposition l){
    if(videPremisse(l) || idProp == conclusionRegle(l)){
        return 0;
    } else {
        if (testProposition(idProp, l->suivant) == 1 || (tetePremisse(l))->idProposition == idProp){
            return 0;
        } else {
            return 1;
        }
    }
}


bool videPremisse(listeProposition l){
    if (l == NULL){
        return 1;
    } else {
        return 0;
    }
}


bool videBase(BC l){
    if (l == NULL){
        return 1;
    } else {
        return 0;
    }
}

