#include "define.h"

extern initCoord(coordonnees *coord){

    coord->posX=0;
    coord->posY=0;
}

extern void initTab(int tab[DIMENSIONS][DIMENSIONS]){
//but: initialisation des tableaux a 0
//entree: un tableau
//sortie: un tableau rempli de 0

    for(int i=0; i<DIMENSIONS;i++){
        for (int j=0; j<DIMENSIONS;j++){

            tab[i][j]=0;
        }
    }
}

extern void initTabChar(char tab[DIMENSIONS][DIMENSIONS]){
//but: initialisation des tableaux a 0
//entree: un tableau
//sortie: un tableau rempli de 0

    for(int i=0; i<DIMENSIONS;i++){
        for (int j=0; j<DIMENSIONS;j++){

            tab[i][j]=' ';
        }
    }
}

extern void afficheTab(int tab[DIMENSIONS][DIMENSIONS]){
//but: afficher un tableau de caracteres avec printf
//entree: un tableau de caractere
//sortie: /

    printf("  0 1 2 3 4 5 6 7 8 9\n---------------------\n");

    for(int i=0; i<DIMENSIONS;i++){

        printf("%d|", i);

        for (int j=0; j<DIMENSIONS;j++){

            printf("%d ", tab[i][j]);
        }

        printf("\n");
    }
}

extern void afficheTabChar(char tab[DIMENSIONS][DIMENSIONS]){
//but: afficher un tableau de caracteres avec printf
//entree: un tableau de caractere
//sortie: /

    printf("  0 1 2 3 4 5 6 7 8 9\n---------------------\n");

    for(int i=0; i<DIMENSIONS;i++){

        printf("%d|", i);

        for (int j=0; j<DIMENSIONS;j++){

            printf("%c ", tab[i][j]);
        }

        printf("\n");
    }
}

extern void initJoueur(joueur *joueurNum){
//but: initialiser les joueurs a 0
//entree: un type joueur
//sortie: un type joueur initialise

    for(int i=0;i<NB_BATEAUX;i++){

        initBateau(joueurNum, i);
    }

    initTab(joueurNum->plateau);
    initTabChar(joueurNum->avancement);
}

extern void initBateau(joueur *joueurNum, int ordre){
//but: initialiser le type bateau d'un type joueur
//entree: type bateau
//sortie: type bateau initialise

    joueurNum->placemt[ordre].taille=-1;
    joueurNum->placemt[ordre].taille=0;
    joueurNum->placemt[ordre].taille=0;
}


extern void introduction(){
//but: afficher les regles et une ntroduction au jeu
//entree: /
//sortie: /

    printf("BATAILLE NAVALE\n");
}


extern void placement(joueur *joueur1, joueur *joueur2){
//but: appeler chaque joueur a placer ses bateaux
//entree: les deux types joueurs
//sortie: les deux types joueurs avec leurs types bateau a jour

    printf("PLACEMENT DES BATEAUX\n");
    placeJoueur(joueur1, 1);
    placeJoueur(joueur2, 2);

}

extern void placeJoueur(joueur *joueurNum, int num){
//but: placer chaque bateau du joueur
//entree: type joueur
//sortie: type joueur avec type bateau a jour

    printf("\nJOUEUR %d :\n", num);

    for(int i=0; i<NB_BATEAUX; i++){

        placeBateau(joueurNum, i);
    }
}

extern void placeBateau(joueur *joueurNum, int ordre){
//but: placer un bateau
//entree: type joueur, emplacement dans la boucle d'iteration
//sortie: type joueur avec type bateau a jour (+1 bateau)
    char *typeBateau[MOT_MAX]={"porte-avions","croiseur",
            "contre-torpilleur 1","contre-torpilleur 2","torpilleur"
            };
    int tailleBateau[NB_BATEAUX]={5,4,3,3,2};

    printf("Placement du %s ; ce bateau occupe %d cases.\n", typeBateau[ordre], tailleBateau[ordre]);

    //joueurNum->placemt[ordre].nom=typeBateau;
    joueurNum->placemt[ordre].taille=tailleBateau[ordre];

    lectureOrtn(joueurNum, ordre);

    lectureCoord(joueurNum, ordre);

    majPlateau(joueurNum, ordre);

    afficheTab(joueurNum->plateau);
}

