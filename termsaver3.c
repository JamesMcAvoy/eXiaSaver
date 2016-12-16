#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <curses.h> //-lncurses compiler
#include "inc/functions.h"

#define K_UP	122 //Z
#define K_RIGHT	100 //D
#define K_DOWN	115 //S
#define K_LEFT	113 //Q
#define LEAVE	99  //C

/**
 * Input key
 */
int key() {
	WINDOW *w;
	initscrn(w);
	noecho();
	timeout(100);
	return getch();
}

int main(int argc, char **argv) {

	/* écrit dans l'historique */
	Historical hist;
	char histFile[10];
	strcpy(histFile, "histo.txt");
	strcpy(path, getenv("EXIASAVER_HOME"));
	hist.file = strcat(path, histFile);
	hist.type = 3;

	writeHist(hist);

	//variables
	char path[50];
	char pathPBM[50];
	char filePBM[25];
	strcpy(path, getenv("EXIASAVER_HOME"));
	strcpy(pathPBM, getenv("EXIASAVER3_PBM"));

	/* up right down left */
	strcpy(filePBM, "avion_up.pbm");
	char *pic1 = strcat(pathPBM, filePBM);
	strcpy(pathPBM, getenv("EXIASAVER3_PBM"));

	strcpy(filePBM, "avion_right.pbm");
	char *pic2 = strcat(pathPBM, filePBM);
	strcpy(pathPBM, getenv("EXIASAVER3_PBM"));

	strcpy(filePBM, "avion_down.pbm");
	char *pic3 = strcat(pathPBM, filePBM);
	strcpy(pathPBM, getenv("EXIASAVER3_PBM"));

	strcpy(filePBM, "avion_left.pbm");
	char *pic4 = strcat(pathPBM, filePBM);

	/* déclaration screensaver interactif */
	Interactive inter;
	inter.file[0] = pic1;
	inter.file[1] = pic2;
	inter.file[2] = pic3;
	inter.file[3] = pic4;

	char *tableau;
	FILE *fichier = NULL;
	int width = 0,
		height = 0,
		size = 0;

	width = widthPBM(fichier);
	height = heightPBM(fichier);
	size = 2*width*height; 

	int randint = randomnb(1, 4);

	fichier = fopen(inter.file[randint--], "r");

	displayPBM(fichier, size, width, height, tableau);

	fclose(fichier);

	char c;

	switch(randint) {
		case 1:
			c = K_UP;
			break;
		case 2:
			c = K_RIGHT;
			break;
		case 3:
			c = K_DOWN;
			break;
		case 4:
			c = K_LEFT;
			break;
	}

	while(c != LEAVE) {

		switch(c) {
			case K_UP:
				height--;

				fichier = NULL;
				fichier = fopen(inter.file[0], "r");
				displayPBM(fichier, size, width, height, tableau);
				fclose(fichier);
				break;
			case K_RIGHT:
				width++;

				fichier = NULL;
				fichier = fopen(inter.file[1], "r");
				displayPBM(fichier, size, width, height, tableau);
				fclose(fichier);
				break;
			case K_DOWN:
				height++;

				fichier = NULL;
				fichier = fopen(inter.file[2], "r");
				displayPBM(fichier, size, width, height, tableau);
				fclose(fichier);
				break;
			case K_LEFT:
				width--;

				fichier = NULL;
				fichier = fopen(inter.file[3], "r");
				displayPBM(fichier, size, width, height, tableau);
				fclose(fichier);
				break;
		}

		c = key();

	}

	return 0;

}
