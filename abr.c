#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "pile.h"
#include "file.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

int EstArbreVide(Arbre_t a){
  if(a->fgauche == NULL && a->fdroite == NULL){
    return 1;
  }
  return 0;
}


int feuille(Arbre_t a)
{
  if (a == NULL)
    return 0;
  else
  {
    if ((a->fgauche == NULL) && (a->fdroite == NULL))
      return 1;
    else
      return 0;
  }
}

Arbre_t ajouter_noeud(Arbre_t a, Arbre_t n)
{
  /* ajouter le noeud n dans l'arbre a */

  if (a == NULL)
    return n;
  else if (n->cle < a->cle)
    a->fgauche = ajouter_noeud(a->fgauche, n);
  else
    a->fdroite = ajouter_noeud(a->fdroite, n);
  return a;
}

Arbre_t rechercher_cle_arbre(Arbre_t a, int valeur)
{
  if (a == NULL)
    return NULL;
  else
  {
    if (a->cle == valeur){
      printf("%d\n",a->cle);
      return a;
    }
    else
    {
      if (a->cle < valeur)
        return rechercher_cle_arbre(a->fdroite, valeur);
      else
        return rechercher_cle_arbre(a->fgauche, valeur);
    }
  }
}

Arbre_t ajouter_cle(Arbre_t a, int cle)
{
  Arbre_t n;
  Arbre_t ptrouve;

  /* 
     ajout de la clé. Creation du noeud n qu'on insere 
    dans l'arbre a
  */

  ptrouve = rechercher_cle_arbre(a, cle);

  if (ptrouve == NULL)
  {
    n = (Arbre_t)malloc(sizeof(noeud_t));
    n->cle = cle;
    n->fgauche = NULL;
    n->fdroite = NULL;

    a = ajouter_noeud(a, n);
    return a;
  }
  else
    return a;
}

Arbre_t lire_arbre(char *nom_fichier)
{
  FILE *f;
  int cle;
  Arbre_t a = NULL;

  f = fopen(nom_fichier, "r");

  while (fscanf(f, "%d", &cle) != EOF)
  {
    a = ajouter_cle(a, cle);
  }

  fclose(f);

  return a;
}

void afficher_arbre(Arbre_t a, int niveau)
{
  /*
    affichage de l'arbre a
    on l'affiche en le penchant sur sa gauche
    la partie droite (haute) se retrouve en l'air
  */

  int i;

  if (a != NULL)
  {
    afficher_arbre(a->fdroite, niveau + 1);

    for (i = 0; i < niveau; i++)
      printf("\t");
    printf(" %d (%d)\n\n", a->cle, niveau);

    afficher_arbre(a->fgauche, niveau + 1);
  }
  return;
}

int hauteur_arbre_r(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  int lh = hauteur_arbre_r(a->fgauche);
  int rh = hauteur_arbre_r(a->fdroite);
  
  if(lh>rh){
    return lh+1;
  }
  return rh+1;
}

int hauteur_arbre_nr(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  return 0;
}

void parcourir_arbre_largeur(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return;
  }

  pfile_t F = creer_file();
  enfiler(F,a);
  Arbre_t n;
  while (file_vide(F) != 1)
  {
    n = defiler(F);
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
    printf("%d\n",n->cle);
  }
}

void afficher_nombre_noeuds_par_niveau(Arbre_t a) //Parcours en largeur + print le nombre à chaque niveau
{
  if (EstArbreVide(a) == 1)
  {
    return;
  }

  return;
}

int nombre_cles_arbre_r(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  int nb_cle = 0;
  pfile_t F = creer_file();
  enfiler(F,a);
  while (file_vide(F) != 0)
  {
    Arbre_t n = defiler(F);
    if (!EstArbreVide(n))
    {
      enfiler(F, n->fgauche);
      enfiler(F, n->fdroite);
      nb_cle++;
    }
  }
  return nb_cle;
}

