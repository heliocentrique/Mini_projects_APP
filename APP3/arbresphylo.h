#ifndef ARBRESPHYLO_H
#define ARBRESPHYLO_H

#include "listes.h"
#include "arbres.h"




/*Utulisee dans analyse_arbre*/
void analyse_arbre_rec(arbre racine, int *nb_esp, int *nb_carac);

/* Analyse un arbre: doit mettre à jour le nombre d'espèces et de 
 * caractéristiques.
 */
void analyse_arbre(arbre racine, int* nb_esp, int* nb_carac);



/* Recherche une espèce dans l'arbre et remplit seq avec la séquence de ses 
 * caractéristiques.
 *
 * Doit retourner 0 si l'espèce a été retrouvée, 1 sinon.
 */
int rechercher_espece(arbre racine, char *espece, liste_t* seq);


int ajouter_espece(arbre* racine, char *espece, cellule_t* seq);

/* Acte-III-B */

/* Renvoie le minimum (minim) des entiers x et y */
int minim(int x, int y);

/* Renvoie la profondeur d'un noeud */
int prof(arbre a, arbre fils_1);

void afficher_par_niveau(arbre racine, FILE* fout);

// on considère qu'il n'est pas possible
// d'insérer une caractéristique à un arbre vide, ni d'insérer une caractéristique
// qui n'est possédée par aucune espèce déjà présente dans l'arbre (pour ce
// cas-là, ajout_espece fait l'affaire). Ceci permet d'éviter d'avoir à ajouter
// des noeuds caractéristique sans enfant qui seraient confondues avec des
// espèces/feuilles.
int ajouter_carac(arbre* a, char* carac, cellule_t* seq);


#endif
