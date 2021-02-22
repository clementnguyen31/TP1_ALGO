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
 
  afficher_arbre(a,0);
}
