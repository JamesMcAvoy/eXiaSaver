#include <stdio.h>
#include <string.h>

#define LARGEUR_CONSOLE 80

void printf_center (const char* str) {
  unsigned int n;
  for (n =0; n < (LARGEUR_CONSOLE - strlen(str)) / 2; n++) {
    putchar(' ');
  }
  printf("%s", str);
}
