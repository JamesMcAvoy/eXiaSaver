#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Pour le rand
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int main(int argc, char **argv) {

	//Paramètre -stat
	if(argc == 2) {
		if(argv[0] = "-stat") {

			FILE* fichier = NULL;
			char chaine[TAILLE_MAX] = "";
			int compteurStatique = 0;
			int compteurDynamique = 0;
			int compteurInteractif = 0;
    	int a=0;
			int val;
			int i;
    	int statik = 1;
			int dynamic = 2;
			int interactive = 3;
			int date[3][TAILLE_MAX] = {0};
			int heure[3][TAILLE_MAX] = {0};
			int mode;
			//char nom[50] = {""};
    	char* caractereLu;
			char jour[0];
			char chaineLu[0];

			printf("( ͡° ͜ʖ ͡°) STATISTIQUES ( ͡° ͜ʖ ͡°)\n\n");
    	printf(" Nous vous proposons 3 modes         \n");
    	printf(" d'affichages :                       \n\n");
			printf("1.Afficher l'historique\n ");
			printf("2.Combien de fois est utilisé les différents écran de veille\n");
			printf("3.Dernier utilisé\n");


			while ((a!=1)||(a!=2)||(a!=3))
			{
				fichier = fopen("histo.txt", "r+");


				printf("Quel type d'affichage voulez-vous ?\n");
				scanf("%d", &a);

				if (a ==1)
				{
						fichier = fopen("histo.txt", "r");
						while (fgetc(fichier) != EOF){
							fscanf(fichier, "%d-%d-%d %d:%d:%d;%d", &date[0][i], &date[1][i], &date[2][i], &heure[0][i], &heure[1][i], &heure[2][i], &mode);
							printf("%d-%d-%d %d:%d:%d\n", date[0][i], date[1][i], date[2][i], heure[0][i], heure[1][i], heure[2][i]);

						}

						printf("\n");
						//printf("Le lanceur eXiaSaver a été lancé %d fois le %s.\n", jour[0],chaineLu);

					}



				if (a == 2){
					fichier = fopen("histo.txt", "r");
					while (fgetc(fichier) != EOF)
					{

						fscanf(fichier, "%d-%d-%d %d:%d:%d;%d",  &date[i][0], &date[i][1], &date[i][2], &heure[i][0], &heure[i][1], &heure[i][2], &mode);
						if (mode == statik){
							compteurStatique++;
						}
						if (mode == dynamic ){
							compteurDynamique++;
						}
						if (mode == interactive){
							compteurInteractif++;
					}
					}
					printf("Le screensaver Statique a été utilisé en totale :%d\n", compteurStatique);
					printf("Le screensaver Dynamique a été utilisé en totale :%d\n", compteurDynamique);
					printf("Le screensaver Interactif a été utilisé en totale :%d\n", compteurInteractif);

			}
				if (a == 3){
						fichier = fopen("histo.txt", "r");
						fgets(chaine, 20, fichier);
						printf("%s\n", chaine);

				}
	 		}
			fclose(fichier);
			
		}
	}

    srand(time(NULL));

    int nbgen = (rand() % 2) + 1;

    system("clear");

    char *path;
    char *term;

    //path=~/ExiaSaver/termsaverN
    strcpy(path, getenv("EXIASAVER_HOME"));

    switch(nbgen) {
		case 1:
			strcpy(term, "termsaver1");
			strcat(path, term);
			system(path);
			break;

		case 2:
			strcpy(term, "termsaver2");
			strcat(path, term);
			system(path);
			break;
	}

	return 0;

}
