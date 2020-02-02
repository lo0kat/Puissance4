/*!
\file saisieEntierNaturel.c
\author CHOMEL Louis
\date Dimanche 27 Octobre 2019
\version 1.0
\brief Permet de récupérer un entier naturel saisi par l'utilisateur
*/

/*on importe le prototype*/
#include "saisieEntierNaturel.h"

int saisieEntierNaturel(void){
    int int_entierSaisi;
    char char_buffer;
    int int_bufferEstVide;
    int_bufferEstVide = 1;


    while (int_bufferEstVide ==1)  {
      printf("Entrez un entier naturel : ");
      scanf ("%d",&int_entierSaisi);
      scanf("%c",&char_buffer);
      /*L'utilisateur n'a pas saisi un entier naturel*/
      if (char_buffer != '\n' || int_entierSaisi < 0) {
        printf("Erreur ce n'est pas un entier naturel\n");
        while (char_buffer != '\n'){
        scanf("%c",&char_buffer);
        }
      }
      else {
        int_bufferEstVide = 0;
      }
    }

    return(int_entierSaisi);
}
