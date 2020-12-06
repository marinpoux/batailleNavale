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

--> cf. recherches.mdp
*/



int main()
{
    //variables
    joueur joueur1={};
    joueur joueur2={};

    //initialisation des joueurs
    initJoueur(&joueur1);
    initJoueur(&joueur2);

    //intro
    introduction();

    //placement des bateaux
    placement(joueur1, joueur2);
//    debug(&joueur1, 1);
//    debug(&joueur2, 2);

    //deroulement de la partie
    partie(&joueur1, &joueur2);

    return 0;
}

extern void debug(joueur *joueurNum, int num){
//but: generer un plateau predetermine pour un joueur
//entree: type joueur, entier correspondant;
//sortie: /
    int tailleBateau[NB_BATEAUX]={5,4,3,3,2};

    printf("\nJOUEUR %d :\n", num);

    for(int i=0; i<NB_BATEAUX; i++){

        joueurNum->placemt[i].taille=tailleBateau[i];
        joueurNum->placemt[i].ortn='h';
        joueurNum->placemt[i].posX=i*2;
        joueurNum->placemt[i].posY=i*2;

        majPlateau(joueurNum, i);
    }

    afficheTab(joueurNum->plateau);
}
