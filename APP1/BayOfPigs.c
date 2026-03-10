
#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



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



int main() {
    char stock[MAXREP];
    char newstock[MAXREP]; 


    show_messages(true);

    
    connexion("im2ag-appolab.u-ga.fr");
    envoyer("login 12307635 'RAFCA ZOUGHEIB' ");
    envoyer("load BayOfPigs");
    envoyer_recevoir("start", stock);
    decryptee(stock,newstock);
    printf("%s",newstock);
    envoyer_recevoir("Par otuam eriet", stock);
    decryptee(stock,newstock);
    printf("%s",newstock);
    return 0;
}

