#include <stdio.h>
#include "listes.h"
#define TAILLE_MAX 100

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

void creer_pile(PileEntiers *p){
  p->n = 0;
  for (int i =0 ; i < TAILLE_MAX ; i++){
    p->tab[i].entier=0;
  }
}

/* Opérations d'accès */

/* Retourne vrai ssi p est vide */
int est_vide(PileEntiers *p){
  return p->n == 0;
}

/* Renvoie l'entier en haut de la pile */
/* p doit être non vide */
int sommet(PileEntiers *p){
  if (est_vide(p)){
    printf("la pile est vide");
  } 
  else {
    return p->tab[(p->n)-1].entier;
  }
  return 0;
}

/* Renvoie le nombre d'éléments dans la pile */
int taille(PileEntiers *p){
  return p->n;
}

/* Afficher les éléments de la pile */
void print(PileEntiers *p){
  for (int i = p->n - 1; i >= 0; i--){
    printf("%d\n", p->tab[i].entier);
  }
}

/* Opérations de modification */

/* Vider la pile p */
void vider(PileEntiers *p){
  p->n=0;
}

/* Empiler un entier x */
/* Précondition : taille(p) < TAILLE_MAX */
void empiler(PileEntiers *p, int x){
  if ((p->n) < TAILLE_MAX){
    p->tab[p->n].entier = x;
    p->n = (p->n) + 1 ;
  }
  else {
    printf("Taille max allouee");
  }
}

/* Supprimer et renvoyer l'entier en haut de la pile */
/* Précondition : p non vide */
int depiler(PileEntiers *p){

  if (p->n > 0){
    int x = sommet(p);
    p->n--;
    return x;
    }
    else
    {
      printf("La pile ne contient aucun element");

  }
  return 0;
}

/* Depile un block d'une pile */
sequence_t* depiler_bloc(PileEntiers *p) {
    if (p->n > 0) {
        p->n--;
        printf("Dépilage de la séquence %p à l'indice %d\n", p->tab[p->n].seq, p->n);
        return p->tab[p->n].seq;  
    } else {
        printf("Erreur : la pile est vide.\n");
        return NULL; 
    }
}

/* Empile un block dans une pile */
void empiler_bloc(PileEntiers *p, sequence_t *seq) {
    if (p->n < TAILLE_MAX) {
        printf("Empilage de la séquence %p à l'indice %d\n", seq, p->n);
        p->tab[p->n].seq = seq;  
        p->n++;
    } else {
        printf("Erreur : la pile est pleine.\n");
    }
}