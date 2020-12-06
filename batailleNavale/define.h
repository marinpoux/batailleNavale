#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//constantes
    #define DIMENSIONS 10   //dimension d'un plateau
    #define NB_BATEAUX 5    //nombre de bateaux
    #define MOT_MAX 21      //taille max d'un nom de bateau

//types
    typedef enum orientation{v,h}orientation;

    typedef struct coordonnees{
    //a integrer dans bateau...

        int posX;
        int posY;
    }coordonnees;

    typedef struct bateau{

        //char nom[MOT_MAX];
        int taille;
        orientation ortn;
        int posX;
        int posY;
        //coordonnees coord;
    }bateau;

    typedef struct joueur{

        bateau placemt[NB_BATEAUX];
        int plateau[DIMENSIONS][DIMENSIONS];
        char avancement[DIMENSIONS][DIMENSIONS];
    }joueur;

//prototype
    extern initCoord(coordonnees *coord);
    extern void initTab(int tab[DIMENSIONS][DIMENSIONS]);
    extern void initTabChar(char tab[DIMENSIONS][DIMENSIONS]);
    extern void afficheTab(int tab[DIMENSIONS][DIMENSIONS]);
    extern void afficheTabChar(char tab[DIMENSIONS][DIMENSIONS]);
    extern void initJoueur(joueur *joueurNum);
    extern void initBateau(joueur *joueurNum, int ordre);
    extern void introduction();
    //extern void placement(joueur *joueur1, joueur *joueur2);
    extern void debug(joueur *joueurNum, int num);
    extern void placeJoueur(joueur *joueurNum, int num);
    extern void placeBateau(joueur *joueurNum, int ordre);
    extern void lectureOrtn(joueur *joueurNum, int ordre);
    extern void lectureCoord(joueur *joueurNum, int ordre);
    extern int verifCoord(joueur *joueurNum, int xTemp, int yTemp, int ordre);
    extern void majPlateau(joueur *joueurNum, int ordre);

    extern void partie(joueur *joueur1, joueur *joueur2);
    extern int manche(int num, joueur *jJoueur, joueur *jAdvers);
    extern void saisieCoord(coordonnees *coord);
    extern void comparePlateau(int avancementJ[DIMENSIONS][DIMENSIONS], int plateauAd[DIMENSIONS][DIMENSIONS], coordonnees *coord);
    extern int verifVictoire(int tabAdvers[DIMENSIONS][DIMENSIONS], int num);

#endif // DEFINE_H_INCLUDED
