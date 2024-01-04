#ifndef LO21_PROJET_DECLARATION_H
#define LO21_PROJET_DECLARATION_H

typedef struct Proposition{
    int idProposition;
    struct Proposition *suivant;
}Proposition;
typedef Proposition *listeProposition;

typedef struct Regle{
    listeProposition LProposition;
    struct Regle *suivant;
}Regle;
typedef Regle *BC;

typedef struct lFaits{
    int idFait;
    struct lFaits *suivant;
}lFaits;




#endif //LO21_PROJET_DECLARATION_H
