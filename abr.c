#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "pile.h"
#include "file.h"

#define max(a, b) ((a) > (b) ? (a) : (b))


int EstArbreVide(Arbre_t a) //DONE
{
  if(a->fgauche == NULL && a->fdroite == NULL){
    return 1;
  }
  return 0;
}


int feuille(Arbre_t a) //DONE
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

Arbre_t ajouter_noeud(Arbre_t a, Arbre_t n) //DONE
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

Arbre_t rechercher_cle_arbre(Arbre_t a, int valeur) //DONE
{
  if (a == NULL)
    return NULL;
  else
  {
    if (a->cle == valeur){
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

Arbre_t ajouter_cle(Arbre_t a, int cle) //DONE
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

Arbre_t lire_arbre(char *nom_fichier) //DONE
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

void afficher_arbre(Arbre_t a, int niveau) //DONE
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

int hauteur_arbre_r(Arbre_t a) //DONE
{
 
  if (a == NULL)
  {
    return 0;
  }

  int left_height = hauteur_arbre_r(a->fgauche);
  int right_height = hauteur_arbre_r(a->fdroite);
  
  if(left_height >= right_height){
    return left_height+1;
  }
  else{
    return right_height+1;
  }
}

int hauteur_arbre_nr(Arbre_t a) //DONE
{
  if (a == NULL) 
      return 0; 
  
    // Create an empty queue for level order tarversal 
  pfile_t F = creer_file(); 
  
    // Enqueue Root and initialize height 
  enfiler(F,a); 
  int hauteur = 0; 
  
  while (1) 
  { 
        // nodeCount (queue size) indicates number of nodes 
        // at current lelvel. 
    int nombre_noeud = taille(F); 
    if (nombre_noeud == 0) 
        return hauteur; 
    
    hauteur++; 
  
        // Dequeue all nodes of current level and Enqueue all 
        // nodes of next level 
    while (nombre_noeud > 0) 
    { 
      Arbre_t noeud = defiler(F);  
      if (noeud->fgauche != NULL) 
        enfiler(F,noeud->fgauche); 
      if (noeud->fdroite!= NULL) 
        enfiler(F,noeud->fdroite); 
      nombre_noeud--; 
    } 
  }
} 

void parcourir_arbre_largeur(Arbre_t a) //DONE
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

void afficher_nombre_noeuds_par_niveau(Arbre_t a) //DONE
{
  if (a == NULL) 
      return ; 
  
  pfile_t F = creer_file(); 
  
  enfiler(F,a); 
  int i = 0;
  
  while (1) 
  {
    int nombre_noeud = taille(F); 
    if (nombre_noeud == 0) 
        return; 

    printf("Au niveau %d il y a %d noeuds \n",i,nombre_noeud);
    i++;

    while (nombre_noeud > 0) 
    { 
      Arbre_t noeud = defiler(F);  
      if (noeud->fgauche != NULL) 
        enfiler(F,noeud->fgauche); 
      if (noeud->fdroite!= NULL) 
        enfiler(F,noeud->fdroite); 
      nombre_noeud--; 
    } 
  }
}


int nombre_cles_arbre_r(Arbre_t a) //DONE
{
  int nb_cle = 1;


  if(EstArbreVide(a))
  {
    return 1;
  }

  
  if(a->fgauche != NULL ){
    nb_cle = nb_cle + nombre_cles_arbre_r(a->fgauche);
  }
  if(a->fdroite != NULL){
    nb_cle = nb_cle + nombre_cles_arbre_r(a->fdroite);
  }
  
  return nb_cle;
}

int nombre_cles_arbre_nr(Arbre_t a) //DONE
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }
  int nb_cle = 1;
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
  
  return nb_cle;
}


int trouver_cle_min(Arbre_t a) //DONE
{
  if (EstArbreVide(a) == 1)
  {
    return -1;
  }

  if (EstArbreVide(a->fgauche) == 1){
    printf("%d\n",a->fgauche->cle);
    return a->fgauche->cle;
    }

  else{
    return trouver_cle_min(a->fgauche);
    }

}

void imprimer_liste_cle_triee_r(Arbre_t a) //DONE
{
  if (a == NULL)
  {
    return;
  }
  imprimer_liste_cle_triee_r(a->fgauche);

  if(a->fgauche == NULL){
    printf("%d\n",a->cle);
  }

  imprimer_liste_cle_triee_r(a->fdroite);

}

void imprimer_liste_cle_triee_nr(Arbre_t a) //PAS DONE MAIS EASY
{
  ppile_t P = creer_pile();
  while (a!=NULL) {
    empiler(P,a);
    a=a->fgauche;
  }
  while (pile_vide(P) != 1) {
    a = depiler(P); 
    printf ("%d ", a->cle);
    a = a->fdroite; 
    while(a != NULL) { 
      empiler(P,a); 
      a = a->fgauche; 
    }
  }
}

int arbre_parfait(Arbre_t a) //DONE
{
  if (EstArbreVide(a) == 1)
  {
    return 1;
  }

  if(hauteur_arbre_r(a->fdroite) != hauteur_arbre_r(a->fgauche)){
    return 0;
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
    if(n->fgauche==NULL && n->fdroite != NULL){
      return 0;
    }
    if(n->fgauche!=NULL && n->fdroite == NULL){
      return 0;
    }
  }

  return 1;
}

Arbre_t rechercher_cle_sup_arbre(Arbre_t a, int valeur) //DONE
{
  if (EstArbreVide(a) == 1)
  {
    return NULL;
  }
   Arbre_t max;//stocker le max
   max->cle = -1;

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

    if(max->cle == -1){
      if(n->cle > valeur){
        max = n;
        max->cle = n->cle;
      }
    }
    
    if(n->cle > valeur && n->cle < max->cle){
      printf("%d\n",995);
      max = n;
    }
  }

  return max;
  
  //A chaque nouvelle clé on vérifie si elle est supérieure a valeur et inférieure a max (on cherche celle directement supérieure)
}


