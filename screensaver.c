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