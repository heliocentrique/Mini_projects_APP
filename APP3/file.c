#include "arbres.h"
#include "file.h"
#include <stdlib.h>
#include <stdio.h>

int CRfile(file_N* file){
    file -> taille = 0;
    file->debut = 0;
    return 0;
}

int enfiler(file_N* file,arbre a){
    if(file == NULL){
        printf("ERREUR: Pointeur nul\n");
        return 2;
    }else if(file->taille > NB_N_MAX){
        printf("ERREUR: Taille trop grande\n");
        return 1;
    }else{
        file -> tab[file->taille] = a;
        (file -> taille)++;
        return 0;
    }
}

arbre defiler(file_N* file){
    (file -> debut)++;
    return file -> tab[file -> debut - 1];
}

int est_vide(file_N* file){
    if(file == NULL){
        printf("ERREUR: Pointeur nul\n");
        return 2;
    }else{
        return (file->taille) == (file->debut);
    }
}