Arbre_t rechercher_cle_inf_arbre(Arbre_t a, int valeur) //DONE
{
 if (EstArbreVide(a) == 1)
  {
    return NULL;
  }
   Arbre_t min;//stocker le max
   min->cle = -1;

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

    if(min->cle == -1){
      if(n->cle > valeur){
        min = n;
        min->cle = n->cle;
      }
    }
    
    if(n->cle < valeur && n->cle > min->cle){
      min = n;
    }
  }

  return min;
  
}

Arbre_t detruire_cle_arbre(Arbre_t a, int cle) //PAS DONE
{
  if (rechercher_cle_arbre(a, cle) == NULL) {
    return a;
  }
  else if (rechercher_cle_arbre(a, cle)==a) {

    Arbre_t sol = rechercher_cle_inf_arbre(a, a->cle);
    Arbre_t save = a->fdroite;
    Arbre_t save2 = a->fgauche;

    a = sol;
   
    if (save2 != sol) {
      Arbre_t current = save2;

      while (current->fdroite->fdroite != NULL) {
        current = current->fdroite;
      }
      current->fdroite = NULL;
      a->fdroite = save;
      a->fgauche = save2;
    }
    return a;
  }
  else {
    Arbre_t arbrecle = rechercher_cle_arbre(a, cle);

    if (feuille(arbrecle) == 1) {

      pfile_t file = creer_file();
      enfiler(file, a);
      int trouve = 0;

      while (file_vide(file) != 1 && trouve == 0) 
      {
        Arbre_t current = defiler(file);
        if (current->fgauche == arbrecle) {
          trouve = 1;
          current->fgauche = NULL;
        }

        else if (current->fdroite == arbrecle) {
          trouve = 1;
          current->fdroite = NULL;
        }
        enfiler(file, current->fgauche);
        enfiler(file, current->fdroite);
      }

      return a;
    }

    else {

      pfile_t file = creer_file();
      enfiler(file, a);
      int trouve = 0;

      while (file_vide(file) != 1 && trouve == 0) 
      {
        Arbre_t current = defiler(file);

        if (current->fgauche == arbrecle) {
          trouve = 1;
          if (current->fgauche->fgauche != NULL) {
            Arbre_t sol = rechercher_cle_inf_arbre(current->fgauche, current->fgauche->cle);
            if (sol == current->fgauche->fgauche) {
              Arbre_t save = current->fgauche->fdroite;
              current->fgauche = current->fgauche->fgauche;
              current->fgauche->fdroite = save;
            }
            else {
              Arbre_t save = current->fgauche->fgauche;
              Arbre_t save2 = current->fgauche->fdroite;
              current->fgauche = sol;
              current->fgauche->fgauche = save;
              Arbre_t fg = current->fgauche;
              Arbre_t fgfg = current->fgauche->fgauche;
              while (fgfg->fdroite->fdroite != NULL) {
                fgfg = fgfg->fdroite;
              }
              fgfg->fdroite = NULL;
              fg->fdroite = save2;
            }
          }
          else {
            current->fdroite = current->fdroite->fdroite;
          }
        }

        else if (current->fdroite == arbrecle) {
          trouve = 1;
          if (current->fdroite->fgauche != NULL) {
            Arbre_t sol = rechercher_cle_inf_arbre(current->fdroite, current->fdroite->cle);
            if (sol == current->fdroite->fgauche) {
              Arbre_t save = current->fdroite->fdroite;
              current->fdroite = current->fdroite->fgauche;
              current->fdroite->fdroite = save;
            }
            else {
              Arbre_t save = current->fdroite->fgauche;
              Arbre_t save2 = current->fdroite->fdroite;
              current->fdroite = sol;
              current->fdroite->fgauche = save;
              Arbre_t fd = current->fdroite;
              Arbre_t fdfg = current->fdroite->fgauche;
              while (fdfg->fdroite->fdroite != NULL) {
                fdfg = fdfg->fdroite;
              }
              fdfg->fdroite = NULL;
              fd->fdroite = save2;
            }
          }
          else {
            current->fdroite = current->fdroite->fdroite;
          }
        }

        enfiler(file, current->fgauche);
        enfiler(file, current->fdroite);

      }

      return a;
    }
  }
}

