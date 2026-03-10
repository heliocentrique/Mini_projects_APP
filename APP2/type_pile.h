
#define TAILLE_MAX 100
#include "listes.h"

/* Def de l'union pour accepter différents types */
typedef union {
    int entier;       
    sequence_t *seq;  
    char command;     
} PileElement;


typedef struct {
  int n;
  PileElement tab[TAILLE_MAX];
} PileEntiers;

/* Constructeurs */

/* Créer une pile vide */
void creer_pile(PileEntiers *p);

/* Opérations d'accès */

/* Retourne vrai ssi p est vide */
int est_vide(PileEntiers *p);

/* Renvoie l'entier en haut de la pile */
/* p doit être non vide */
int sommet(PileEntiers *p);

/* Renvoie le nombre d'éléments dans la pile */
int taille(PileEntiers *p);

/* Afficher les éléments de la pile */
void print(PileEntiers *p);

/* Opérations de modification */

/* Vider la pile p */
void vider(PileEntiers *p);

/* Empiler un entier x */
/* Précondition : taille(p) < TAILLE_MAX */
void empiler(PileEntiers *p, int x);

/* Empiler un bloc de commandes (séquence) */
void empiler_bloc(PileEntiers *p, sequence_t *seq);

/* Supprimer et renvoyer l'entier en haut de la pile */
/* Précondition : p non vide */
PileElement depiler(PileEntiers *p);

/* Dépiler un bloc de commandes (séquence) */
sequence_t* depiler_bloc(PileEntiers *p);

