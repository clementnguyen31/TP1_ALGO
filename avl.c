#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "avl.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

Tree_AVL_t create_avl(int key)
{
  Tree_AVL_t new_arbre = malloc(sizeof(node_avl));
  new_arbre->key = key;
  new_arbre->bal = 0;
  new_arbre->c_left = NULL;
  new_arbre->c_right = NULL;
  return new_arbre;
}

Tree_AVL_t rotation_left(Tree_AVL_t a)
{
  if (a->c_right == NULL)
  {
    return a;
  }
  else
  {
    Tree_AVL_t parent = a->c_right;
    if (parent->c_left != NULL)
    {
      Tree_AVL_t child = parent->c_left;
      a->c_right = child;
    }
    else
    {
      a->c_right = NULL;
    }
    parent->c_left = a;
    a->bal = 0;
    parent->bal = 0;
    return parent;
  }
}

Tree_AVL_t rotation_right(Tree_AVL_t a)
{
  if (a->c_left == NULL)
  {
    return a;
  }
  else
  {
    Tree_AVL_t parent = a->c_left;
    if (parent->c_right != NULL)
    {
      Tree_AVL_t child = parent->c_right;
      a->c_left = child;
    }
    else
    {
      a->c_left = NULL;
    }
    parent->c_right = a;
    a->bal = 0;
    parent->bal = 0;
    return parent;
  }
}

Tree_AVL_t double_rotation_left(Tree_AVL_t a)
{
  a->c_right = rotation_right(a->c_right);
  return rotation_left(a);
}

Tree_AVL_t double_rotation_right(Tree_AVL_t a)
{
  a->c_left = rotation_left(a->c_left);
  return rotation_right(a);
}

Tree_AVL_t balancing(Tree_AVL_t A)
{
  if (A->bal == 2) // first case
    if (A->c_right != NULL && A->c_right->bal >= 0)
      return rotation_right(A);
    else
    {
      return double_rotation_right(A);
    }
  else if (A->bal == -2) // second case
    if (A->c_left != NULL && A->c_left->bal <= 0)
      return rotation_left(A);
    else
    {
      return double_rotation_left(A);
    }
  else
    return A;
}

Tree_AVL_t insert_key(Tree_AVL_t a, int key)
{
  if (a->key == key)
  {
    return a;
  }
  else if (key > a->key) // we want to insert the key on the right
  {
    if (a->c_right == NULL)
    {
      Tree_AVL_t new_arbre = create_avl(key);
      a->c_right = new_arbre;
    }
    else
    {
      a->c_right = insert_key(a->c_right, key);
    }
    a->bal = height_avl(a->c_left) - height_avl(a->c_right);
  }
  else if (key < a->key) // we want to insert the key on the left
  {
    if (a->c_left == NULL)
    {
      Tree_AVL_t new_arbre = create_avl(key);
      a->c_left = new_arbre;
    }
    else
    {
      a->c_left = insert_key(a->c_left, key);
    }
    a->bal = height_avl(a->c_left) + 1 - height_avl(a->c_right);
  }
  return balancing(a); // keep balanced
}

void show_avl(Tree_AVL_t a, int level)
{
  int i;

  if (a != NULL)
  {
    show_avl(a->c_right, level + 1);

    for (i = 0; i < level; i++)
    {
      printf("\t");
    }
    printf(" %d (%d)\n\n", a->key, level);

    show_avl(a->c_left, level + 1);
  }
  return;
}

int height_avl(Tree_AVL_t a)
{
  if (a == NULL)
  {
    return 0;
  }
  else
  {
    return max(1 + height_avl(a->c_left), 1 + height_avl(a->c_right));
  }
}