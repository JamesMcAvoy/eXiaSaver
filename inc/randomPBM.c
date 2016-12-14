#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int randomPBM(int MIN, int MAX) {
  int nombreAleatoire = 0;
  srand(time(NULL));
  nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
  return nombreAleatoire;
}
