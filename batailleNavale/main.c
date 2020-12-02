#include "define.h"

/*
PLAN
- definir types dans main.c:
    - bateau{int taille; int ortn; int posX; int posY}bateau
    - joueur{int score; char plateau[DIMENSIONS][DIMENSIONS]
- variables:
    - tableau char colonnes={" ABCDEFGHIJ"}
    - tableau char lignes={'1','2','3','4','5','6','7','8','9','10'} qqch comme ca
    - tableau char plateau[DIMENSIONS][DIMENSIONS]
1) initialisation:
    - joueur joueur1=NULL; joueur joueur2=NULL; qqch comme ca?
    -
2) intro:
    - nom du jeu
    - regles
3) placement
4) jeu

*/



int main()
{
    //variables
    joueur joueur1={};
    joueur joueur2={};

    initJoueur(&joueur1);



    return 0;
}
