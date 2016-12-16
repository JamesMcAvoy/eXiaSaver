#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "inc/fonctions.h"
#include "inc/historical.h"
#define centrer(x,y) printf("\033[%d;%dH", (x), (y))
#define TAILLE_MAX 80


int main(int argc, char *argv[])
{
    //Variable pour le rafraichissement des images et le centrage de l'image
    int rafraichissement = 10;
    int ctrlc = 0;
    int i;
    int a = 20; int b = 15, c = 3, d = 25;
    system("clear");

    while(ctrlc != 1)
    {
        int x = 20;
        int y = 62;

        centrer(c,d);
        initialisationHeure();
        centrer(a,b);

        //Texte afficher pour indiquer comment l'heure ce rafraichis
        if(rafraichissement == 1)
        {
            centrer(a,b+10);
            printf("L'ecran est actualise toutes les secondes\n");
        }
        else
        {
            printf("L'ecran sera actualisé dans quelques secondes");
        }

        //Boucle pour rafraichir l'heure
        for(i = 0; i < rafraichissement; i++)
        {
            sleep(1);
            centrer(x,y);
            printf(".\n");
            y++;
        }

        y = y - rafraichissement;
        centrer(x,y);
        printf("                              ");
    }

    system("clear");

    Historical hist;

    *hist.file = "histo.txt";
    hist.type =2;

    writeHist(hist);
    return 0;
}
