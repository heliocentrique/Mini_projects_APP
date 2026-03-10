#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



/* fonctions deja implementes dans BayOfPigs : */



/* supprime le dernier carac (suppder) de seq */
void suppder(char seq[]){
    seq[strlen(seq)-1]='\0';
}



/* ajoute le carac l au debut de seq */
void ajoutprem(char seq[], char l) {
    for (int i = (strlen(seq)); i >0; i--) {
        seq[i] = seq[i-1];
    }
    seq[0] = l;
    seq[(strlen(seq))+1]='\0';
}



/* decrypte (decryptee) init (initial) en le mettant dans final */
void decryptee(char init[], char final[]) {
    unsigned long mod;

    while (init[0] != '\0') {
        char dcar = init[strlen(init) - 1];
        suppder(init);                       
        mod = (unsigned char)dcar % 8;       

        for (unsigned long i = 0; i < mod && mod < strlen(final); i++) {
            ajoutprem(final, final[strlen(final) - 1]); 
            suppder(final);                           
        }

        ajoutprem(final, dcar); /* ajoute dcar au début de final */
    }
}



/* --------------------------------------------------------------------------------- */



/* fonctions deja implementes dans crypteMove : */



/* supprime (supp) le caractere a l'index i de seq */
void supp(char seq[], int i) {
    int longeur = strlen(seq);
    for (int k = i; k < longeur - 1; k++) {
        seq[k] = seq[k + 1];
    }
    seq[longeur - 1] = '\0';
}



/* ajoute (ajout) le caractere l a la fin de seq si |seq| < MAXREP */
void ajout(char seq[], char l) {
    int longeur = strlen(seq);
    if (longeur < MAXREP) { 
        seq[longeur] = l;
        seq[longeur + 1] = '\0';
    }
}



/* --------------------------------------------------------------------------------- */



/* crypte le message TXT et le met dans FINAL en suivant le protocol demande */
void crypteseq(char TXT[],char FINAL[]){
    char Liste[MAXREP]= "";
    FINAL[0]= '\0';
    char l;
    int index;
    int appart; /* appartient a Liste : 1 si oui et 0 sinon */

    for(unsigned long i=0; TXT[i] != '\0' ;i++){
        strcpy(&l,"");
        appart = 0;
        for(unsigned long j=0; Liste[j] != '\0' ;j++){
            if(Liste[j] == TXT[i]){
                appart=1;
                index=j;
            }
        }
        if (appart==0){
            ajout(Liste,TXT[i]);
            ajout(FINAL,TXT[i]);
        }else{
            if(index==0){
                l = Liste[strlen(Liste)-1];
            }else{
                l = Liste[index-1];
            }
            ajout(FINAL,l);
            supp(Liste,index);
            ajout(Liste,TXT[i]);
        }
    }
}


/* ---------------------------------------------------------------------------------- */



int main(){
    char stock[MAXREP];
    char newstock[MAXREP]; 
    
    show_messages(true);

    connexion("im2ag-appolab.u-ga.fr");
    envoyer("login 12307635 'RAFCA ZOUGHEIB' ");
    envoyer("load crypteSeq");
    envoyer_recevoir("start",stock);
    decryptee(stock,newstock);
    strcpy(stock,"");
    crypteseq(newstock,stock);
    strcpy(newstock,"");
    envoyer_recevoir(stock,newstock);

    
    return 0;
}