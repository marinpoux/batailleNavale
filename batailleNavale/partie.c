#include "define.h"

extern void partie(joueur *joueur1, joueur *joueur2){
//but: jouer la partie
//entree: les deux types joueurs
//sortie: /
    int fin=0;

    printf("\nDEBUT DE LA PARTIE\n");

    while(fin!=1){

        fin=manche(1, &joueur1, &joueur2);

        if(fin!=1){

            fin=manche(2, &joueur2, &joueur1);
        }
    }
}

extern int manche(int num, joueur *jJoueur, joueur *jAdvers){
//but: jouer un tour/une manche (une partie=2tours)
//entree: les deux types joueurs
//sortie: un entier
    coordonnees coord={};
    int fin=0;

    //afficheTab(jJoueur->plateau);

    initCoord(&coord);

    printf("\nJOUEUR %d :\n", num);

    afficheTabChar(jJoueur->avancement);

    saisieCoord(&coord);

    comparePlateau(jJoueur->avancement, jAdvers->plateau, &coord);

    fin=verifVictoire(jAdvers->plateau, num);

    return fin;
}

extern void saisieCoord(coordonnees *coord){
//but: lire et verifier les coordonnees entrees par le joueur
//entree: un type coordonnees
//sortie: /
    int xTemp;
    int yTemp;

    do{
        printf("Quelles coordonnees voulez-vous tirer ?\n");
        printf("Colonne (0 a 9) : "); scanf("%d", &xTemp);fflush(stdin);
        printf("Ligne (0 a 9) : "); scanf("%d", &yTemp);fflush(stdin);

        if((xTemp < 0) || (xTemp >=DIMENSIONS) || (yTemp < 0) || (yTemp >=DIMENSIONS)){

            printf("Les coordonnes entrees ne correspondent pas a l\'intervalle demande !");
        }
    }
    while((xTemp < 0) || (xTemp >=DIMENSIONS) || (yTemp < 0) || (yTemp >=DIMENSIONS));

    coord->posX=xTemp; //printf("x:%d", xTemp);
    coord->posY=yTemp; //printf("y:%d\n", yTemp);
}

extern void comparePlateau(int avancementJ[DIMENSIONS][DIMENSIONS], int plateauAd[DIMENSIONS][DIMENSIONS], coordonnees *coord){
//but: comparer les coordonnes saisies au plateau du joueur + mise a jour des plateaux
//entree: le type coordonnees contenant les coordonnes saisies, les deux tableaux a comparer
//sortie: /
    int xTemp=coord->posX;
    int yTemp=coord->posY;

    //afficheTab(plateauAd);
    printf("contenu : %d\n", plateauAd[yTemp][xTemp]);

    if(plateauAd[yTemp][xTemp]>0){

        printf("Touche !!\n");
        plateauAd[yTemp][xTemp]=-1;
        avancementJ[yTemp][xTemp]='X';
    } else if (plateauAd[yTemp][xTemp]==0){

        printf("Dommage ! Il n'y avait rien a ces coordonnes !\n");
        avancementJ[yTemp][xTemp]='/';
    } else {

        printf("Vous aviez deja tire ici !\n");
    }
}

extern int verifVictoire(int tabAdvers[DIMENSIONS][DIMENSIONS], int num){
//but: verifier si les condistions de victoires sont remplies par le contenu du plateau adverse
//entree: le tableau du plateau adverse, un entier (le joueur en cours)
//sortie: un entier
    int compteur=0;

    for(int i=0; i<DIMENSIONS;i++){
        for (int j=0; j<DIMENSIONS;j++){

            if (tabAdvers[i][j]>0){

                compteur++;
            }
        }
    }

    if (compteur==0){

        printf("Victoire du joueur %d ! Vous avez coule tous les bateaux de l'adversaire !\n", num);
        return 1;
    } else {

        return 0;
    }
}
