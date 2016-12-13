#include <stdio.h>
#include <stdlib.h>

void affichage() {
  char caractere;

  if (fichier != NULL) { // SI L'IMAGE EST BIEN RECUE
    fseek (fichier, 14, SEEK_SET); // SKIP LES PREMIERS ELEMENTS POUR ALLER A L'IMAGE 0/1
    do {
      caractere = fgetc(fichier); // AFFECTE LA LIGNE DANS CHAINE
      if (caractere == '0') {caractere = ' ';} // SI IL Y A UN 0 DANS LE FICHIER PBM -> LE REMPLACER PAR UN ESPACE
      //else if (caractere == ' ') {caractere = '\0';} // SUPPRIME LES ESPACES DU FICHIER PBM
      else if (caractere == '1') {caractere = 'X';} // SI IL Y A UN 1 DANS LE FICHIER PBM -> LE REMPLACER PAR UN X
      printf("%c", caractere); // AFFICHE LE CARACTERE (X ou ESPACE)
    } while (caractere != EOF); // LIT JUSQU'A LA FIN DU FICHIER
  }

  else {printf("Le fichier ne peut pas être ouvert\n");} // SI L'IMAGE N'EST PAS RECUE
}
