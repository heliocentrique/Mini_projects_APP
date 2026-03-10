#include "listes.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* fichier à compléter au besoin */

void init_liste_vide(liste_t *L)
{

    /* a completer */
    L->tete = NULL;
}

/*
 * Supprime toutes les cellules d'une liste L, sans faire de free sur
 * L elle-même.
 */
void liberer_liste(liste_t *L)
{

    /* a completer */
    cellule_t *courant = L->tete;
    while (courant != NULL) {
        cellule_t *temp = courant;   // Stocke temporairement le pointeur courant
        courant = courant->suivant; // Passe à l'élément suivant
        free(temp->val);            // Libère la chaîne de caractères
        free(temp);                 // Libère la cellule
    }
    L->tete = NULL;
}


int ajouter_tete(liste_t *L, string c)
{   /* retourne 0 si OK, 1 sinon  */
    /* a completer */
    cellule_t *nouvelle_cellule = malloc(sizeof(cellule_t));
    if (nouvelle_cellule == NULL) {
        return 1; // Échec de l'allocation mémoire
    }

    // Allouer de la mémoire pour copier la valeur
    nouvelle_cellule->val = strdup(c);
    if (nouvelle_cellule->val == NULL) {
        free(nouvelle_cellule); // Libère la cellule si la copie échoue
        return 1; // Échec de l'ajout
    }

    // Insérer la cellule au début de la liste
    nouvelle_cellule->suivant = L->tete; // Le suivant de la nouvelle cellule pointe sur l'ancienne tête
    L->tete = nouvelle_cellule;         // La nouvelle cellule devient la tête de la liste

    return 0;
    
}