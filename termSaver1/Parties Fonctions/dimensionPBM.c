#include <stdio.h>

int widthPBM(FILE* fichier) {
  int width = 0; // LARGEUR
  int height = 0; // HAUTEUR

  fseek (fichier, 8, SEEK_SET); // Skip les premiers éléments pour aller aux dimensions de l'image
  fscanf(fichier, "%d %d", &width, &height); // Récupère les dimensions de l'image

  return width; // Renvoie la largeur de l'image
}

int heightPBM(FILE* fichier) {
  int width = 0; // HAUTEUR
  int height = 0; // LARGEUR

  fseek (fichier, 8, SEEK_SET); // Skip les premiers éléments pour aller aux dimensions de l'image
  fscanf(fichier, "%d %d", &width, &height); // Récupère les dimensions de l'image

  return height; // Renvoie la hauteur de l'image
}
