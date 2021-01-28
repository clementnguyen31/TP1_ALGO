#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "pile.h"
#include "file.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

bool EstArbreVide(Arbre_t a){
  if(a->fgauche == NULL && a->fdroite == NULL){
    return true;
  }
  return false;
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
    if (a->cle == valeur)
      return a;
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

  return 0;
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
    return -1;
  }

  F = creer_file();
  enfiler(a, F);
  while (file_vide(F) != 0)
  {
    n = F->tete;
    F = defiler(F);
    if (!EstArbreVide(n))
    {
      F = enfiler(FilsGauche(n), F);
      F = Enfiler(FilsDroit(n), F);
      printf("%n",n->cle);
    }
  }
}

void afficher_nombre_noeuds_par_niveau(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
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
  F = creer_file();
  enfiler(a, F);
  while (file_vide(F) != 0)
  {
    n = F->tete;
    F = defiler(F);
    if (!EstArbreVide(n))
    {
      F = enfiler(FilsGauche(n), F);
      F = Enfiler(FilsDroit(n), F);
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
  F = creer_file();
  enfiler(a, F);
  while (file_vide(F) != 0)
  {
    n = F->tete;
    F = defiler(F);
    if (!EstArbreVide(n))
    {
      F = enfiler(FilsGauche(n), F);
      F = Enfiler(FilsDroit(n), F);
      nb_cle++;
    }
  }
  return nb_cle;
}

int trouver_cle_min(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

if (EstVide(FilsGauche(a)){
    return a;}
  else{
    return trouver_cle_min(FilsGauche(a))
    }
}

void imprimer_liste_cle_triee_r(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  printf("Voici la liste des clés triée : ");

  F = creer_file();
  enfiler(a, F);
  while (file_vide(F) != 0)
  {
    n = F->tete;
    F = defiler(F);
    if (!EstArbreVide(n))
    {
      F = enfiler(FilsGauche(n), F);
      F = Enfiler(FilsDroit(n), F);
      printf("%n",n->cle);          //Affiche les clés a chaque exécution dans le bon ordre car c'est un ABR
    }
  }
  return;
}

void imprimer_liste_cle_triee_nr(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  printf("Voici la liste des clés triée : ");

  F = creer_file();
  enfiler(a, F);
  while (file_vide(F) != 0)
  {
    n = tete(F);
    F = defiler(F);
    if (!EstArbreVide(n))
    {
      F = enfiler(FilsGauche(n), F);
      F = Enfiler(FilsDroit(n), F);
      printf("%n",n->cle);          //Affiche les clés a chaque exécution dans le bon ordre car c'est un ABR
    }
  }
  return;
}

int arbre_plein(Arbre_t a)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }
  /*
    a completer
  */

  return 0;
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
    return -1;
  }
  //stocker le max
  //A chaque nouvelle clé on vérifie si elle est supérieure a valeur et inférieure a max (on cherche celle directement supérieure)
}

Arbre_t rechercher_cle_inf_arbre(Arbre_t a, int valeur)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  return NULL;
}

Arbre_t detruire_cle_arbre(Arbre_t a, int cle)
{
  if (EstVide(a))
  {
    return ArbreVide();
  }
  else if (e = Racine(a))
  {
    SUPPRIMMER_RACINE(a); //Seule différence avec la fonction rechercher
  }
  else if (e < Racine(a))
  {
    return RECHERCHER(e, FilsGauche(a));
  }
  else if (e > Racine(a))
  {
    return RECHERCHER(e, FilsDroit(a));
  }
}

Arbre_t intersection_deux_arbres(Arbre_t a1, Arbre_t a2)
{

  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  int *inter = malloc(Nombre_cles(a1)); //Le tableau qui va contenir les clés communes
  int i = 0;

  F = creer_file();
  F2 = creer_file();
  enfiler(a1, F);
  enfiler(a2, F2) while (file_vide(F) != 0 && file_vide(F2) != 0)
  {
    Arbre_t n = tete(F);
    Arbre_t n2 = tete(F2);
    F = defiler(F);
    F2 = defiler(F2);
    if (!EstArbreVide(n) && !EstArbreVide(n2))
    {
      F = enfiler(FilsGauche(n), F);
      F = enfiler(FilsDroit(n), F);
      F2 = enfiler(FilsGauche(n2), F2);
      F2 = enfiler(FilsDroit(n2), F2);

      if (n->cle == n2->cle)
      { //Rajoute la clé de l'intersection au tableau
        inter[i] = n->cle;
        i++;
      }
    }
  }
}

Arbre_t union_deux_arbres(Arbre_t a1, Arbre_t a2)
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  return NULL;
}

Rechercher(int cle, Arbre_t a)
{

  if (EstVide(a))
  {
    return ArbreVide();
  }
  else if (e = Racine(a))
  {
    return a;
  }
  else if (e < Racine(a))
  {
    return RECHERCHER(e, FilsGauche(a));
  }
  else if (e > Racine(a))
  {
    return RECHERCHER(e, FilsDroit(a));
  }
}