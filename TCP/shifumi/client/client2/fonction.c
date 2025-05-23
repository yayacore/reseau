#pragma once
#include "global.h"

/**
 * @param player1->choix Le choix du joueur 1 PIERRE(1), FEUILLE(2) ou CISEAUX(3)
 * @param player2->choix Le choix du joueur 2 PIERRE(1), FEUILLE(2) ou CISEAUX(3)
 */

void updateScore(struct player *player1,struct player *player2, int round) {
    
    // Condition de victoire du joueur 1
    round = 0;
    if((player1->choix == PIERRE && player2->choix == CISEAUX) || (player1->choix == FEUILLE && player2->choix == PIERRE) || (player1->choix == CISEAUX && player2->choix == FEUILLE)) {
    
        player1->victoire ++;
        printf("🏆\n");
    
    // Condition de victoire du joueur 2
    }else if ((player2->choix == PIERRE && player1->choix == CISEAUX) || (player2->choix == FEUILLE && player1->choix == PIERRE) || (player2->choix ==  CISEAUX && player1->choix == FEUILLE)) {
       
        player2->victoire ++;
        printf("🏆\n");
    }
    // En cas d'égalité
    if (player1->choix == player2->choix) {
        printf ("Ex- aequo\n");
    }

    return;
}

// fonction qui prend en compte les != façons d'ortographier la saisie
int writingChoix(char *choix) {

    if(strcmp(choix, "1") == 0 || strcmp(choix, "pierre") == 0 || strcmp(choix, "p") == 0) {return PIERRE;}
   
    if(strcmp(choix, "2") == 0 || strcmp(choix, "feuille") == 0 || strcmp(choix, "f") == 0) {return FEUILLE;}

    if(strcmp(choix, "3") == 0 || strcmp(choix, "ciseaux") == 0 || strcmp(choix, "c") == 0) {return CISEAUX;}

    return -1;
}

void printScore(char *score, struct player player1, struct player player2) {

    sprintf(score,
    "\n%s\n choix : %d\n victoire :%d\n"
    "\n%s\n choix : %d\n victoire :%d\n",
    player1.nom, player1.choix, player1.victoire,
    player2.nom, player2.choix, player2.victoire);
}
