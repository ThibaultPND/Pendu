/*****************************************************************************/
/** Auteur : Thibault Chassagne                                             **/
/**                                                                         **/
/** Date : 12/10/2023                                                       **/
/**                                                                         **/
/** Nom : Pendu                                                             **/
/**                                                                         **/
//? Desc : Programme de pendu sur terminal.                                 **/
/**                                                                         **/
//? Commande de compilation :                                               **/
/** gcc *.c -o prog.exe                                                     **/
/**                                                                         **/
//! Les fichiers fonction.c, fonction.h et main.c doivent être dans un      **/
//! dossier seul.                                                           **/
/**                                                                         **/
/** Ce programme est destiner à une utilisation sur terminal windows (cmd)  **/
/*****************************************************************************/

#include"fonction.h"

int main(int argc, char *argv[]) {

    system("cls");
    system("chcp 65001");
    printf("Bienvenue dans ce programme de pendu !\n\
Les règles sont simples. Pour commencer le joueur un doit donner un mot à faire deviner (3<>10):\n");

    char motADeviner[12];
    do
    {
        printf("> ");
        scanf("%11s", motADeviner );
        fflush(stdin);
        strcpy(motADeviner, strupr(motADeviner));

    } while (strlen(motADeviner) < 3 || strlen(motADeviner) > 10 || motInvalide(motADeviner));
    
    const int taillemotADeviner = strlen(motADeviner);

    char lettreTrouve[taillemotADeviner];
    memset(lettreTrouve, '_', taillemotADeviner );
    lettreTrouve[taillemotADeviner] = '\0';
    
    char lettreSaisie[27];
    lettreSaisie[0] = '\0';

    char lettre;
    int chanceRestantes = 11;

    int erreur = -1;
    do {
        system("cls");
        printf("Lettres saisie :");
        afficherLettreTrouve(lettreSaisie);
        printf("Chances restantes : %d.\n\n",chanceRestantes);
        do { // Capturer une lettre
            afficherLettreTrouve(lettreTrouve);
            if (verifierErreurs(erreur)){
                printf("Fermer le programme\n");
                break;
            }
            scanf("%c", &lettre);
            fflush(stdin);

            // toUpper()
            if (lettre >= 'a' && lettre <= 'z') {
                lettre -= 0x20;
            }
            erreur = conditionSecondaire(lettre, lettreSaisie);
        } while (erreur != fermerJeu && erreur != -1);
        strncat(lettreSaisie, &lettre, 1);
        if (erreur == fermerJeu){
            break;
        }
        if (lettreDansMot(lettre, motADeviner)){
            printf("La lettre est dans le motADeviner !\n");
            remplacerTiret(lettre, motADeviner, lettreTrouve);
        }else{
            printf("La lettre n'est pas dans le mot à deviner !\n");
            chanceRestantes--;
        }
        erreur = conditionPrincipal(lettre, chanceRestantes, lettreTrouve);
    } while ( erreur != fermerJeu && erreur != gagne && erreur != plusDeChances);
    
    switch (erreur){
        case fermerJeu:
            printf("Vous avez choisi de fermer le jeu !\n");
            return EXIT_SUCCESS;
        case gagne:
            printf("Vous avez choisi de fermer le jeu !\n");
            return EXIT_SUCCESS;
        case plusDeChances:
            printf("Vous êtes mort ! Vous n'avec plus d'essais !\nLe mot était %s.", motADeviner);
            return EXIT_SUCCESS;
        default:
            break;
    }
    return 0;
}