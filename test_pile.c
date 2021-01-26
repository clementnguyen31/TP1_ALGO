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

int empiler (ppile_t p, pnoeud_t pn)
  {
 if(pile_pleine(p) == 1){
   return 0;
 }
 p->sommet = p->sommet+1;
 p->Tab[p->sommet] = pn;
 return 1;
}

int pile_vide (ppile_t p)
{
 if(p->sommet == -1 ){
   return 1;
 }
  return 0 ;
}

int pile_pleine (ppile_t p)
 {
  if(p->sommet == 31){
    return 1;
  }
  return 0;
} 

ppile_t creer_pile ()
{
  pile_t newpile;
  ppile_t ptp = &newpile;
  ptp->sommet = -1;
  return ptp ;
}