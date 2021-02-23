#include <stdlib.h>
#include "abr.h"
#include "pile.h"

ppile_t creer_pile ()
{
  pile_t *p = malloc(sizeof(pile_t));
  p->sommet = -1;
  return p ;
}

int detruire_pile (ppile_t p)
{
  free(p);
  return 1;
}  

int pile_vide (ppile_t p)
{
 if(p->sommet < 0 ){
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

pnoeud_t depiler (ppile_t p)
{
 pnoeud_t temp = p->Tab[p->sommet];
 p->sommet = p->sommet-1;

 return temp;
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
