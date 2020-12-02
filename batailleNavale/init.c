#include "define.h"

extern void initBateau(int ordre){


}

extern void initJoueur(joueur *joueurNum){


}



extern void placeBateau(int ordre){
    char typeBateau[NB_BATEAUX][MOT_MAX]={"porte-avions",
            "croiseur",
            "contre-torpilleur",
            "contre-torpilleur",
            "torpilleur"};
    int tailleBateau[NB_BATEAUX]={5,4,3,3,2};



}

extern void placeJoueur(joueur *joueurNum){

    for(int i=0; i<NB_BATEAUX; i++){

        placeBateau(i);
    }
}
