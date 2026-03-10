#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#ifdef NCURSES
#include <ncurses.h>
#endif
#include "listes.h"
#include "curiosity.h"
#include "type_pile.h"


/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 * condition de boucle, contenu du switch
 */


void stop (void)
{
    char enter = '\0';
    printf ("Appuyer sur entrée pour continuer...\n");
    while (enter != '\r' && enter != '\n') { enter = getchar(); }
}


/* fonctions pour calculer (Acte II) */


void add(PileEntiers *p)
{
    if (p->n >= 2)
    {
        PileElement x = depiler(p);
        PileElement y = depiler(p);
        empiler(p, (y.entier + x.entier));
    }
    else
    {
        printf("Pas assez de valeurs");
    }
}


void moin(PileEntiers *p)
{
    if (p->n >= 2)
    {
        PileElement x = depiler(p);
        PileElement y = depiler(p);
        empiler(p, (y.entier - x.entier));
    }
    else
    {
        printf("Pas assez de valeurs");
    }
}


void fois(PileEntiers *p)
{
    if (p->n >= 2)
    {
        PileElement x = depiler(p);
        PileElement y = depiler(p);
        empiler(p, (y.entier * x.entier));
    }
    else
    {
        printf("Pas assez de valeurs");
    }
}


/* Fonction qu'on appelle pour executer les commandes du block (Acte IV) */

void executer_bloc(sequence_t *bloc) {
    cellule_t *current = bloc->tete;

    while (current != NULL) {
        char command = current->command;

        switch (command) {
            case 'A':
                avance();
                break;
            case 'G':
                gauche();
                break;
            case 'D':
                droite();
                break;
            default:
                printf("Commande inconnue : '%c'\n", command);
                break;
        }

        current = current->suivant;
    }
}


/* Fonction qu'on appelle pour lire le contenue du block (Acte IV) */

sequence_t* lire_bloc(sequence_t *seq) {
    sequence_t *bloc = malloc(sizeof(sequence_t));
    bloc->tete = NULL;
    cellule_t *last = NULL;

    printf("Début de la lecture du bloc : ");
    while (seq->tete != NULL && seq->tete->command != '}') {
        cellule_t *new_cell = malloc(sizeof(cellule_t));
        new_cell->command = seq->tete->command;
        new_cell->suivant = NULL;

        if (bloc->tete == NULL) {
            bloc->tete = new_cell;  
        } else {
            last->suivant = new_cell;  
        }
        last = new_cell;

        printf("%c ", new_cell->command); 

        cellule_t *temp = seq->tete;
        seq->tete = seq->tete->suivant;
        free(temp);
    }

    printf("\n");

    if (seq->tete != NULL && seq->tete->command == '}') {
        cellule_t *temp = seq->tete;
        seq->tete = seq->tete->suivant;
        free(temp);
    }

    return bloc;
}


/* Contenue du cas { du swittch ecris a part pour rendre le switch plus facile a lire */

void traiter_case_accolade(sequence_t* seq, PileEntiers *p) {

    sequence_t* bloc = lire_bloc(seq);
    if (bloc == NULL) {
        fprintf(stderr, "Erreur : Impossible de lire le bloc\n");
        return;
    }
    empiler_bloc(p, bloc);

    cellule_t* temp_seq = seq->tete;
    seq->tete = seq->tete->suivant;
    free(temp_seq); 
 
    if (seq->tete == NULL) {
        fprintf(stderr, "Erreur : seq->tete est devenu NULL après le bloc\n");
        return;
    }
}





/*-----------------------------------------------INTERPRETE---------------------------------------------------------------------*/



int interprete(sequence_t* seq, bool debug) {
    // Version temporaire a remplacer par une lecture des commandes dans la
    // liste chainee et leur interpretation.

    char commande;

    debug = true; /* À enlever par la suite et utiliser "-d" sur la ligne de commandes */

    printf("Programme:");
    afficher(seq);
    printf("\n");
    if (debug) stop();

    printf("\n>>>>>>>>>>> A Faire : interprete.c/interprete() <<<<<<<<<<<<<<<<\n");
    
    if (seq == NULL || seq->tete == NULL) {
        printf("Erreur : séquence vide ou invalide.\n");
        return CIBLERATEE;
    }

    commande = seq->tete->command; // À modifier: première commande de la séquence
    int ret; // Utilisée pour les valeurs de retour
    PileElement val;
    PileEntiers p;
    creer_pile(&p);

    while (seq->tete != NULL) { // À modifier: condition de boucle

        switch (commande) {
            /* Ici on avance tout le temps, à compléter pour gérer d'autres commandes */
            case 'A':
                ret = avance();
                if (ret == VICTOIRE) return VICTOIRE; /* on a atteint la cible */
                if (ret == RATE) return RATE; /* tombé dans l'eau ou sur un rocher */
                break; /* à ne jamais oublier !!! */

            case 'G':
                gauche();
                break; /* à ne jamais oublier !!! */

            case 'D':
                droite();
                break; /* à ne jamais oublier !!! */

            case '0':
                empiler(&p, 0);
                break;

            case '1':
                empiler(&p, 1);
                break;

            case '2':
                empiler(&p, 2);
                break;

            case '3':
                empiler(&p, 3);
                break;

            case '4':
                empiler(&p, 4);
                break;

            case '5':
                empiler(&p, 5);
                break;

            case '6':
                empiler(&p, 6);
                break;

            case '7':
                empiler(&p, 7);
                break;

            case '8':
                empiler(&p, 8);
                break;

            case '9':
                empiler(&p, 9);
                break;

            case '+':
                add(&p);
                break;

            case '-':
                moin(&p);
                break;

            case '*':
                fois(&p);
                break;

            case 'P':
                val = depiler(&p);
                pose(val.entier);
                break;

            case 'M':
                val = depiler(&p);
                empiler(&p, mesure(val.entier));
                break;

            case '{': 
                traiter_case_accolade(seq, &p);
                break;

            case '?': {
                // Gestion du cas 'if'
                sequence_t* V = depiler_bloc(&p);
                sequence_t* F = depiler_bloc(&p);
                int n = depiler(&p).entier;

                if (n != 0) {
                    executer_bloc(V);
                } else {
                    executer_bloc(F);
                }
                break;
            }

            default:
                printf("Caractère inconnu: '%c'\n", commande);
                break;
        }

        // Vérification de seq->tete avant d'y accéder
        if (seq->tete != NULL) { 
            cellule_t *temp = seq->tete; 
            seq->tete = seq->tete->suivant; 
            free(temp);
        }

        /* Affichage pour faciliter le debug */
        afficherCarte();
        printf("Programme:");
        afficher(seq);
        print(&p);
        printf("\n");

        // Vérification de seq->tete avant d'y accéder
        if (seq->tete != NULL) {
            commande = seq->tete->command;
        } else {
            printf("Erreur : seq->tete est NULL à la fin de la boucle.\n");
            return CIBLERATEE;
        }

        if (debug) stop();
    }

    /* Si on sort de la boucle sans arriver sur la cible,
     * c'est raté :-( */
    return CIBLERATEE;
}