int nombre_cles_arbre_nr(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }
  int nb_cle = 0;
  pfile_t F = creer_file();
  enfiler(F,a);
  Arbre_t n;
  while (file_vide(F) != 1)
  {
    n = defiler(F);
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
      nb_cle++;
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
      nb_cle++;
    }
  }
  
  printf("Il y a : %d clés dans l'arbre",nb_cle);
  return nb_cle;
}



int trouver_cle_min(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

if (EstArbreVide(a->fgauche) == 1){
    return a->cle;}
  else{
    return trouver_cle_min(a->fgauche);
    }

  return -1;
}

void imprimer_liste_cle_triee_r(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return;
  }

  pfile_t F = creer_file();
  enfiler(F,a);
  Arbre_t n;
  while (file_vide(F) != 1)
  {
    n = defiler(F);
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
    printf("%d\n",n->cle);
  }
}

void imprimer_liste_cle_triee_nr(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return;
  }

  pfile_t F = creer_file();
  enfiler(F,a);
  Arbre_t n;
  while (file_vide(F) != 1)
  {
    n = defiler(F);
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
    printf("%d\n",n->cle);
  }
}

int arbre_plein(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return 1;
  }
  else{
    arbre_plein(a->fgauche);
    arbre_plein(a->fdroite);

    if(a->fgauche == NULL || a->fdroite == NULL){
      return 0;
    }
  }
  return 1;
}

int arbre_parfait(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  return 0;
}

Arbre_t rechercher_cle_sup_arbre(Arbre_t a, int valeur)
{
  if (EstArbreVide(a) == 1)
  {
    return NULL;
  }
   Arbre_t max = NULL;//stocker le max
   max->cle = -1;

  pfile_t F = creer_file();
  enfiler(F,a);
  Arbre_t n;
  while (file_vide(F) != 0)
  {
    n = defiler(F);
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
      
    if(n->cle > valeur && n->cle < max->cle){
      max = n;
    }
  }

  printf("%d\n",max->cle);
  return max;
  
  //A chaque nouvelle clé on vérifie si elle est supérieure a valeur et inférieure a max (on cherche celle directement supérieure)
}


Arbre_t rechercher_cle_inf_arbre(Arbre_t a, int valeur)
{
 if (EstArbreVide(a) == 1)
  {
    return NULL;
  }
   Arbre_t min = NULL;//stocker le max
   min->cle = -1;

  pfile_t F = creer_file();
  enfiler(F,a);
  Arbre_t n;
  while (file_vide(F) != 0)
  {
    n = defiler(F);
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
      
    if(n->cle < valeur && n->cle > min->cle){
      min = n;
    }
  }

  printf("%d\n",min->cle);
  return min;
}

Arbre_t detruire_cle_arbre(Arbre_t a, int cle)
{
  return NULL;
}

Arbre_t intersection_deux_arbres(Arbre_t a1, Arbre_t a2)
{

  if (EstArbreVide(a1) == 1 || EstArbreVide(a2) == 1)
  {
    return NULL;
  }
  

  int *inter = malloc(nombre_cles_arbre_nr(a1)); //Le tableau qui va contenir les clés communes
  int i = 0;

  pfile_t F = creer_file();
  enfiler(F, a1);
  Arbre_t n;
  
  while(file_vide(F) != 0 )
  {
    n = defiler(F);
    
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
  
    if (rechercher_cle_arbre(a2,n->cle) != NULL)
    { //Rajoute la clé de l'intersection au tableau
      inter[i] = n->cle;
      i++;
    }
  }

  Arbre_t abr = NULL;
  for(int j = 0; j< i; j++){
    ajouter_cle(abr,inter[j]);
  }
  return abr;
}

Arbre_t union_deux_arbres(Arbre_t a1, Arbre_t a2) //Pa compri
{
  if (EstArbreVide(a1) == 1)
  {
    return NULL;
  }

  return NULL;
}

Arbre_t Rechercher(int cle, Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return NULL;
  }
  else if (cle == a->cle)
  {
    return a;
  }
  else if (cle < a->cle)
  {
    return Rechercher(cle, a->fgauche);
  }
  else if (cle > a->cle)
  {
    return Rechercher(cle, a->fdroite);
  }

  return NULL;
}