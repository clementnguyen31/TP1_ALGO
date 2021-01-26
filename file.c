#include <stdlib.h>

#include "abr.h"
#include "file.h"

//La tete sera à la position 0

pfile_t creer_file()
{
  file_t *f = malloc(sizeof(file_t));
  f->tete = -1;
  f->queue = -1;
  return f;
}

int detruire_file(pfile_t f)
{
  free(f);
}

int file_vide(pfile_t f)
{
  if (f->tete == -1)
  {
    return 1;
  }
  return 0;
}

int file_pleine(pfile_t f)
{
  if (f->Tab[31] != NULL)
  {
    return 1;
  }
  return 0;
}

pnoeud_t defiler(pfile_t f)
{
  if (file_pleine(f) == 0)
  {
    int i = 0;
    pnoeud_t temp = &f->Tab[0]; //Pointeur sur l'élément à défiler
    while (f->Tab[i + 1] != NULL)
    {
      f->Tab[i] = f->Tab[i + 1];
    }
    f->queue = f->Tab[i - 1];
    f->Tab[i] = NULL; //Le dernier est a enlever

    f->tete = f->Tab[0];
    return temp;
  }
}

int enfiler(pfile_t f, pnoeud_t p)
{

  int first_free; //indice de la premiere case libre
  int temp;

  while (first_free != 0)
  {
    f->Tab[first_free] = f->Tab[first_free - 1];
    first_free = first_free - 1;
  }
  f->Tab[first_free] = p;

  f->tete = f->Tab[0];
  f->queue = f->Tab[temp];
  return 1;
}
