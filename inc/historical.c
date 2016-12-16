#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "historical.h"

void writeHist(Historical hist) {

  if(hist.type == 1)
  	system("date +\"%D %X;1\" >> histo.txt");
  else if(hist.type == 2)
  	system("date +\"%D %X;2\" >> histo.txt");

}
