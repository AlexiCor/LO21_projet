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

    //Création de la première règle
    listeProposition regle1;

    regle1 = creerLPropositionVide();

    regle1 = ajoutProposition(1, regle1);
    regle1 = ajoutProposition(2, regle1);
    regle1 = ajoutProposition(3, regle1);
    regle1 = ajoutConlusion(4, regle1);

    Regle REGLE;
    REGLE.LProposition=regle1;
    REGLE.suivant=NULL;

    baseConnaissance = ajoutRegle(REGLE, baseConnaissance);

    //Création de la deuxième règle
    listeProposition regle2;

    regle2 = creerLPropositionVide();

    regle2 = ajoutProposition(1, regle2);
    regle2 = ajoutProposition(5, regle2);
    regle2 = ajoutConlusion(6, regle2);

    REGLE.LProposition=regle2;
    REGLE.suivant=NULL;

    baseConnaissance = ajoutRegle(REGLE, baseConnaissance);

    //Création de la troisème règle
    listeProposition regle3;

    regle3 = creerLPropositionVide();

    regle3 = ajoutProposition(1, regle3);
    regle3 = ajoutProposition(2, regle3);
    regle3 = ajoutProposition(7, regle3);
    regle3 = ajoutConlusion(8, regle3);

    REGLE.LProposition=regle3;
    REGLE.suivant=NULL;

    baseConnaissance = ajoutRegle(REGLE, baseConnaissance);

    //Création de la troisème règle
    listeProposition regle4;

    regle4 = creerLPropositionVide();

    regle4 = ajoutProposition(4, regle4);
    regle4 = ajoutProposition(6, regle4);
    regle4 = ajoutProposition(8, regle4);
    regle4 = ajoutConlusion(9, regle4);

    REGLE.LProposition=regle4;
    REGLE.suivant=NULL;

    baseConnaissance = ajoutRegle(REGLE, baseConnaissance);

    printf("base de connaissance complete\n");


    //Récupération de la base de faits
    lFaits lbaseFaits;
    lbaseFaits.suivant = NULL;
    lbaseFaits.idFait = 0;
    lFaits *F = &lbaseFaits;

    printf("Veuillez entrer la base de faits, un fait a la fois, puis entrer 0 une fois finis :\n");
    int rep = 1, resultatScanf;
    while (rep != 0){
        resultatScanf = scanf("%d", &rep);
        if(resultatScanf == 1 && rep != 0){ //Vérifie si l'utilisateur a rentré un entier ou autre chose
            if (F->idFait == 0){
                F->idFait = rep;
            }
            else{
                F->suivant = malloc(sizeof(lFaits));
                F->suivant->suivant = NULL;
                F->suivant->idFait = rep;
                F = F->suivant;
            }

        }
        else if(resultatScanf == 1 && rep == 0){
            printf("Saisie de la base de faits terminee\n");
        }
        else{
            printf("Erreur de saisie. Veuillez entrer un entier.\n");
            while (getchar() != '\n'); //Vide le buffer
        }
    }


    F = &lbaseFaits;
    if(F == NULL){
        printf("La base de faits est vide, il n'y a aucune conclusion\n");
        return 0;
    }

    printf("Liste des faits de la base de fait :\n");
    while (F->suivant != NULL){
        printf("%d ", F->idFait);
        F = F->suivant;
    }
    printf("%d ", F->idFait);
    printf("\n");


    //Utilisation du moteur d'inférence

    lFaits lconclusion;
    lconclusion.suivant = NULL;
    lconclusion.idFait = 0;
    lFaits *C = &lconclusion;

    F = &lbaseFaits;
    BC testBaseConnaissance = baseConnaissance;
    lFaits *lF;
    lF = &lbaseFaits;
    while (F != NULL){
        testBaseConnaissance = teteBase(baseConnaissance);
        while (!videBase(testBaseConnaissance)) {
            if(testProposition(F->idFait,testBaseConnaissance->LProposition)){
                printf("la proposition %d se trouve dans une regle\n",F->idFait);
                testBaseConnaissance->LProposition = supprimerProposition(F->idFait, testBaseConnaissance->LProposition);
            }
            if(conclusionRegle(testBaseConnaissance->LProposition) == tetePremisse(testBaseConnaissance->LProposition) && testBaseConnaissance->LProposition->idProposition != 0){
                printf("Une regle est valide, la proposition %d est vraie\n", testBaseConnaissance->LProposition->idProposition);

                while (lF->suivant != NULL){
                    lF = lF->suivant;
                }
                lF->suivant = malloc(sizeof(lFaits));
                lF->suivant->idFait = testBaseConnaissance->LProposition->idProposition;
                lF->suivant->suivant = NULL;
                lF = lF->suivant;

                if (C->idFait == 0){
                    C->idFait = testBaseConnaissance->LProposition->idProposition;
                }else{
                    C->suivant = malloc(sizeof(lFaits));
                    C->suivant->idFait = testBaseConnaissance->LProposition->idProposition;
                    C->suivant->suivant = NULL;
                    C = C->suivant;
                }
                testBaseConnaissance->LProposition->idProposition = 0;
            }
            testBaseConnaissance = testBaseConnaissance->suivant;
        }
        F = F->suivant;
    }



    //Affichage des resultats

    C = &lconclusion;
    if(lconclusion.idFait == 0){
        printf("\nAucune conclusion n'a ete trouvee avec la base de fait donnee\n");
        return 0;
    }
    printf("\nA partir de la base de fait donnee, les conclusions trouvees sont :\n");
    while(C->suivant != NULL){
        printf("%d ", C->idFait);
        C = C->suivant;
    }
    printf("%d\n", C->idFait);


    return 0;
}
