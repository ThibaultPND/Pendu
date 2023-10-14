#include"fonction.h"

void remplacerTiret(char lettre, char *motADeviner, char *lettreTrouve){
    bool lettreChange = false;
    for (int i = 0; i < strlen(motADeviner); i++) {
        if (motADeviner[i] == lettre){
            lettreTrouve[i] = lettre;
        }
    }
    return 0;
    
}

bool lettreDansMot(char lettre, char *motADeviner){
    for (int i = 0; i < strlen(motADeviner) ; i++) {
        if (motADeviner[i] == lettre){
            return true;
        }
    }
    return false;
    
}

bool motInvalide(char *motADeviner){
    for (int i = 0; i < strlen(motADeviner); i++){
        if (motADeviner[i] < 'A' || motADeviner[i] > 'Z'){
            return true;
        }
    }
    return false;
    
}

bool lettreDejaPropose(char lettre, char *lettreSaisie){
    for (int i = 0; i < strlen(lettreSaisie); i++){
        if (lettre == lettreSaisie[i]){
            return true;
        }
    }
    return false;
}

int conditionSecondaire(char lettre, char *lettreSaisie){
    if (lettre == '0')
        return fermerJeu;
    if (lettre < 'A' || lettre > 'Z')
        return lettreInvalide;
    if (lettreDejaPropose(lettre, lettreSaisie))
        return dejaPropose;
    
    return -1;
}

int conditionPrincipal(char lettre, int chances, char *lettreTrouve){
    if (lettre == '0')
        return fermerJeu;
    if (chances <= 0)
        return plusDeChances;
    if (!lettreDansMot('_', lettreTrouve))
        return gagne;
    return -1;
}

int verifierErreurs(int erreur){
    if (erreur == fermerJeu){
        return 1;
    }else if (erreur == lettreInvalide){
        printf("Cette lettre n'est pas valide.\nVeuillez entrer une lettre valide !\n> ");
    }else if (erreur == dejaPropose){
        printf("Vous avez déja proposé la lettre !\nVous devez entrer une lettre différente.\n> ");
    }else{
        printf("Chosir une lettre :\n> ");
    }
    return 0;
}

void afficherLettreTrouve(char *lettreTrouve){
    for (int i = 0; i < strlen(lettreTrouve); i++){
        printf("%c ", lettreTrouve[i]);
    }
    printf("\n");
}

