#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Pour le rand
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include "inc/historical.h" //

int main(int argc, char **argv) {

	//Paramètre -stat
	if(argc == 2) {
		if(argv[0] = "-stat")
			system("./stat");
	}

	pid_t fils;

    srand(time(NULL));

    int nbgen = rand()%1+1; //entre 1-3
    int father;

    int system(const char *command);

    system("clear");

    switch(nbgen) {
	    case 1:
			fils = fork();
			father = getppid();
			if(fils == 0) {
				system(getenv("EXIASAVER_HOME") + "termsaver1");
			}
			else father = wait(NULL);
			break;

	    case 2:
			system(getenv("EXIASAVER_HOME") + "termsaver2");
			break;

		case 3:
		    system(getenv("EXIASAVER_HOME") + "termsaver3");
		    break;
	}

}