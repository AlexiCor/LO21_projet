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
    printf("base de connaissance vide creee\n");
    BC regle1;

    regle1 = creerBaseVide();
    printf("regle creee\n");

    regle1->LProposition = ajoutProposition(1, regle1->LProposition);
    regle1->LProposition = ajoutProposition(2, regle1->LProposition);
    regle1->LProposition = ajoutProposition(3, regle1->LProposition);
    printf("regle creee\n");

    baseConnaissance = ajoutRegle(*regle1, baseConnaissance);





    //Récupération de la base de faits
    int *baseFaits, i=0;

    printf("Veuillez entrer la base de faits, un fait à la fois, puis entrer 0 une fois finis :\n");
    int rep = 1, resultatScanf;
    while (rep != 0){
        resultatScanf = scanf("%d", &rep);
        if (resultatScanf == 1 && rep != 0){ //Vérifie si l'utilisateur a rentré un entier ou autre chose
            baseFaits[i] = rep;
            i++;
        }
        else{
            printf("Erreur de saisie. Veuillez entrer un entier.\n");
            while (getchar() != '\n'); //Vide le buffer
        }
    }

    printf("Liste des faits de la base de fait :\n");
    for (int j = 0; j < i; ++j) {
        printf("%d\n", baseFaits[j]);
    }




    //Utilisation du moteur d'inférence




    //Affichage des resultats




    return 0;
}
