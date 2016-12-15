# eXiaSaver
Projet C Linux écran de veille

###curses.h
apt-get install libncurses-dev<br />
compiler avec -lncurses

## Arborescence
* /home/ (root)
  * .bashrc (contient var env)
  * screensaver.c (screensaver, launcher)
  * termsaver1.c (termsaver1, 1er écran veille)
  * termsaver2.c (termsaver2, 2e  écran veille)
  * termsaver3.c (termsaver3, 3e  écran veille)
  * histo.txt (fichier historique)
  * PBM/ (dossier contenant fichiers PBM)
    * ...
  * inc/ (contient headers et fonctions utiles)
    * functions.h
    * functions.c
    * historical.h
    * historical.c

## TODO
* finir termsaver3.c
* réécrire termsaver1/2 de façon à avoir les fonctions en header
* finir historical.c
* finir param -stat launcher
* ajouter writeHist sur termsaver1/2/3
