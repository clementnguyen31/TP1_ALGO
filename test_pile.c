#include <stdlib.h>
#include <stdio.h>
#include "abr.h"
#include "pile.h" 


   void aide() {  
   fprintf(stderr,"\n\nMenu principal :\n"); 
   fprintf(stderr,"\n 1 : Empiler \n");  
   fprintf(stderr,"\n 2 : Dépiler \n"); 
   fprintf(stderr,"\n 3 : voir si la pile est vide \n");   
    fprintf(stderr,"\n 4 : detruire la pile \n"); 
   fprintf(stderr,"\n 5 : exit\n"); 
   fprintf(stderr,"\n");
 }
 
 
int main (){ 
 aide();
char n; 
ppile_t pile = creer_pile(); 
pnoeud_t noeud=0; 
int a;
      while (1){
     
     
      printf("---> ");
      fflush(stdout);
      n = getchar();
    switch(n){ 

case '1' :          
         printf("\n le sommet avant d'ampiler est: %d " , pile->sommet);
         empiler(pile,noeud); 
         printf("\n le sommet aprés avoir ampiler est:%d \n" , pile->sommet);
         break;
case '2' :  
       printf("\n le sommet avant de depiler est:%d " , pile->sommet); 
       depiler(pile); 
       printf("\n le sommet aprés avoir depiler est:%d \n" , pile->sommet);
break; 
case '3' :     if(pile_vide(pile) == 1){
        printf("La pile est vide \n"); }
        else { 
        printf("La pile n'est pas vide \n"); 
        
        }
    
break; 
case '4' : 
     a=detruire_pile(pile); 
    if ( a == 1){ 
    printf("la pile a etait detruit\n"); 
    }  
     
break; 

case '5' :  exit(0);
break;

return 0;
}}}
 
/*void afficher() { 
  ppile_t pile;
   if (pile->sommet == -1)
      printf("\n La pile est vide");
  else {
      for (int i = pile->sommet; i >= 0; i--)
         printf("\n%d", pile->Tab[i]);
   }
} 
*/

/*
int main() {
   int choice;
   int option = 1; 
   int pn; 
   
   ppile_t pile = creer_pile();
 
   printf("\n\tImplémentation d'une pile");
   while (option) {
      printf("\nMenu principal");
      printf("\n1.Empiler \n2.Dépiler \n3.Afficher \n4.exit");
      printf("\nEntrez votre choix: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1: 
         printf("\n le sommet avat d'apiler est:%d " , pile->sommet);
         empiler(pile,pn); 
         printf("\n le sommet aprés avoir ampiler est:%d " , pile->sommet);
         break;
      case 2: 
       printf("\n le sommet avant de depiler est:%d " , pile->sommet); 
       depiler(pile); 
       printf("\n le sommet aprés avoir depiler est:%d " , pile->sommet);
         break;
      case 3:
         afficher();
         break;
      case 3:
         exit(0);
      }
      printf("\nVoulez-vous continuer (Tapez 0(Non) ou 1(Oui))? : ");
      scanf("%d", &option);
   }
   return 0;
}*/
/*
int main(){ 

    ppile_t pile = creer_pile();
    if(pile_vide(pile) == 1){
        printf("La pile que nous venons de créer est bien vide \n");
    }

    pnoeud_t noeud=1;
    empiler(pile,noeud);
    if(pile_vide(pile) == 0){
        printf("La pile que nous venons de créer n'est plus vide \n ");
    } 
     
    depiler (pile); 
       if(){
        printf("La pile que nous venons de créer n'est plus vide \n ");
    } 
     
     
    int a=detruire_pile(pile); 
    if ( a == 1){ 
    printf("la pile a etait detruit\n"); 
    } 
    
    
    

    printf("###### Tout les tests sont passés ######\n");
    return 1;
}*/
/* 

int detruire_pile (ppile_t p)
{
  free(p);
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
}*/
