/*!
\file puissance4.h
\author CHOMEL Louis
\date Mercredi 6 Novembre 2019
\version 1.0
\brief Prototypes de fonctions pour le jeu puissance4
*/

/*Taille fixe de la grille*/
#define N 5



/* Librairie permettant notamment d'utiliser la fonction scanf*/
#include <stdio.h>




/*!
\fn void init(int ttint_plateau[N][N])
\author CHOMEL Louis
\version 1.0
\brief Permet d'initialiser le plateau avec -1 pour chaque case
\date Mercredi 6 Novembre 2019
\version 1.0
\param ttint_plateau Tableau modélisant les cases du plateau
*/
void init (int ttint_plateau[N][N]);


/*!
\fn void affGrille(int ttint_plateau[N][N])
\author CHOMEL Louis
\version 1.0
\brief Permet d'afficher les valeurs d'un tableau 2D (utile uniquement pour le débogage)
\date Mercredi 6 Novembre 2019
\version 1.0
\param ttint_plateau Tableau modélisant les cases du plateau
*/
void affGrille(int ttint_plateau[N][N]);


/*!
\fn void affichage(int ttint_plateau[N][N])
\author CHOMEL Louis
\version 1.0
\brief Permet de visualiser le plateau du puissance 4
\date Mercredi 6 Novembre 2019
\version 1.0
\param ttint_plateau Tableau modélisant les cases du plateau
*/
void affichage(int ttint_plateau[N][N]);


/*!
\fn int jouer(int ttint_plateau[N][N], int int_joueur, int int_x)
\author CHOMEL Louis
\brief Modifie la valeur du tableau selon le coup du joueur
\date Mercredi 6 Novembre 2019
\version 1.0
\param ttint_plateau Tableau modélisant les cases du plateau
\param int_joueur numéro de joueur (1 ou 2)
\param int_x choix du coup du joueur
*/
int jouer (int ttint_plateau[N][N], int int_joueur, int int_x);


/*!
\fn int aligneMotif(int ttint_plateau[N][N], int int_i, int int_j)
\author CHOMEL Louis
\brief Vérifie s'il existe 4 fois un motif (X ou O) partant de la position [int_i][int_j]
\date Mercredi 6 Novembre 2019
\version 1.0
\param ttint_plateau Tableau modélisant les cases du plateau
\param int_i ligne (position)
\param int_j colonne (position)
*/
int aligneMotif(int ttint_plateau[N][N], int int_i, int int_j);


/*!
\fn int aGagne(int ttint_plateau[N][N])
\author CHOMEL Louis
\version 1.0
\brief Vérifie si le jeu continue ou s'il s'arrete avec la vitoire d'un des deux joueurs ou le match nul
\date Mercredi 6 Novembre 2019
\param ttint_plateau Tableau modélisant les cases du plateau
*/
int aGagne(int ttint_plateau[N][N]);


/*!
\fn void tourDeJeu(int ttint_plateau[N][N])
\author CHOMEL Louis
\brief Permet de faire jouer les deux joueurs chacun leur tour jusqu'à ce qu'un des joueurs gagne ou que la grille soit pleine
\date Mercredi 6 Novembre 2019
\version 1.0
\param ttint_plateau Tableau modélisant les cases du plateau
*/
void tourDeJeu (int ttint_plateau[N][N]);
