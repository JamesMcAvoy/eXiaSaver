#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Pour le rand
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(void){
  pid_t fils;
  int status;
  srand(time(NULL));
  int MIN = 1;
  int MAX = 3;
  int nombreAleatoire;
  nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
  int father;

  system("clear");
  switch (nombreAleatoire)
  {
    case 1:

      fils = fork();
      father = getppid();
      if(fils == 0)
      {
        system("./termSaver1");
      }
      else
      {
          father = wait(NULL);
      }

      break;
    case 2:
      printf("termsaver2");

      break;
    case 3:
      printf("termsaver3");



      break;
}
}
