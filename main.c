#include <stdlib.h>
#include <stdio.h>
#include "declaration.h"
#include "implementation.h"
#include "initialisation.h"
#include "resultat.h"
#include "verification.h"

int main() {

    //Création des règles / de la base de connaissances
    BC baseConnaissance;
    *baseConnaissance = creerBaseVide();
    Proposition regle1;
    *regle1 = creerRegleVide();

    regle1 = ajoutProposition(1, regle1);
    regle1 = ajoutProposition(2, regle1);
    regle1 = ajoutProposition(3, regle1);
    regle1 = ajoutConlusion(4, regle1);

    ajoutRegle(regle1, baseConnaissance);






    //Récupération de la base de faits
    printf("Veuillez entrer la base de faits, un fait à la fois, puis entrer 0 une fois finis :\n");
    int rep = 1;
    while (rep != 0){
        scanf("%d", &rep);
        printf("%d", rep);
    }



    //Utilisation du moteur d'inférence




    //Affichage des resultats




    return 0;
}
