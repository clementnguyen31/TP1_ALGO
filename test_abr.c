#include <stdio.h>
#include <stdlib.h>

#include "abr.h"

int main (int argc, char**argv)
{
  Arbre_t a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  
  afficher_arbre (a,0) ;
  printf("%d\n",nombre_cles_arbre_nr(a));
  printf("%d\n",nombre_cles_arbre_r(a));
  printf("%d\n",hauteur_arbre_r(a));

  printf("%d\n",rechercher_cle_sup_arbre(a,6)->cle);
  printf("%d\n",rechercher_cle_inf_arbre(a,6)->cle);
  
}
