#include <stdio.h>
#include <time.h>




int main ()
{

  int system(const char *command);
  FILE* fichier = NULL;
  fichier = fopen("historique.txt", "a+");
  if (fichier != NULL)
  {
    system("date +\"%F %T \" > historique.txt");
      //fprint(fichier, "%d / %d / %d  %d : %d : %d ; %d : ?",jour , mois, année, heure, minute, seconde,  );
    fclose(fichier);
  }
  return 0;
}
