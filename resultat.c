
#include "resultat.h"
#include "parcours.h"


listeProposition supprimerProposition(int e, listeProposition l){
    listeProposition p = tetePremisse(l);
    if (p->idProposition == e){
        p = p->suivant;
        return p;
    } else {
        while ((p->suivant)->idProposition != e){
            p = p->suivant;
        }
        p->suivant = (p->suivant)->suivant;
    }
    return l;
}