Arbre_t intersection_deux_arbres(Arbre_t a1, Arbre_t a2) //QUASI DONE
{
  if (a1 == NULL || a2 == NULL)
  {
    return NULL;
  }
  Arbre_t n = NULL;
  Arbre_t abr = NULL;

  pfile_t F = creer_file();

  enfiler(F, a1);
  
  
  while(file_vide(F) != 1 )
  {
    n = defiler(F);
    
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
    
    if (rechercher_cle_arbre(a2,n->cle))
    { //Rajoute la clé de l'intersection au tableau
      abr = ajouter_cle(abr,n->cle);
    }
  }
  return abr;
}

Arbre_t union_deux_arbres(Arbre_t a1, Arbre_t a2) //QUASI DONE
{
  if (EstArbreVide(a1) == 1 || EstArbreVide(a2) == 1)
  {
    return NULL;
  }

  Arbre_t n = NULL;
  Arbre_t abr = NULL;

  pfile_t F = creer_file();
  pfile_t F2 = creer_file();

  enfiler(F, a1);
  enfiler(F2, a2);
  
  
  while(file_vide(F) != 1 )
  {
    n = defiler(F);
    
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
    abr = ajouter_cle(abr,n->cle);
  }
  
  while(file_vide(F2) != 1 )
  {
    n = defiler(F2);
    
    if (n->fgauche != NULL) {
      enfiler(F2, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F2, n->fdroite);
    }
    abr = ajouter_cle(abr,n->cle);
  }

  return abr;
}

int inclusion_arbre(Arbre_t a1, Arbre_t a2){

  if (a1 == NULL || a2 == NULL)
  {
    return NULL;
  }
  Arbre_t n = NULL;

  pfile_t F = creer_file();

  enfiler(F, a1);
  
  
  while(file_vide(F) != 1 )
  {
    n = defiler(F);
    
    if (n->fgauche != NULL) {
      enfiler(F, n->fgauche);
    }
    if (n->fdroite != NULL) {
      enfiler(F, n->fdroite);
    }
    
    if (rechercher_cle_arbre(a2,n->cle) == NULL)
    { 
      return 0;
    }
  }
  return 1;
}










