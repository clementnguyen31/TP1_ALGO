#include <stdio.h>
#include <stdlib.h>

#include "abr.h"

int main (int argc, char**argv)
{
  Arbre_t a ;
  Arbre_t b ;

  if (argc != 3)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  b = lire_arbre (argv[2]) ;
 

  printf(" \n Nous allons afficher les deux arbres passés en parametre \n");

  afficher_arbre(a,0);
  afficher_arbre(b,0);

  printf("La hauter du premier arbre est : %d\n",hauteur_arbre_r(a));
  printf("La hauter du deuxieme arbre est : %d\n",hauteur_arbre_r(b));

  printf("\n");

  printf("Nombre de noeuds par niveaux du second arbre : ");
  printf("\n");

  afficher_nombre_noeuds_par_niveau(a);

  printf("\n");

  printf("Intersection des deux arbres passés en parametre :");
  printf("\n");
  afficher_arbre(intersection_deux_arbres(a,b),0);

  printf("\n");

  printf("Union des deux arbres passés en parametre :");
  printf("\n");
  afficher_arbre(union_deux_arbres(a,b),0);

  printf("\n");
  printf("Nous allons supprimer la clé 4 du premier arbre et l'afficher mis a jour \n");
  afficher_arbre(detruire_cle_arbre(a,2),0);


  printf("\n");
  printf("TOUT LES TESTS ONT ETE VALIDES");
}
