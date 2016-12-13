#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include"fonction.h"
#define largeur_console 80

/* Fonction */
int compteur()
{   while(1)
    {
        system("cls");
        int valeur = 0;
        recuparationHeure();
        printf_center("L'heure va s'actualiser dans quelques secondes :");
        while(valeur < 10)
        {
            printf(".", valeur);
            valeur ++;
            my_delay(1);
        }
    }



}


int recuparationHeure()
{
    /*int heure;
    int minute;*/

    // On lit l'heure courante
    time_t now = time(NULL);

    //On la convertit en heure local
    struct tm tm_now = *localtime(&now);

    //On créer une chaine HH:MM
    char s_heure[sizeof "HH"];
    char s_minute[sizeof "MM"];

    //strftime(s_now, sizeof s_now, "%H:%M", &tm_now);

    strftime(s_heure, sizeof s_heure, "%H", &tm_now);
    strftime(s_minute, sizeof s_minute, "%M", &tm_now);

    printf("%s :", s_heure);
    printf(" %s\n", s_minute);


    //On affiche le résultat
    //printf("%s\n", s_now);

}


void my_delay(int i) //fonction pour faire une pause de x seconde
{
    clock_t start,end;
    start=clock();
    while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

//fonction pour centre les images
void printf_center(const char* str)
{
    unsigned int n;
    for(n = 0; n < (largeur_console-strlen(str)) / 2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
}


int main(int argc, char *argv[])
{
    compteur();


}





