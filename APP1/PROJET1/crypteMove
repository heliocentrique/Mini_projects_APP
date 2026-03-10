
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


int decale(char l, int cle) {

    if (l >= 'A' && l <= 'Z') {
        return (char) (((l - 'A' + cle) % 26 + 26) % 26 + 'A');
    }
    
    else if (l >= 'a' && l <= 'z') {
        return (char) (((l - 'a' + cle) % 26 + 26) % 26 + 'a');
    }
    else {
        return l;
    }
}


void itere(char table[], int cle, char final[]){
    
    for (int i=0 ; table[i] != '\0' ; i++){
    
	final[i]= decale(table[i],cle);
    
    }
    final[strlen(table)] = '\0';
}






int main() {

    char reponse[13];
    strncpy(reponse, ">>>recu >>> Hmjwj Fqnhj,Oj hwtnx vzj stzx xtrrjx xzw jhtzyj, stzx fqqtsx ijatnw hmfsljw stywj rjymtij ij hmnkkwjrjsy. O'fn zsj ujynyj nijj ijwwnjwj qf yjyj utzw hjqf. Az qf xnyzfynts, stzx sj utzatsx jywj ywtu uwzijsyx fafsy ij ufxxjw fz uqfs uwjaz. Oj yj qfnxxj zs uwthmfns rjxxflj ifsx q'jcjwhnhj 'hwduyjRtaj', wjxyj anlnqfsyj jy jkkfhj yjx ywfhjx. Fz kfny, qf xtqzynts utzw wjzxxnw uwtojyC jxy i'jsatdjw 'ajsn anin anhn' fz xjwajzw. Yz fzwfx fnsxn fhhjx f q'jcjwhnhj 'hwduyjRtaj'.Gnjs f ytn, Gtg UX : Xn yz fx qj yjrux, o'fn rnx ijx htijx xjhwjyx utzw hj vzj yz xfnx ifsx q'jcjwhnhj hmfqqjslj 'uqfsG' rfnx hj s'jxy ufx qf uwntwnyj utzw q'nsxyfsy. Jshfx ij itzyj, wjywtzaj-rtn uqzyty wfunijrjsy xzw hwduyjRtaj.", sizeof(reponse) - 1);
    reponse[12] = '\0';  // Correct null termination

    // Appel de la fonction decale et affichage du résultat
    char resultat = decale('Z', 3);
    printf("Résultat du décalage : %c\n", resultat);
    
    char final[200];
    itere(reponse, 21, final);
    
    printf("final : %s\n", final);

    return 0;
}

