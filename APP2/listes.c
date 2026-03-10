#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"
#include <string.h>

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */

bool silent_mode = false;


cellule_t* nouvelleCellule (void)
{
    cellule_t* c = (cellule_t *) malloc(sizeof(cellule_t));
    c -> command = '\0';
    c -> suivant = NULL;
    /* À compléter (utiliser malloc) */
    printf("\n>>>>>>>>>>> A Faire : liste.c/nouvelleCellule() <<<<<<<<<<<<<<<<\n");
    return c;
}


void detruireCellule (cellule_t* cel)
{
    free(cel);
    /* À compléter (utiliser free) */
    printf("\n>>>>>>>>>>> A Faire : liste.c/detruireCellule() <<<<<<<<<<<<<<<<\n");
}



void ajout_en_tete(sequence_t *seq, char n) {
    
     cellule_t *new = (cellule_t *)malloc(sizeof(cellule_t));
     new->command= n; 
     new->suivant= seq->tete;
     seq->tete= new;
    
    /* votre code ici */
    return;
}



void conversion (char *texte, sequence_t *seq)
{
    int leng =strlen(texte);

    for (int i= leng -1 ; i >= 0 ; i--){
        ajout_en_tete(seq, texte[i]);
    }
}






void afficher (sequence_t* seq)
{
    assert (seq);
    cellule_t *courant = seq->tete;
    char carac;
    while (courant != NULL){
        carac = courant -> command;
        printf("%c",carac);
        courant = courant->suivant;
    }
    
     /* Le pointeur doit être valide */
}

