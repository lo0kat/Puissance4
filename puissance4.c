/*!
\file puissance4.c
\author CHOMEL Louis
\date Mercredi 6 Novembre 2019
\version 1.0
\brief Ensemble de fonctions pour le jeu puissance4
*/

/*On importe les prototypes*/
#include "puissance4.h"

/*On importe le prototype pour saisir un entier*/
#include "saisieEntierNaturel.h"


void init (int ttint_plateau[N][N]){
  int int_i; // lignes de la grille
  int int_j; // colonnes de la grille

  /*Pour toutes les cases du tableau 2d*/
  for (int_i=0;int_i<N;int_i++){
    for (int_j=0;int_j<N;int_j++){
      /*On remplit le tableau avec une valeur par défaut*/
      ttint_plateau[int_i][int_j] = -1;
    }
  }
}


void affGrille(int ttint_plateau[N][N]){
  int int_i; // lignes de la grille
  int int_j; // colonnes de la grille

  /*Pour toutes les cases du tableau 2d*/
  for (int_i=0;int_i<N;int_i++){
    for (int_j=0;int_j<N;int_j++){
      printf(" %d ",ttint_plateau[int_i][int_j]);
    }
    /*passage à la ligne*/
    printf("\n");
  }
}




void affichage(int ttint_plateau[N][N]){
  int int_i; // lignes de la grille
  int int_j; // colonnes de la grille
  int int_k; // compteur permettant de diviser chaque ligne du tableau en 3 lignes de dessin

  /*On affiche le numéro des colonnes*/
  for (int_j=0;int_j<N;int_j++){
    printf("    %d",int_j);
  }

  /*A la ligne*/
  printf("\n");
  /*Pour chaque ligne du tableau ttin_plateau*/
  for (int_i=0;int_i<N;int_i++){
    /*Chaque ligne de la grille est composée de 3 lignes (2 bords et une ligne de contenu)*/
    for (int_k=0;int_k<3;int_k++){

    /*On translate le tableau de 2 espaces*/
    printf("  ");

      for (int_j=0;int_j<N;int_j++){

      /*Ligne qui traite du contenu des cases*/
      if (int_k ==1){
        /*Bord latéral gauche de la case*/
        printf("| ");
          switch (ttint_plateau[int_i][int_j]) {
            /*Le joueur 1 a joué à cet endroit*/
            case 1:
            printf("X");
            break;

            /*Le joueur deux a joué a cet endroit*/
            case 2:
            printf("O");
            break;

            /*La case est libre*/
            case -1:
            printf(" ");
            break;

            default:
            break;
          }
          /*Bord latéral droit de la case*/
          printf(" |");
        }

        else {
          /*Bords inférieur et supérieur de chaque case */
          printf("+---+");
        }

      }
      printf("\n");
    }
  }

}




int jouer (int ttint_plateau[N][N], int int_joueur, int int_x){
  int int_position; // position relative (ligne) à la colonne int_x
  int int_contenu; // contenu du tableau a la position int_position

  int_position =N-1; // On part du bas de la colonne

  if (int_x < 0 || int_x > N-1){
    printf("Erreur la grille ne dispose que de %d  colonnes\n",N-1);
    /*Valeur d'erreur*/
    return(0);
  }

  else {
    int_contenu = ttint_plateau[int_position][int_x];
    /*On part du bas de la colonne et on remonte jusqu'à trouver une place */
    while (int_contenu !=-1 && int_position >=0 ){
      int_position--;
      int_contenu=ttint_plateau[int_position][int_x];
    }
    /*S'il n'y a pas de place*/
    if (int_contenu !=-1){
      printf("La colonne est pleine\n");
      /*Valeur d'erreur*/
      return(0);

    }
    /*Le joueur 1 veut jouer à la position et il y a de la place*/
    else if (int_joueur ==1) {
      ttint_plateau[int_position][int_x]=1;
      /*Valeur de succés : le joueur a joué au bon endroit*/
      return(1);
    }
    /*Le joueur 2 veut jouer à la position et il y a de la place*/
    else {
      ttint_plateau[int_position][int_x]=2;
      /*Valeur de succés : le joueur a joué au bon endroit*/
      return(1);
    }
  }
}

