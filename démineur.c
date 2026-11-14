#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Taille maximale du terrain 
enum { TAILLE_MAX = 100 };

// Question 2 : structures de donnees

// Une cellule du terrain
typedef struct {
  int bombe;    // si y'a bombe ou pas
  int masquee;  // si la cellule est masquée ou pas
} Cellule;

// Une partie : un terrain carre de n x n cellules

typedef struct {
  int n; // nombre de lignes (et de colonnes) du terrain
  Cellule terrain[TAILLE_MAX][TAILLE_MAX];
} Partie;

// Question 3 : initialisation du terrain

int initialiser(Partie *p, int n) {
  if (n < 1 || n > TAILLE_MAX)
    return 1;
  p->n = n;
  for (int l = 0; l < n; ++l)
    for (int c = 0; c < n; ++c) {
      p->terrain[l][c].masquee = 1;
      p->terrain[l][c].bombe = 0;
    }
  return 0;
}