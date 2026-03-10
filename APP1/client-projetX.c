
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>



/*decale une lettre*/ 
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



/*decale le message entier lettre par lettre*/
void itere(char table[], int cle, char final[]){
    
    for (int i=0 ; table[i] != '\0' ; i++){
    
	final[i]= decale(table[i],cle);
    
    }
    final[strlen(table)] = '\0';
}



int main() {

    char reponse[1000];
    strcpy(reponse, ">>>recu >>> Gtg, utzw ijhwduyjw nq kfzy ufwynw ij qf kns iz rjxxflj jy jxxfdjw ij wjkfnwj \"f q'jsajwx\" qjx inkkjwjsyjx jyfujx. Xn yz wjuwjsix q'jcjruqj ij \"Ujyny rjxxflj htzwy.\" ts ujzy ufwynw ij qf kns jy wjywtzajw qjx inkkjwjsyx jyfyx ij YCY jy JSH ozxvz'fz ijgzy. Ufw jcjruqj xn qj *ijwsnjw* hfwfhyjwj ij JSH jyfny 'f', hjqf atziwfny inwj vz'f q'jyfuj uwjhjijsyj ts f qz zs 'f' jy ijuqfhj zs hfwfhyjwj f qf kns ij YCY. Js kfnxfsy qjx tujwfyntsx nsajwxjx ts wjywtzaj qj rjxxflj nsnynfq.");
    
    // Appel de la fonction decale et affichage du résultat
    char resultat = decale('Z', 3);
    printf("Résultat du décalage : %c\n", resultat);
    
    char final[200];
    itere(reponse, 21, final);
    
    printf("final : %s\n", final);

    return 0;
}

