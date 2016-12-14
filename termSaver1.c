#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>

#include "randomPBM.h"
#include "dimensionPBM.h"
#include "displayPBM.h"


int main(int argc, char *argv[]) {
/* ============================================
==================== CLEAR ====================
============================================ */
  system("clear"); // EFFACE LE TERMINAL


/* ================================================
==================== VARIABLES ====================
================================================ */
/* FICHIER / TAILLE */
  FILE* fichier = NULL;
  fichier = NULL;
  int width = 0;
  int height = 0;
  int size = 0;
  char *tableau;
  char c;

/* GENERATION DE L'IMAGE */
  int MIN = 1;
  int MAX = 5;
  int nombreAleatoire;
  char chaine[10];

  nombreAleatoire = randomPBM(MIN, MAX); // GENERE UN NOMBRE ALEATOIRE ENTRE 1 ET 5
  sprintf(chaine, "../termSaver1/PBM/image_%d.pbm", nombreAleatoire); // STOCKE LE CHEMIN DANS LA VARIABLE chaine
  fichier = fopen(chaine, "r"); // OUVRE LE FICHIER EN LECTURE


/* =====================================================
==================== TAILLE FICHIER ====================
===================================================== */
  width = widthPBM(fichier); // RECUPERE LA LARGEUR DE L'IMAGE (sans les espaces)
  height = heightPBM(fichier); // RECUPERE LA HAUTEUR DE L'IMAGE
  size = 2*width*height; // RECUPERE LA TAILLE TOTALE DE L'IMAGE

/* ========================================================
==================== AFFICHAGE FICHIER ====================
======================================================== */
pid_t fils;
int father;

fils = fork();
father = getppid();
if(fils == 0)
{
  displayPBM(fichier, size, width, height, tableau);
}
else
{
    father = wait(NULL);
}


/* =========================================================
==================== FERMER SCREENSAVER ====================
========================================================= */
  printf("\n");
  c = getchar(); // ATTEND QUE L'UTILSATEUR ENTRE UNE TOUCHE POUR FERMER LE PROGRAMME
  if (c == ' ') {return EXIT_SUCCESS;}
}
