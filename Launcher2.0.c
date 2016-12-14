#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Pour le rand
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>
#define TAILLE_MAX 1000

int main(int argc, char **argv) {

	//Paramètre -stat
	if(argc == 2) {
		if(argv[0] = "-stat") {

		FILE* fichier = NULL;
		char chaine[TAILLE_MAX] = "";
    int a=0;
    int x = 1;
    int caractereLu, ligne = 1;
		char* jour[];
    printf("( ͡° ͜ʖ ͡°) STATISTIQUES ( ͡° ͜ʖ ͡°)\n\n");
    printf(" Nous vous proposons 3 modes         \n");
    printf(" d'affichages :                       \n\n");
		printf("1. Nombre utilisation par jour\n ");
		printf("2. Combien de fois est utilisé les différents écran de veille\n");
		printf("3. Dernier utilisé\n");


		while ((a!=1)||(a!=2)||(a!=3)){
			fichier = fopen("histo.txt", "r+");

				{
				printf("Quel type d'affichage voulez-vous ?\n");
				scanf("%d", &a);

				if (a ==1){
						fichier = fopen("histo.txt", "r");
						jour = fgets(chaine, 10, fichier);
						end of line


						}
				}

				}

	}

	pid_t fils;

    srand(time(NULL));

    int nbgen = (rand() % 3) + 1;
    int father;

    system("clear");

    char path[25];
    char term[25];

    //path=~/ExiaSaver/termsaverN
    strcpy(path, getenv("EXIASAVER_HOME"));

    switch(nbgen) {
	    case 1:
			fils = fork();
			father = getppid();
			if(fils == 0) {
				strcpy(term, "termsaver1");
				strcat(path, term);
				system(path);
			}
			else father = wait(NULL);
			break;

		case 2:
			strcpy(term, "termsaver2");
			strcat(path, term);
			system(path);
			break;

		case 3:
			strcpy(term, "termsaver3");
			strcat(path, term);
		    system(path);
		    break;
	}

	return 0;

}
