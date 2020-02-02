/*!
\file main.c
\author CHOMEL Louis
\date Mercredi 6 Novembre 2019
\version 1.0
\brief Menu pour le puissance 4
*/


/*Fonctions de traitement et d'affichage du puissance 4*/
#include "puissance4.h"

/*Fonction de saisie d'entier Naturel*/
#include "saisieEntierNaturel.h"





/*!
\fn int main (int argc , char** argv )
\author CHOMEL Louis
\version 1.0
\brief Menu pour le jeu puissance4
\date Mercredi 6 Novembre 2019
\param argc nombre d'arguments en entrée
\param argv valeur des arguments
\return 0 si tout s'est bien passé
*/
int main( int argc,char** argv) {
    int int_choixutilisateur; // entier stockant le choix de l'utilisateur
    int ttint_grille[N][N]; // tableau 2D qui stocke les différents coups des joueurs

    /*Demande à l'utilisateur*/
    printf("##Puissance4##\n");
    printf("Joueur 1 : X \n");
    printf("Joueur 2 : O \n");
    printf("1 - Jouer\n");
    printf("2 - Quitter\n");
    printf("Votre choix : ");
    int_choixutilisateur = saisieEntierNaturel();

    /*Tant que l'utilisateur ne choisit pas une option correcte*/
    while (int_choixutilisateur != 1 && int_choixutilisateur != 2 ){
      printf("Veuillez choisir une option entre 1 et 2\n");
      int_choixutilisateur = saisieEntierNaturel();
    }
    /*L'utilisateur décide de jouer*/
    if (int_choixutilisateur==1){
      /*Initialisation du tableau 2D*/
      init(ttint_grille);

      /*les deux joueurs jouent chacun leur tour*/
      tourDeJeu(ttint_grille);
    }


    /*On renvoie 0 car tout s'est bien passé (aucune erreur particulière)*/
    return(0);

    }
