#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void randomFichier() {
  FILE* fichier = NULL;
  char chaine[10];
  int MAX = 4;
  int MIN = 1;
  int nombreAleatoire = 0;
  
  srand(time(NULL));
  nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;

  sprintf(chaine, "PBM/fichier_%d.pbm", nombreAleatoire);
  fichier = fopen(chaine, "r"); // OUVRE LE FICHIER EN LECTURE
}
