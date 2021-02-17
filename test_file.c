#include <stdlib.h>
#include <stdio.h>
#include "abr.h"
#include "file.h"



int main(){

pfile_t f = creer_file();
printf("%d",file_vide(f));
pnoeud_t p = malloc(sizeof(noeud_t));
p->cle = 4;
enfiler(f,p);
printf("%d",defiler(f)->cle);
return 1;
}