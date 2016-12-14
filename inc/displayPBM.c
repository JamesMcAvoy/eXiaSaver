#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void displayPBM(FILE* fichier, int size, int width, int height, char *tableau) {
  tableau = malloc(size * sizeof(char));
  if (fichier != NULL) {
    centerY(height); // SE PREPARE A AFFICHER L
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

  else {printf("Le fichier ne peut pas être ouvert\n");} // SI L'IMAGE N'EST PAS RECUE
}
