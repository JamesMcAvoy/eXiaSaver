#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "historical.h"

void writeHist(Historical hist) {
	
	system("date +\"%D %X;\" > histo.txt");

	FILE* fichier = NULL;
	fichier = fopen("historique.txt", "a+");
	
	char chaine[5];
	sprintf(chaine, "%d\n", hist.type);
	
	if (fichier != NULL) {
		fputs(chaine, fichier);
		fclose(fichier);
	}

}
