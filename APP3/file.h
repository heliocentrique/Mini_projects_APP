#ifndef FILE_H
#define FILE_H

#include "arbres.h"

#define NB_N_MAX 999999

typedef struct file_N{
    arbre tab[NB_N_MAX]; 
    int debut;
    int taille;
} file_N;

/* crée une file vide */
int CRfile(file_N* file);

/* enfile un noeud dans une file passée en paramètre */
int enfiler(file_N* file,arbre a);

/* défile et renvoie un noeud de la file passée en paramètre */
arbre defiler(file_N* file);

/* renvoie 1 si la file est vide, 0 sinon et retourne 2 si la file est un pointeur nul */
int est_vide(file_N* file);

#endif 