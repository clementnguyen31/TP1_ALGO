#include <stdlib.h>
#include <stdio.h>
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
  if(f == NULL){
    return 0;
  }
  free(f);
  return 1;
}

int taille(pfile_t f){
  return f->queue - f->tete;
}

int file_vide(pfile_t f)
{
  if (f->queue == (f->tete)%(MAX_FILE_SIZE))
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



pnoeud_t defiler (pfile_t f)
  {
  if (file_vide(f) == 1) {
    return NULL;
  }
  f->tete = f->tete+1; 
  pnoeud_t retour = f->Tab[(f->tete)%(MAX_FILE_SIZE)];
  return retour;
}

int enfiler (pfile_t f, pnoeud_t p)
{
  if (file_pleine(f) != 1) {
    f->queue += 1; 
    f->Tab[(f->queue)%(MAX_FILE_SIZE)] = p; 
    return f->queue;
  }
  return 0;
}
