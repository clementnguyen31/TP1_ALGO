#include <stdlib.h>
#include <stdio.h>
#include "abr.h"
#include "pile.h"

int main(){
    ppile_t pile = creer_pile();
    if(pile_vide(pile) == 1){
        printf("La pile que nous venons de créer est bien vide - ");
    }

    pnoeud_t noeud;
    empiler(pile,noeud);
    if(pile_vide(pile) == 0){
        printf("La pile que nous venons de créer n'est plus vide - ");
    }

    printf("###### Tout les tests sont passés ######");
    return 1;
}
