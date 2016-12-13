# eXiaSaver
Projet C Linux écran de veille

#Arborescence
/home/ (root)
  |_.bashrc (contient var env)
  |_screensaver.c (screensaver, launcher)
  |_termsaver1.c (termsaver1, 1er écran veille)
  |_termsaver2.c (termsaver2, 2e  écran veille)
  |_termsaver3.c (termsaver3, 3e  écran veille)
  |_histo.txt (fichier historique)
  |_PBM/ (dossier contenant fichiers PBM)
    |_...
  |_inc/ (contient headers et fonctions utiles)
    |_functions.h
    |_functions.c
    |_historical.h
    |_historical.c

*TODO*
**supprimer Fonctions/**
**supprimer screensaver_dynamique**
**finir termsaver3.c**
**réécrire termsaver1/2 de façon à avoir les fonctions en header**
**finir historical.c**
**finir param -stat launcher**
