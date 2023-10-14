#if !defined(__PENDU_H__)
#define __PENDU_H__

#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_LENGHT 10
#define MIN_LENGHT 3


/**
 * Remplace les tirets de lettreTrouve en fonction de la lettre entrée et
 * du mot qu'il faut deviner.
 *
 * \param lettre Lettre qui va être traité.
 * 
 * \param motADeviner Chaîne de caractère qui correspond au mot à deviner
 *                    par le joueur.
 * 
 * \param lettreTrouve Chaîne de caractère représentant l'êtat actuel 
 *                     des lettres que le joueurs à trouvé.
 * 
 * \sa lettreDansMot
 */
void remplacerTiret(char lettre, char *motADeviner, char *lettreTrouve);


/**
 * Verifie si la lettre apparait dans le mot.
 *
 * \param lettre Lettre qui va être traité.
 * 
 * \param motADeviner Chaîne de caractère qui correspond au mot à deviner
 *                    par le joueur.
 * 
 * \return Retourne true si la lettre est dans le mot, sinon false.
 * 
 * \sa remplacerTiret
 */
bool lettreDansMot(char lettre, char *mot);


/**
 * Verifie si le mot est valide pour le pendu.
 * 
 * Un mot est valide quand tout ses caractères sont compris entre 'A' et 'Z'.
 * 
 * \param motADeviner Chaîne de caractère qui correspond au mot à deviner
 *                    par le joueur.
 * 
 * \return Retourne true si le mot valide, sinon false.
 */
bool motInvalide(char *motADeviner);


/**
 * Verifie si la lettre à déja été tapé.
 * 
 * Une lettre à déja été tapé quand elle se situe dans lettreSaisie.
 * 
 * \param lettre Lettre qui va être traité.
 * 
 * \param lettreSaisie Liste des lettres qui ont déja été tapé dans
 *                     le jeu.
 * 
 * \return Retourne true si la lettre est dans la liste, sinon false.
 */
bool lettreDejaPropose(char lettre, char *lettreSaisie);


/**
 * Enumération de tout les valeurs de retour possible des conditions.
 * 
 * L'erreur vaut -1 quand elle est nulle.
 * 
 * \sa conditionPrincipal
 * \sa conditionSecondaire
 * \sa VerifieErreurs
 */
enum{
    fermerJeu = 0,
    lettreInvalide = 1,
    dejaPropose = 2,
    plusDeChances = 3,
    gagne = 4
};


/**
 * Verifie les conditions pour la boucle principal du programme
 * 
 * \return Retourne un entier qui correspond à une erreur selon l'énumération.
 */
int conditionPrincipal(char lettre, int chances, char *lettreTrouve);


/**
 * Verifie les conditions pour la boucle secondaire du programme
 * 
 * \return Retourne un entier qui correspond à une erreur selon l'énumération.
 */
int conditionSecondaire(char lettre, char *lettreSaisie);



/**
 * Verifie les erreurs en fonction de l'énuméraiton.
 * 
 * Cette fonction va à partie de l'erreur d'entrée taper un texte différent.
 * Cette fonction est uniquement déstiné à l'entrée d'un caractère.
 * 
 * \return Retourne 1 quand il faut fermer le programme 0 dans tout les autres cas.
 */
int verifierErreurs(int erreur);

/**
 * Affiche la chaîne de lettreTrouve sous la forme :
 * 
 * _ _ _ _ _ _
 *
 * \param lettreTrouve Chaîne de caractère représentant l'êtat actuel 
 *                     des lettres que le joueurs à trouvé. 
 */
void afficherLettreTrouve(char *lettreTrouve);

#endif // __PENDU_H__
