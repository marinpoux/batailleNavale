#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//constantes
    #define DIMENSIONS 10   //dimension d'un plateau
    #define NB_BATEAUX 5    //nombre de bateaux
    #define MOT_MAX 20      //taille max d'un nom de bateau

//types
    typedef enum orientation{vertl, horzl}orientation;

    typedef struct bateau{

        int taille;
        orientation ortn;
        int posX;
        int posY;
    }bateau;

    typedef struct joueur{
        bateau plateau[5];
    }joueur;

//prototype


#endif // DEFINE_H_INCLUDED
