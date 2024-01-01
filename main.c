#include <stdlib.h>
#include <stdio.h>
#include "declaration.h"
#include "implementation.h"
#include "initialisation.h"
#include "resultat.h"
#include "verification.h"
#include "parcours.h"

int main() {

    //Création des règles / de la base de connaissances
    BC baseConnaissance = creerBaseVide();
    printf("base de connaissance vide creee\n");
    listeProposition regle1;

    regle1 = creerLPropositionVide();
    printf("regle creee\n");

    regle1 = ajoutProposition(1, regle1);
    regle1 = ajoutProposition(2, regle1);
    regle1 = ajoutProposition(3, regle1);
    regle1 = ajoutConlusion(4, regle1);
    printf("regle creee\n");

    Regle REGLE;
    REGLE.LProposition=regle1;
    REGLE.suivant=NULL;

    baseConnaissance = ajoutRegle(REGLE, baseConnaissance);





    //Récupération de la base de faits
    baseFaits lbaseFaits;
    lbaseFaits.suivant = NULL;
    lbaseFaits.idFait = 0;
    baseFaits *F = &lbaseFaits;

    printf("Veuillez entrer la base de faits, un fait a la fois, puis entrer 0 une fois finis :\n");
    int rep = 1, resultatScanf;
    while (rep != 0){
        resultatScanf = scanf("%d", &rep);
        if(resultatScanf == 1 && rep != 0){ //Vérifie si l'utilisateur a rentré un entier ou autre chose
            printf("bien joue\n");
            baseFaits tempF;
            tempF.idFait = rep;
            tempF.suivant = NULL;
            if (F->idFait == 0){
                *F = tempF;
            }
            else{
                F->suivant = &tempF;
            }


        }
        else{
            printf("Erreur de saisie. Veuillez entrer un entier.\n");
            while (getchar() != '\n'); //Vide le buffer
        }
    }

    *F = lbaseFaits;
    if(F == NULL){
        printf("La base de faits est vide, il n'y a aucune conclusion\n");
        return 0;
    }

    printf("Liste des faits de la base de fait :\n");
    while (F->suivant != NULL){
        printf("%d ", F->idFait);
        F = F->suivant;
    }
    printf("\n");


    //Utilisation du moteur d'inférence

    conclusion lconclusion;
    lconclusion.suivant = NULL;
    lconclusion.idFait = 0;
    conclusion *C = &lconclusion;

    int j = 0;
    while (F->suivant != NULL){
        BC testBaseConnaissance = baseConnaissance;
        while (!videBase(testBaseConnaissance)) {


            if(testProposition(F->idFait,testBaseConnaissance->LProposition)){
                printf("la proposition %d est vraie\n",F->idFait);
                supprimerProposition(F->idFait, testBaseConnaissance->LProposition);
            }
            else{
                if(conclusionRegle(testBaseConnaissance->LProposition) == tetePremisse(testBaseConnaissance->LProposition)){
                    printf("La regle est valide, la proposition %d est vraie", testBaseConnaissance->LProposition->idProposition);
                    baseFaits *lF = &lbaseFaits;
                    while (lF->suivant != NULL){
                        lF = lF->suivant;
                    }
                    lF->suivant->idFait = testBaseConnaissance->LProposition->idProposition;
                    lF->suivant->suivant = NULL;
                    C->idFait = testBaseConnaissance->LProposition->idProposition;
                    C = C->suivant;
                }
            }

            testBaseConnaissance = testBaseConnaissance->suivant;
        }
        F = F->suivant;
    }






    //Affichage des resultats

    printf("A partir de la base de fait donnee, voici les propositions trouvées :\n");
    *C = lconclusion;
    if(lconclusion.idFait == 0){
        printf("Aucune conclusion n'a été trouvée");
        return 0;
    }
    printf("Les conclusions trouvées sont :\n");
    while(C->suivant != NULL){
        printf("%d ", C->idFait);
        C = C->suivant;
    }
    printf("%d\n", C->idFait);


    return 0;
}
