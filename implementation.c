#include "implementation.h"
#include "declaration.h"

listeProposition ajoutProposition(int e, listeProposition l) {
    Proposition *nouvelleProp = creerRegleVide();
        nouvelleProp->idProposition = e;

        if (videPremisse(l) != TRUE) {

            conclusionRegle(l)->suivant = nouvelleProp;
        } else {
            l = nouvelleProp;
        }


    return l;
}
