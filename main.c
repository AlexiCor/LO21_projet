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
    int rep = 1, resultatScanf;
    while (rep != 0){
        resultatScanf = scanf("%d", &rep);
        if (resultatScanf == 1){ //Vérifie si l'utilisateur a rentré un entier ou autre chose
            printf("%d\n", rep);
        }
        else{
            printf("Erreur de saisie. Veuillez entrer un entier.\n");
            while (getchar() != '\n'); //Vide le buffer
        }
    }



    //Utilisation du moteur d'inférence




    //Affichage des resultats




    return 0;
}
