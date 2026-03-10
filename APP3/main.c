#include "arbres.h"
#include "arbresphylo.h"
#include "listes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DEBUG = 0;

int main(int argc, char *argv[])
{
    char *fichier = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage:  %s [-d] <fichier>\n", argv[0]);
        fprintf(stderr, "\n");
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "\t-d\tmode debug\n");
        exit(1);
    }
    int arg = 1;

    while (arg < argc) {
        if (!strncmp(argv[arg], "-d", 2)) {
            DEBUG = 1;
            arg++;
            continue;
        }
        if (argv[arg][0] == '-') {
            fprintf(stderr, "Option inconnue : '%s'\n", argv[arg]);
            exit(1);
        }
        if (fichier == NULL) {
            fichier = argv[arg];
            arg++;
            continue;
        } else {
            fprintf(stderr,
                    "Trop de fichiers sur la ligne de commande : '%s'\n",
                    argv[arg]);
            exit(1);
        }
    }

    debug("Ouverture de %s\n", fichier);
    FILE *f = fopen(fichier, "r");
    if (!f) {
        fprintf(stderr, "Erreur à l'ouverture du fichier `%s'\n", fichier);
        perror(fichier);
        exit(1);
    }

    arbre mon_arbre = lire_arbre(f);

    int nombre_especes; /* Ne pas initialiser ici, c'est analyse_arbre */
    int nombre_caract;  /* qui doit s'en charger */

    affiche_arbre(mon_arbre);

    analyse_arbre(mon_arbre, &nombre_especes, &nombre_caract);

    printf("Nombre d'especes de l'arbre: %d\n", nombre_especes);
    printf("Nombre de caractéristiques de l'arbre: %d\n", nombre_caract);


    return 0;
}



/* Acte-I-B */

void ecrire_noeud(arbre a, FILE *f) {
    if (a == NULL) {
        return;
    }

    
    if (a->gauche != NULL) {
        fprintf(f, "    %s -> %s [label = \"non\"];\n", a->valeur, a->gauche->valeur);
        ecrire_noeud(a->gauche, f);
    }

    
    if (a->droit != NULL) {
        fprintf(f, "    %s -> %s [label = \"oui\"];\n", a->valeur, a->droit->valeur);
        ecrire_noeud(a->droit, f);
    }
}


void arbre_en_dot(arbre a, FILE *f) {
    if (a == NULL || f == NULL) {
        return;
    }

    
    fprintf(f, "digraph arbre {\n");
    ecrire_noeud(a, f);
    fprintf(f, "}\n");
    fclose(f);
    system("dot -Tpng -o arbre.png arbre.dot");
}
