#include <stdlib.h>
#include <stdio.h>
#include "abr.h"
#include "file.h"



   void aide() {  
   fprintf(stderr,"\n\nMenu principal :\n"); 
   fprintf(stderr,"\n 1 : Enfiler \n");  
   fprintf(stderr,"\n 2 : Défiler \n"); 
   fprintf(stderr,"\n 3 : vérifier si la file est vide \n");    
   fprintf(stderr,"\n 4 : detruire la file \n");  
   fprintf(stderr,"\n 5 : afficher la tete et la queue \n"); 
   fprintf(stderr,"\n q : exit\n");  
   fprintf(stderr,"\n h : aide \n"); 
   fprintf(stderr,"\n");
 }
 
 
int main (){ 
 aide();
char n; 
pfile_t file = creer_file(); 
int a; 
pnoeud_t nd = malloc(sizeof(noeud_t));
//file->cle = 0; 
      while (1){
     
     
      printf("---> ");
      fflush(stdout);
      n = getchar();
    switch(n){ 

case '1' :

if (enfiler(file,nd)== 1){ 
printf("L'enfilement a bien etait fait ");
}     
         printf("\n avant d'anfiler: \n  la tete=%d \n  la queue= %d\n" ,file->tete,file->queue);   
         enfiler(file,nd);
         printf("\n aprés avoir anfiler: \n  la tete=%d \n  la queue=%d \n" ,file->tete,file->queue); 
         break;
case '2' : 
       printf(" avant de defiler\n  tete=%d \n  queue=%d \n" , file->tete,file->queue );   
       defiler(file); 
       printf("aprés avoir defiler:\n  la tete=%d \n  la queue=%d\n" ,file->tete,file->queue );
break; 
case '3' :
        if(file_vide(file) == 1 ){
        printf("La file est vide \n"); }
        else { 
        printf("La file n'est pas vide \n"); 
        
 }
    
break; 
case '4' : 
     a=detruire_file(file); 
    if ( a == 1){ 
    printf("la file a etait detruit\n"); 
    }
break; 
 case '5' :  printf("\n la tete: %d \n la queue: %d`\n" , file->tete ,file->queue); 
 break; 
 case 'h' :  aide();
break;
case 'q' :  exit(0);
break;
 default:
          fprintf(stderr,"\n\n (vous pouvez taper h pour afficher le paneau d'aide ou q pour quitter)\n\n");  
          break;
return 1;
}}}
/*
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
*/
