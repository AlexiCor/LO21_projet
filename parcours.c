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


listeProposition conclusionRegle(listeProposition l) {
    printf("VidePremisse1");
    if (videPremisse(l)) {
        printf("conclusionRegle0\n");
        return NULL;
    } else {
        printf("VidePremisse2");
        if (videPremisse(l->suivant)) {
            printf("conclusionRegle5\n");
            return l;

        } else {
            printf("conclusionRegle1\n");
            Proposition *p;
            p = &(*(tetePremisse(l)));
            printf("conclusionRegle2\n");
            while (!videPremisse(p->suivant)){
                printf("conclusionRegle3\n");
                p = p->suivant;
            }
            printf("conclusionRegle4\n");
            return p;
        }
    }
}


BC teteBase(BC l){
    if(videBase(l)){
        return NULL;
    }else{
        return l;
    }
}

