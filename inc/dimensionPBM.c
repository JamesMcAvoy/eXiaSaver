#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int widthPBM(FILE* fichier) {
  int width = 0;
  int height = 0;

  if (fichier != NULL) { // SI L'IMAGE EST BIEN RECUE
    fseek (fichier, 8, SEEK_SET); // SKIP LES PREMIERS ELEMENTS POUR ALLER A L'IMAGE 0/1
    fscanf(fichier, "%d %d", &width, &height);
    return width;
  }
  else {return 0;}
}

int heightPBM(FILE* fichier) {
  int width = 0;
  int height = 0;

  if (fichier != NULL) { // SI L'IMAGE EST BIEN RECUE
    fseek (fichier, 8, SEEK_SET); // SKIP LES PREMIERS ELEMENTS POUR ALLER A L'IMAGE 0/1
    fscanf(fichier, "%d %d", &width, &height);
    return height;
  }
  else {return 0;}
}
