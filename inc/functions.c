#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void display(Screensaver scrnsave) {

	FILE *fichier = NULL;
	int i = 0;
	char caractere;
	char c;
	char chaine[10];

	int test = 0;
	int dimension[2];

	int width = 0;
	int height = 0;
	int size = 0;
	char *tableau;

	if(scrnsave.stat != NULL)
		fichier = fopen(scrnsave.stat.file, "r"); // OUVRE LE FICHIER EN LECTURE
	else if(scrnsave.dyn != NULL)
		fichier = fopen(scrnsave.dyn.file, "r"); // OUVRE LE FICHIER EN LECTURE
	else if(scrnsave.dyn != NULL)
		fichier = fopen(scrnsave.inter.file, "r"); // OUVRE LE FICHIER EN LECTURE
	else {
		printf("Le fichier ne peut pas être ouvert\n");
		return;
	}

	/* =====================================================
	==================== TAILLE FICHIER ====================
	===================================================== */
	  if (fichier != NULL) { // SI L'IMAGE EST BIEN RECUE
	    fseek (fichier, 8, SEEK_SET); // SKIP LES PREMIERS ELEMENTS POUR ALLER A L'IMAGE 0/1
	    fscanf(fichier, "%d %d", &dimension[0], &dimension[1]);
	    width = dimension[0];
	    height = dimension[1];
	    size = 2*width*height;
	    tableau = malloc(size * sizeof(char));


	/* ========================================================
	==================== AFFICHAGE FICHIER ====================
	======================================================== */
	    do {
	      caractere = fgetc(fichier); // AFFECTE LA LIGNE DANS CHAINE
	      if (caractere == '0') {caractere = ' '; tableau[i] = caractere; i++;} // SI IL Y A UN 0 DANS LE FICHIER PBM -> LE REMPLACER PAR UN ESPACE
	      else if (caractere == ' ') {caractere = ' '; tableau[i] = caractere; i++;} // MET LESPACE DANS LE TABLEAU
	      else if (caractere == '\n') {caractere = '\n'; tableau[i] = caractere; i++;} // MET LE RETOUR A LA LIGNE DANS LE TABLEAU
	      else if (caractere == '1') {caractere = 'X'; tableau[i] = caractere; i++;} // SI IL Y A UN 1 DANS LE FICHIER PBM -> LE REMPLACER PAR UN X
	    } while (caractere != EOF); // LIT JUSQU'A LA FIN DU FICHIER

	    for(int j=0; j<size; j++) {
			printf("%c", tableau[j]);

	    }

		free(tableau);
	}


	/* =====================================================
	==================== ERREUR FICHIER ====================
	===================================================== */
	else {printf("Le fichier ne peut pas être ouvert\n");} // SI L'IMAGE N'EST PAS RECUE


}