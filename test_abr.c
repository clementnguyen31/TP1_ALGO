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
  afficher_arbre (a,0) ;
  printf("%d\n",nombre_cles_arbre_nr(a));
  printf("%d\n",nombre_cles_arbre_r(a));
  
  afficher_arbre (intersection_deux_arbres(a,b),0);
}