int aligneMotif(int ttint_plateau[N][N], int int_i, int int_j){
  int int_nombreAligne; // compteur de nombre de motifs alignés
  int int_k; // compteur de ligne partant de la ligne int_i
  int int_m; // compteur de colonne partant de la colonne int_j
  int int_motif; // contenu de la case à la position [int_i][int_j]

  /*Initialisation*/
  int_k =int_i;
  int_m = int_j;
  int_nombreAligne =0;
  int_motif = ttint_plateau[int_i][int_j];

  /*La case est vide*/
  if(int_motif == -1){
    /*renvoie -1 car il n'y a pas d'alignement de motif du joueur 1 ou joueur 2*/
    return(-1);
  }
  else {
    /* On vérifie les directions possibles partant de la case i,j en s'assurant de ne pas sortir du tableau*/
    /*Il suffit de vérifier les directions d'alignement possibles : | , / , \ et _   */
    while(int_nombreAligne<4 && int_m>= 0 ){
      /*Le motif n'est plus le meme que celui à la position [int_i][int_j]*/
      if (int_motif !=ttint_plateau[int_k][int_m]){
        int_nombreAligne =5; // Valeur permettant de sortir de la boucle
      }
      /*On a trouvé le meme motif qu'en [int_i][int_j]*/
      else {
        int_nombreAligne++;
        int_m--;

      }
    }
    if (int_nombreAligne !=4 ) {
              /*Réinitialisation , on n'a pas trouvé le motif 4 fois vers la gauche */
              int_nombreAligne =0;
              int_k =int_i;
              int_m = int_j;

              while(int_nombreAligne<4 && int_k >=0 && int_k <N){
                if (int_motif !=ttint_plateau[int_k][int_m]){
                  int_nombreAligne =5; // Valeur permettant de sortir de la boucle
                }
                /*On a trouvé le meme motif qu'en [int_i][int_j]*/
                else {
                  int_nombreAligne++;
                  int_k--;
              }
            }

              if (int_nombreAligne !=4 ) {
                        /*Réinitialisation , on n'a pas trouvé le motif 4 fois vers le haut*/
                        int_nombreAligne =0;
                        int_k =int_i;
                        int_m = int_j;
                        while(int_nombreAligne<4 && int_k >=0 && int_k <N && int_m>= 0 && int_m < N){
                          if (int_motif !=ttint_plateau[int_k][int_m]){
                            int_nombreAligne =5; // Valeur permettant de sortir de la boucle
                          }
                          /*On a trouvé le meme motif qu'en [int_i][int_j]*/
                          else {
                            int_nombreAligne++;
                            int_k--;
                            int_m--;
                          }
                          }
                        if (int_nombreAligne !=4 ) {
                              /*Réinitialisation , on n'a pas trouvé le motif 4 fois vers la diagonale supérieure gauche*/
                              int_nombreAligne =0;
                              int_k =int_i;
                              int_m = int_j;
                              while(int_nombreAligne<4 && int_k >=0 && int_k <N && int_m>= 0 && int_m < N){
                                if (int_motif !=ttint_plateau[int_k][int_m]){
                                  int_nombreAligne =5; // Valeur permettant de sortir de la boucle
                                }
                                else {
                                  int_nombreAligne++;
                                  int_k--;
                                  int_m++;
                                  }
                                }
                              /*On n'a pas trouvé de motifs se répétant quatre fois vers la diagonale supérieure droite*/
                              if (int_nombreAligne !=4 ) {
                                /*renvoie -1 car il n'y a pas d'alignement de motif du joueur 1 ou joueur 2*/
                                int_motif=-1;

                              }
                          }
                  }
    }
  /* -1 si il n'y a pas de motifs sinon renvoie un entier (1 ou 2)  caractérisant le joueur pour lequel il existe 4 motifs alignés*/
  return(int_motif);
  }
}

int aGagne(int ttint_plateau[N][N]){
  int int_resultatJeu; // 0 si match nul , 1 ou 2 si un joueur a gagné et -1 si le jeu n'est pas terminé
  int int_motifAligne; // -1 si on ne trouve pas de motif partant de [int_i][int_j] sinon c'est le numéro du joueur ayant gagné
  int int_i; // lignes de la grille
  int int_j; // colonnes de la grille

  /*Initialisation*/
  int_i=N-1; // Puisque les cases se remplissent du bas vers le haut des colonnes on vérifie avec une boucle décroissante pour gagner en complexité dans le meilleur des cas
  int_resultatJeu= 0;
  int_motifAligne =-1;

  /*Pour chaque case du tableau on vérifie s'il existe un motif partant de cette case*/
  while (int_i >= 0 && int_motifAligne ==-1 ){
    int_j=N-1;
    while (int_j >=0 && int_motifAligne ==-1 ){
    int_motifAligne = aligneMotif(ttint_plateau,int_i,int_j);
    int_j--;
    }
  int_i--;
  }

  /*Aucun des deux joueurs n'a gagné*/
  if (int_motifAligne == -1){
    /*On vérifie si on peut encore jouer*/
    int_i=0;
    while (int_i < N && int_resultatJeu !=-1){
      /*Il suffit uniquement de vérifier si la première ligne de la grille possède une place vide*/
      if (ttint_plateau[0][int_i]== -1){
        int_resultatJeu = -1;
      }
      int_i++;
    }
  }

  else{
    /*int_resultatJeu prend la valeur du joueur qui a gagné*/
    int_resultatJeu = int_motifAligne;

    }
    return(int_resultatJeu);
}



void tourDeJeu (int ttint_plateau[N][N]){
  int int_joueur; // détermine le joueur en train de jouer
  int int_resultatPartie; // stocke la valeur de aGagne à chaque tour
  int int_choixJoueur; // stocke le choix du joueur

  /*C'est le joueur 1 qui commence*/
  int_joueur =1;
  int_resultatPartie =-1; // On suppose avoir fait l'initialisation au préalable donc on peut jouer


  while (int_resultatPartie ==-1){
    system("clear"); // permet de réinitialiser l'affichage
    affichage(ttint_plateau);
    printf("Au joueur %d de jouer\n",int_joueur);

    /*Tant que l'utilisateur n'entre pas une valeur valide on lui demande de choisir une colonne*/
    int_choixJoueur = saisieEntierNaturel();
    while (jouer(ttint_plateau,int_joueur,int_choixJoueur) == 0){
      printf("Vous ne pouvez pas jouer à cet endroit\n");
      printf("Au joueur %d de jouer\n",int_joueur);
      int_choixJoueur = saisieEntierNaturel();
    }
    int_resultatPartie = aGagne(ttint_plateau);
    /*Permet de passer au joueur suivant*/
    int_joueur = 1+((int_joueur)%2);

  }

  /* Affichage de la grille résultat*/
  system("clear");
  affichage(ttint_plateau);
  if (int_resultatPartie == 0){
    printf("Match Nul !\n");
  }
  else{
    printf("Le joueur %d a gagné !\n",int_resultatPartie);
  }


}
