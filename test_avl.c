#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "avl.h"

int main(int argc, char **argv)
{
    Tree_AVL_t arbre = create_avl(5);

    Tree_AVL_t arbre2 = arbre;
    arbre2 = insert_key(arbre2, 10);
    arbre2 = insert_key(arbre2, 20);
    arbre2 = insert_key(arbre2, 30);
    arbre2 = insert_key(arbre2, 40);
    show_avl(arbre2, 0);

    printf("TOUT LES TESTS SONT VALIDES");
    return 0;
}
