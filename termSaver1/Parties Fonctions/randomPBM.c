#include <stdlib.h>
#include <time.h>

int randomPBM(int MIN, int MAX) {
  int nombreAleatoire = 0;

  srand(time(NULL));
  nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN; // Génère un nombre aléatoire entre MIN et MAX

  return nombreAleatoire; // Retourne le nombre aléatoire
}
