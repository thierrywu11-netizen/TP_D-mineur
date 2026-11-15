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

// Question 4 : affichage du terrain

void afficher(const Partie *p, int montrerBombes) {
  printf("   ");
  for (int c = 0; c < p->n; ++c)
    printf("%-*d", c >= 10 ? 3 : 2, c);
  printf("\n");
  for (int l = 0; l < p->n; ++l) {
    printf("%2d ", l);
    for (int c = 0; c < p->n; ++c) {
      char car;
      if (montrerBombes && p->terrain[l][c].bombe)
        car = '*';
      else if (p->terrain[l][c].masquee)
        car = '.';
      else
        car = ' ';
      printf("%-*c", c >= 10 ? 3 : 2, car);
    }
    printf("\n");
  }
}



int main() {
  Partie p;
  if (initialiser(&p, 5) != 0) {
    printf("Erreur lors de l'initialisation.\n");
    return 1;
  }
  afficher(&p, 0);

  p.terrain[1][1].masquee = 0; // une cellule démasquée
  p.terrain[3][2].bombe = 1;   // une bombe posée à la main
  afficher(&p, 0);             // la bombe reste invisible
  afficher(&p, 1);             // la bombe apparaît en '*'
  return 0;
}