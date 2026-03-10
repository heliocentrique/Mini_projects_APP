
#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



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



/* crypte (cryptee) TXT en suivant le protocol decrit sur appolab */
void cryptee(char TXT[], char* ENC) {
    unsigned long mod;
    char x[MAXREP];
    char l;  

    while (strlen(TXT) != 0) {
        l = TXT[0];         
        strcpy(x, "");      
        ajout(ENC, l);      
        
        mod = l % 8;        /* calcule du mod de l */
        supp(TXT, 0);       

        
        if (mod != 0 && strlen(TXT) >= mod) {
            for (unsigned long i = 0; i < mod; i++) {
                ajout(x, TXT[0]); 
                supp(TXT, 0);     
            }
            strcat(TXT, x);      /* concatene x à la fin de TXT */
        }
    }
}



/* --------------------------------------------------------------------------------- */



int main() {
    char stock[MAXREP];
    char newstock[MAXREP]; 

    show_messages(true);

    
    connexion("im2ag-appolab.u-ga.fr");
    envoyer("login 12307635 'RAFCA ZOUGHEIB' ");
    envoyer("load crypteMove");
    envoyer_recevoir("aide", stock);
    printf("%s",stock);
    cryptee(stock,newstock);
    envoyer("start");
    envoyer(newstock);
    // deconnexion();
    return 0;
}

