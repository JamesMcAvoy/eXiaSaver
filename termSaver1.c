#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
//#include "../Fonctions/statique.h"


void centerX(int width, const char* str) {
  for (int a=0; a<((80-(width*2-1))/2); a++) {
    putchar(' ');
  }
  printf("%s", str);
}

void centerY(int height) {
  for (int b=0; b<((23-height)/2); b++) {
    putchar('\n');
  }
}


int main(int argc, char *argv[]) {
/* ============================================
==================== CLEAR ====================
============================================ */
  system("clear"); // EFFACE LE TERMINAL


/* ================================================
==================== VARIABLES ====================
================================================ */
  FILE* fichier = NULL;
  int i = 0;
  char caractere;
  char c;
  char chaine[10];

  fichier = NULL;
  int width = 0;
  int height = 0;
  int size = 0;
  char *tableau;

  int MAX = 5;
  int MIN = 1;
  int nombreAleatoire = 0;
  srand(time(NULL));
  nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;

  sprintf(chaine, "PBM/image_%d.pbm", nombreAleatoire);
  fichier = fopen(chaine, "r"); // OUVRE LE FICHIER EN LECTURE


/* =====================================================
==================== TAILLE FICHIER ====================
===================================================== */
  if (fichier != NULL) { // SI L'IMAGE EST BIEN RECUE
    fseek (fichier, 8, SEEK_SET); // SKIP LES PREMIERS ELEMENTS POUR ALLER A L'IMAGE 0/1
    fscanf(fichier, "%d %d", &width, &height);
    size = 2*width*height;
    tableau = malloc(size * sizeof(char));


/* ========================================================
==================== AFFICHAGE FICHIER ====================
======================================================== */
    centerY(height); // SE PREPARE A AFFICHER L'IMAGE VERTICALEMENT
    for (int i=0; i<(height+1); i++) { // PARCOURT TOUTES LES LIGNES
      fgets(tableau, size, fichier); // RENTRE LES CARACTERES DANS LE TABLEAU
      for (int j=0; j<size; j++) { // PARCOURT TOUTES LES COLONNES
        if (tableau[j] == '0') {tableau[j] = ' ';} // SI IL Y A UN 0 DANS LE FICHIER PBM -> LE REMPLACER PAR UN ESPACE
        else if (tableau[j] == '1') {tableau[j] = 'X';} // SI IL Y A UN 1 DANS LE FICHIER PBM -> LE REMPLACER PAR UN X
      }
      centerX(width, tableau); // AFFICHE L'IMAGE CENTREE HORIZONTALEMENT
    }

    free(tableau);
  }


/* =====================================================
==================== ERREUR FICHIER ====================
===================================================== */
  else {printf("Le fichier ne peut pas être ouvert\n");} // SI L'IMAGE N'EST PAS RECUE


/* =========================================================
==================== FERMER SCREENSAVER ====================
========================================================= */
  printf("\n");
  c = getchar(); // ATTEND QUE L'UTILSATEUR ENTRE UNE TOUCHE POUR FERMER LE PROGRAMME
  if (c == ' ') {return EXIT_SUCCESS;}
}
