#include "arbresphylo.h"
#include "arbres.h"
#include "listes.h"
#include "file.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Acte-I-A */


void analyse_arbre(arbre racine, int *nb_esp, int *nb_carac)
{
       *nb_esp=0;
       *nb_carac=0;
       if (racine == NULL) {
              return;} 
       analyse_arbre_rec(racine, nb_esp, nb_carac);
            
}

/* Dans arbresphylo.h cette fonction est ecrite avant analyse-arbre pour eviter
 * les erreurs de segmentation */
void analyse_arbre_rec(arbre racine, int *nb_esp, int *nb_carac)
{
       if (racine == NULL) {
              return;} 

       if (racine->gauche == NULL && racine->droit == NULL) {
              (*nb_esp)++;
       }

       if (racine->gauche != NULL||racine->droit != NULL) {
              (*nb_carac)++;
              analyse_arbre_rec(racine->gauche, nb_esp, nb_carac);

              analyse_arbre_rec(racine->droit, nb_esp, nb_carac);
       }     
}





/* ACTE-II */
/* Recherche l'espece dans l'arbre. Modifie la liste passée en paramètre pour y
 * mettre les caractéristiques. Retourne 0 si l'espèce a été retrouvée, 1 sinon.
 */
int rechercher_espece(arbre racine, char *espece, liste_t *seq){

       int racine_g, racine_d;

       if (racine == NULL){
              return 1;
       }

       if ((racine->gauche== NULL) && (racine->droit== NULL)){
              if (!strcmp(racine->valeur,espece)){  /* pour comparer la valeur de la racine a l'espece attendue*/
                     return 0;
              } else {
              return 1;
              }
       }

       racine_g = rechercher_espece(racine->gauche,espece,seq);
       racine_d = rechercher_espece(racine->droit,espece,seq);

       if (racine_g == 0){
              return 0;
       }

       if (racine_d == 0){
              ajouter_tete(seq,racine->valeur);
              return 0;
       }

    /* à compléter */
    return 1;
}


/* Acte-III-A */


/* Doit renvoyer 0 si l'espece a bien ete ajoutee, 1 sinon, et ecrire un
 * message d'erreur.
 */
int ajouter_espece(arbre *a, char *espece, cellule_t *seq) {
    if (*a == NULL) { // Cas 1 : Arbre vide
        *a = nouveau_noeud();
        if (seq == NULL) {
            (*a)->valeur = strdup(espece);
        } else {
            arbre courant = *a;
            while (seq != NULL) {
                courant->valeur = strdup(seq->val);
                seq = seq->suivant;
                if (seq != NULL) {
                    courant->droit = nouveau_noeud();
                    courant = courant->droit;
                }
            }
            courant->droit = nouveau_noeud();
            courant->droit->valeur = strdup(espece);
        }
        return 0;
    }

    // Cas 2 : Nœud sans fils
    if ((*a)->gauche == NULL && (*a)->droit == NULL) {
        if (seq == NULL) {
            printf("Erreur : Impossible d'ajouter %s, conflit détecté.\n", espece);
            return 1;
        } else {
            arbre nouveau = nouveau_noeud();
            nouveau->valeur = strdup(seq->val);
            nouveau->gauche = *a;
            *a = nouveau;

            arbre courant = *a;
            seq = seq->suivant;
            while (seq != NULL) {
                courant->droit = nouveau_noeud();
                courant = courant->droit;
                courant->valeur = strdup(seq->val);
                seq = seq->suivant;
            }
            courant->droit = nouveau_noeud();
            courant->droit->valeur = strdup(espece);
            return 0;
        }
    }

    // Cas 3 : Arbre normal
    if (seq != NULL && !strcmp((*a)->valeur, seq->val)) {
        return ajouter_espece(&((*a)->droit), espece, seq->suivant);
    } else {
        return ajouter_espece(&((*a)->gauche), espece, seq);
    }
}



/* Acte-III-B */

int minim(int x, int y){
       if (x >= y){
              return y;
       }else{
              return x;
       }
}

int prof(arbre a, arbre fils_1){

       if (a == NULL){
              return -1;
       }

       if (!strcmp(a->valeur,fils_1->valeur)) {
              return 0;

       }else{
              int prof_d = prof(a->droit,fils_1);
              int prof_g = prof(a->gauche,fils_1);

              if(prof_d == -1 || prof_g == -1){  
                     if(prof_d == -1 && prof_g != -1)
                            return prof_g+1; 
                     else if(prof_g == -1 && prof_d != -1)
                            return prof_d+1; 
                     else
                            return -1; 
              
              }else{
                     return minim(prof(a -> droit,fils_1),prof(a -> gauche,fils_1))+1;
              }

       }
}


/* Doit afficher la liste des caractéristiques niveau par niveau, de gauche
 * à droite, dans le fichier fout.
 * Appeler la fonction avec fout=stdin pour afficher sur la sortie standard.
 */
void afficher_par_niveau(arbre racine, FILE* fout) {
       int niveau_act = 0;
       int niveau_pre = 0;
       arbre a = NULL;
       arbre a_pre = NULL;

   if(racine != NULL){
      file_N* file = malloc(sizeof(file_N));
      CRfile(file);
      enfiler(file,racine);  

      while(!est_vide(file)){ 
         a = defiler(file); 
         
         if(a_pre != NULL){
            niveau_act = prof(racine,a);
            niveau_pre = prof(racine,a_pre);

            if(niveau_act != niveau_pre) 
               fprintf(fout,"\n"); 
         }
      
         if(a->droit != NULL || a->gauche != NULL) 
            fprintf(fout,"%s ",a->valeur); 
         if(a->gauche != NULL) 
            enfiler(file,a->gauche);
         if(a->droit != NULL)
            enfiler(file,a->droit); 
         a_pre = a;
      }
   }
}

// Acte 4


int ajouter_carac(arbre *a, char *carac, cellule_t *seq)
{
       printf ("<<<<< À faire: fonction ajouter_carac fichier " __FILE__ " >>>>>\n");
       return 0;
}
