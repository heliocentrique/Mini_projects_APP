#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main() {

    char reponse[MAXREP];
    char renv[MAXREP];
    // Affiche les échanges avec le serveur (false pour désactiver)
    show_messages(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr");

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    

    envoyer_recevoir("login 12307635 'RAFCA ZOUGHEIB'", reponse);
    envoyer_recevoir("load tutorielFORT", reponse);
    envoyer_recevoir("depart", reponse);
    envoyer_recevoir("OK", reponse);
    envoyer_recevoir("OUI", reponse);
    envoyer_recevoir("CHATEAU FORT", reponse);
    envoyer_recevoir("KIKI LIKIKI LIKIKIKI LILILI KIKIKI", reponse);
    envoyer_recevoir("MAIS ARRETEZ DE CRIER !", reponse);
    for (int i=0 ; reponse[i] != '\0' ; i++ ) { 
    	renv[i]= toupper(reponse[i]);
    }
    renv[strlen(reponse)] = '\0';
    
    envoyer_recevoir(renv, reponse);
    
        for (int i=0 ; reponse[i] != '\0' ; i++ ) { 
    	renv[i]= toupper(reponse[i]);
    }
    renv[strlen(reponse)] = '\0';
    
    envoyer_recevoir(renv, reponse);
    
        for (int i=0 ; reponse[i] != '\0' ; i++ ) { 
    	renv[i]= toupper(reponse[i]);
    }
    renv[strlen(reponse)] = '\0';
    
    envoyer_recevoir(renv, reponse);
    

    printf("Réponse du serveur11: %s", reponse);

    printf ("Fin d'envoi des messages.\n");
    printf ("Pour envoyer d'autres lignes, ajouter des appels à la fonction `envoyer`\n");
    deconnexion();
    printf ("Fin de la connection au serveur\n");
    return 0;
}
