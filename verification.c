#include "verification.h"
#include "parcours.h"
#include <stdio.h>
#include <stdbool.h>

bool testProposition(int idProp, listeProposition l){
    if(videPremisse(l) || (idProp == conclusionRegle(l)->idProposition)){
        return false;
    } else {
        if (testProposition(idProp, l->suivant) || tetePremisse(l)->idProposition == idProp){
            return true;
        } else {
            return false;
        }
    }
}


bool videPremisse(listeProposition l){
    if (l == NULL||l->idProposition == 0){
        //la premisse est vide
        return true;
    }else{
            //la premisse n'est pas vide
            return false;
        }


}


bool videBase(BC l){
    if (l == NULL){
        return true;
    } else {
        if (l->LProposition == NULL){
            return true;
        }
        else{
            return false;
        }
    }
}