extern void lectureOrtn(joueur *joueurNum, int ordre){
//but: lire et verifier l'orientation du bateau
//entree: type joueur, ordre dans la boucle
//sortie: /
    char ortnTemp;

    do {
        printf("Quelle est l'orientation du bateau ?\nv : vertical - h : horizontal\n");
        scanf("%c", &ortnTemp);
        fflush(stdin);
    } while((ortnTemp!='v') && (ortnTemp!='h'));

    joueurNum->placemt[ordre].ortn=ortnTemp;
}

extern void lectureCoord(joueur *joueurNum, int ordre){
//but: lire les coordonnees du bateau
//entree: type joueur, ordre dans la boucle
//sortie: /
    int xTemp;
    int yTemp;

    int ok=0;

    do{
        printf("Quelles sont les coordonnees du bateau ?\n");
        printf("Colonne (0 a 9) : "); scanf("%d", &xTemp);fflush(stdin);
        printf("Ligne (0 a 9) : "); scanf("%d", &yTemp);fflush(stdin);

        //printf("colonne %d ligne %d ok %d\n", xTemp, yTemp, ok);

        ok=verifCoord(joueurNum, xTemp, yTemp, ordre);
    }
    while(ok != 1);

    //printf("colonne %d ligne %d\n", xTemp, yTemp);

    joueurNum->placemt[ordre].posX=xTemp;
    joueurNum->placemt[ordre].posY=yTemp;
}

extern int verifCoord(joueur *joueurNum, int xTemp, int yTemp, int ordre){
//but: verifier la validite des coordonnes saisies
//entree: type joueur, coordonnes entrees, ordre dans la boucle
//sortie: un entier (0: coordonnes non valides; 1: coordonnes valides)
    orientation oTemp=joueurNum->placemt[ordre].ortn;
    int taille=joueurNum->placemt[ordre].taille;
    int verif=0;

    //char *colonnes={"abcdefghijABCDEFGHIJ"};
    //char *lignes={"0123456789"};

    if ((xTemp >= 0) && (xTemp <DIMENSIONS) && (yTemp >= 0) && (yTemp <DIMENSIONS)){

        if(oTemp == 'h'){

            if(xTemp+taille>=DIMENSIONS){

                printf("Le bateau depasse du plateau !\n");
                return 0;
            } else {

                for(int i=xTemp; i<(xTemp+taille);i++){

                    if(joueurNum->plateau[yTemp][i]!=0){

                        verif++;
                    }
                }

                if(verif!=0){

                    printf("L\'emplacement est deja occupe !\n");
                    return 0;
                } else {

                    printf("Le bateau a ete place aux coordonnees %d-%d.\n", xTemp, yTemp);
                    return 1;
                }
            }

        } else if(oTemp == 'v'){

            if(yTemp+taille>=DIMENSIONS){

                printf("Le bateau depasse du plateau !\n");
                return 0;
            } else {

                for(int i=yTemp; i<(yTemp+taille);i++){

                    if(joueurNum->plateau[i][xTemp]!=0){

                        verif++;
                    }
                }

                if(verif!=0){

                    printf("L\'emplacement est deja occupe !\n");
                    return 0;
                } else {

                    printf("Le bateau a ete place aux coordonnees %d-%d.\n", xTemp, yTemp);
                    return 1;
                }
            }
        }

    } else {

        printf("Les coordonnes entrees ne correspondent pas a l\'intervalle demande !");
        return 0;
    }
}

extern void majPlateau(joueur *joueurNum, int ordre){
//but: mettre a jour le placement des bateaux sur le plateau
//entree: type joueur, ordre dans la boucle
//sortie: /
    orientation oTemp=joueurNum->placemt[ordre].ortn;
    int taille=joueurNum->placemt[ordre].taille;
    int xTemp=joueurNum->placemt[ordre].posX;
    int yTemp=joueurNum->placemt[ordre].posY;

    if(oTemp == 'h'){

        for(int i=xTemp; i<(xTemp+taille);i++){

            joueurNum->plateau[yTemp][i]=taille;
        }
    } else if(oTemp == 'v'){
        for(int i=yTemp; i<(yTemp+taille);i++){

            joueurNum->plateau[i][xTemp]=taille;
        }
    }
}
