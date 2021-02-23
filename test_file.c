#include <stdlib.h>
#include <stdio.h>
#include "abr.h"
#include "file.h"



int main(){
int a =0;
pfile_t f = creer_file();  

if(file_vide(f) == 1 ){
printf("La file a bien etait crée et est vide ");  
 a=a+1
 }

pnoeud_t nd = malloc(sizeof(noeud_t));
p->cle = 4; 

if (enfiler(f,p)== 1){ 
printf("L'enfilement a bien etait fait ");
a=a+1; 

}

if (defiler(f) == 1) { 
printf("Le defilement a bien etait fait");
a=a+1;
}
 
if  (a==3) { 

printf("###### Tout les tests sont passés ######");
}
 
return 1;
} 

