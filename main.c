#include <stdlib.h>
#include <stdio.h>
#include "declaration.h"
#include "implementation.h"
#include "initialisation.h"
#include "resultat.h"
#include "verification.h"

int main() {

    //Création des règles / de la base de connaissances
    BC baseConnaissance = creerBaseVide();
    Proposition regle1 = creerRegleVide();
    ajoutRegle(regle1, baseConnaissance)






    //Récupération de la base de faits
    int rep = 1;
    while (rep != 0){
        scanf("%d", &rep);
        printf("%d", rep);
    }



    //Utilisation du moteur d'inférence




    //Affichage des resultats




    return 0;
}
