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
  if (file_pleine(f) == 1){
    return NULL;
  }
    int i = 0;
    pnoeud_t temp = f->Tab[0]; //Pointeur sur l'élément à défiler

    while (f->Tab[i+1] != NULL)
    {
      f->Tab[i] = f->Tab[i+1];
      i++;
    }
    i++;

    f->Tab[i] = NULL; //Le dernier est a enlever
    
    if(i > 0){
      f->queue = f->Tab[i-1]->cle;
    }
    else{
      f->queue = f->Tab[0]->cle;
    }
    f->tete = f->Tab[0]->cle;
    return temp;
  
}

int enfiler(pfile_t f, pnoeud_t p)
{

  int i = 0 ; //indice de la premiere case libre

  if(file_pleine(f) == 1){
    return 0;
  }

  while (f->Tab[i] != NULL)
  {
    i++;
  }

  f->Tab[i] = p;
  if(i==0){
    f->tete = p->cle;
    f->queue = p->cle;
  }
  else{
    f->queue = p->cle;
  }
  return 1;
}
