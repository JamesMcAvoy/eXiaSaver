#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/* ==================== TERMSAVER DYNAMIQUE ==================== */
void initialisationHeure()
{
  #define centrer(x,y) printf("\033[%d;%dH", (x), (y))
  #define TAILLE_MAX 80
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    //On met les secondes, minutes, heures dans différentes variables
    int timeSeconde1 = (instant.tm_sec)/10;
    int timeSeconde2 = (instant.tm_sec)-(timeSeconde1*10);
    int timeMinute1 = (instant.tm_min)/10;
    int timeMinute2 = (instant.tm_min)-(timeMinute1*10);
    int timeHeure1 = (instant.tm_hour)/10;
    int timeHeure2 = (instant.tm_hour)-(timeHeure1*10);


    //On met les secondes, minutes, heures dans un tableau
    int Heure[8];
    Heure[0] = timeHeure1;
    Heure[1] = timeHeure2;
    Heure[2] = 25;
    Heure[3] = timeMinute1;
    Heure[4] = timeMinute2;
    Heure[5] = 25;
    Heure[6] = timeSeconde1;
    Heure[7] = timeSeconde2;

    int z = 0;
    int tailleFichier = 1;

    int y=35-((4+tailleFichier*2)*3+5), x = 10;
    int i = 0, j = 0; //Variable pour les boucles
    FILE* fichier = NULL; //On met le pointeur à null
    char chaine[TAILLE_MAX];
    int chaine2[2];
    int a,b;

    //Boucle pour récuperer les images PBM correspondant à chaque chiffre de l'heure
    for (z = 0; z < 8; z++)
    {
        switch(Heure[z])
        {
            case 0 :
                fichier = fopen("../PBM2/chiffre_0.pbm", "r");
            break;
            case 1 :
                fichier = fopen("../PBM2/chiffre_1.pbm", "r");
            break;
            case 2 :
                fichier = fopen("../PBM2/chiffre_2.pbm", "r");
            break;
            case 3 :
                fichier = fopen("../PBM2/chiffre_3.pbm", "r");
            break;
            case 4 :
                fichier = fopen("../PBM2/chiffre_4.pbm", "r");
            break;
            case 5 :
                fichier = fopen("../PBM2/chiffre_5.pbm", "r");
            break;
            case 6 :
                fichier = fopen("../PBM2/chiffre_6.pbm", "r");
            break;
            case 7 :
                fichier = fopen("../PBM2/chiffre_7.pbm", "r");
            break;
            case 8 :
                fichier = fopen("../PBM2/chiffre_8.pbm", "r");
            break;
            case 9 :
                fichier = fopen("../PBM2/chiffre_9.pbm", "r");
            break;
            case 25 :
                fichier = fopen("../PBM2/separateur.pbm", "r");
            break;

        }

        if(fichier != NULL)//On vérifie si le fichier est ouvert
        {
            fseek(fichier, 8, SEEK_SET);
            fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]);
            a = chaine2[0];
            b = chaine2[1];
            a = (a*2)-1;

            fseek(fichier, 1, SEEK_CUR);

            for(i = 0; i < b; i++)//boucle qui parcourt la ligne
            {
                centrer(x,y);
                fgets(chaine, TAILLE_MAX, fichier); //Récupération d'une ligne dans le fichier pbm

                for(j = 0; j < a; j++) //boucle qui parcourt la ligne
                {
                    centrer(x,y);
                    if(chaine[j] == '0')
                        chaine[j] = ' ';//On remplace les 0 par  des espaces
                    else if(chaine[j] == '1')
                        chaine[j] = 'X';//On change les 1 par des X

                }
                x = x + 1;
                printf("%s", chaine);
            }
            fclose(fichier);//On ferme le fichier
            fichier = NULL;
        }
        x = x - 5;
        y = y + 7;
    }
}
/* ==================== TERMSAVER DYNAMIQUE ==================== */
