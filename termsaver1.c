#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "inc/functions.h"
#include "inc/historical.h"

int main(int argc, char *argv[]) {
	/* ============================================
	==================== CLEAR ====================
	============================================ */
	system("clear");

	int MAX = 5;
	int MIN = 1;
	int nombreAleatoire = 0;
	srand(time(NULL));
	nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;

	char path[25];
    strcpy(path, getenv("EXIASAVER_PBM1"));
	sprintf(chaine, "image_%d.pbm", nombreAleatoire);
	strcat(path, chaine);

	Screensaver scrnsave;
	Static termsaver1;

	termsaver1.file = path;
	scrnsave.stat = termsaver1;
	scrnsave.dyn = NULL;
	scrnsave.inter = NULL;

	/*
		TODO writeHist
	*/

	/* =========================================================
	==================== FERMER SCREENSAVER ====================
	========================================================= */
	printf("\n");
	c = getchar(); // ATTEND QUE L'UTILSATEUR ENTRE UNE TOUCHE POUR FERMER LE PROGRAMME
	if (c == ' ') {
		return EXIT_SUCCESS;
	}
}