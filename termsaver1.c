#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

#include "/inc/fonctions.h"


int main(int argc, char *argv[]) {
/* ==================== CLEAR ==================== */
  system("clear"); // EFFACE LE TERMINAL


/* ==================== VARIABLES ==================== */
  /* FICHIER / TAILLE */
  FILE* fichier = NULL;
  fichier = NULL;
  int width = 0; // Largeur
  int height = 0; // Hauteur
  int size = 0; // Taille de l'image
  char *tableau; // Tableau permattant de stocker l'image

  /* GENERATION DE L'IMAGE */
  int MIN = 1; // Numéro de l'image le plus bas
  int MAX = 5; // Numéro de l'image le plus haut
  int nombreAleatoire;
  //const char *EXIASAVER_HOME;
  char EXIASAVER1_PBM[50];
  //getenv("EXIASAVER1_PBM");
  //const char *EXIASAVER2_PBM;
  //const char *EXIASAVER3_PBM;
  strcpy(EXIASAVER1_PBM, "/PBM");
  char chaine[50];


  nombreAleatoire = randomnb(MIN, MAX); // Génère un nombre aléatoire entre MIN et MAX
  switch(nombreAleatoire) {
    case 1: strcpy(chaine, EXIASAVER1_PBM); strcat(chaine, "/image_1.pbm"); break;
    case 2: strcpy(chaine, EXIASAVER1_PBM); strcat(chaine, "/image_2.pbm"); break;
    case 3: strcpy(chaine, EXIASAVER1_PBM); strcat(chaine, "/image_3.pbm"); break;
    case 4: strcpy(chaine, EXIASAVER1_PBM); strcat(chaine, "/image_4.pbm"); break;
    case 5: strcpy(chaine, EXIASAVER1_PBM); strcat(chaine, "/image_5.pbm"); break;
  }
  //sprintf(chaine, "../PBM1/image_%d.pbm", nombreAleatoire); // Stocke le chemin dans la variable <chaine>
  fichier = fopen(chaine, "r"); // Ouvre le fichier en lecture
/* ==================== VARIABLES ==================== */


  if (fichier != NULL) { // Si le fichier est bien reçu
/* ==================== TAILLE FICHIER ==================== */
    width = widthPBM(fichier); // Récupère la largeur l'image (sans les espaces)
    height = heightPBM(fichier); // Récupère la hauteur de l'image
    size = 2*width*height; // Récupère la taille de l'image (avec les espaces)


/* ==================== AFFICHAGE FICHIER ==================== */
    pid_t fils; // Initialisation du processus fils
    int father; // Initialisation du processus père
    fils = fork(); // Créé le processus fils

    if(fils == 0) { // Exécute le code dans le processus fils
      displayPBM(fichier, size, width, height, tableau); // Affiche l'image
      system("stty cbreak -echo");
      getchar(); // Attend que l'utilisateur appuie sur une touche
      system("stty cooked echo"); // Permet de fermer le programme sans appuyer sur ENTRER
    }
    else {father = wait(NULL); system("clear"); return EXIT_SUCCESS;} // Permet de retourner dans le processus père à la fin du programme

  }

  else {printf("Le fichier n'a pas pu être reçu...\n"); return EXIT_FAILURE;}
}
