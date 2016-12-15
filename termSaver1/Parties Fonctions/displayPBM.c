#include <stdio.h>
#include <stdlib.h>

#define LARGEUR_CONSOLE 80
#define HAUTEUR_CONSOLE 22

void centerX(int width, const char* str) {
  for (int a = 0; a < ((LARGEUR_CONSOLE - (width*2)) / 2); a++) {
    putchar(' '); // Ajoute un espace tant que l'image n'est pas centrée horizontalement
  }
  printf("%s", str); // Affiche l'image
}

void centerY(int height) {
  for (int b = 0; b < ((HAUTEUR_CONSOLE - height) / 2); b++) {
    putchar('\n'); // Ajoute un retour à la ligne tant que l'image n'est pas centrée verticalement
  }
}

void displayPBM(FILE* fichier, int size, int width, int height, char *tableau) {
  tableau = malloc(size * sizeof(char)); // Le tableau prend la taille de l'image

  centerY(height);
  for (int i = 0; i < (height + 1); i++) { // Parcourt toutes les lignes
    fgets(tableau, size, fichier); // Rentre les caractères dans le tableau

    for (int j = 0; j < size; j++) { // Parcourt toutes les colonnes
      if (tableau[j] == '0') {tableau[j] = ' ';} // Si il y a un 0 dans le fichier PBM -> Le remplace par un ESPACE
      else if (tableau[j] == '1') {tableau[j] = 'X';} // Si il y a un 1 dans le fichier PBM -> Le remplace par un X
    }

    centerX(width, tableau); // Affiche l'image centrée
  }

  free(tableau);
}
