#include <stdio.h>
#include "algorithm.h"
/*
 * Catégories d'algorithmes:
 *    - Search
 *    - Sort
 *    - Insert
 *    - Update
 *    - Delete
 */

/*
 * Charactéristics of an algorithm:
 *  - Unambiguous : L'algorithme ne doit pas être ambigue
 *  - Input : 0 ou plus d'entrées
 *  - Ouput : 1 ou plusieurs sorties
 *  - Finiteness : l'algorithme doit finir après un certain nombre de pas
 *  - Feasability : Il doit être calculable avec des ressources limités
 *  - Independent : La direction pas à pas d'un algo doit être
 *      indépendant d'un langage de programmation
 */

/*
 * Complexité algorithmique:
 * posont X un algorithme et n la taille des données entrées.
 * le temps et l'espace utilisé par X sont les 2 facteurs
 * principaux de l'efficacité de X.
 *
 * - Time factor: temps mesuré en comptant les opérations élémentaires,
 *      pour effectuer l'algorithme.
 *      - On considère que chaque opération élémentaire a une taille fixe.
 *      - T(n) ou T est le temps d'un algorithme et n le nombre de steps
 *      d'un algorithme. T(n) = c * n,
 *      ou c'est la durée d'une opération élémentaire.
 *      (notons que n et donc T(n) augmente généralement
 *      en fonction de la quantité de donnée entrée)
 * - Space factor: mesuré en comptant la quantité maximale d'espace mémoire
 *      utilisé par l'algorithme.
 *      space = taille fixe de l'algorithme + taille dynamique.
 *      - La taille fixe est la quantité de variable utilisé etc.
 *      - La taille dynamique est une quantité de mémoire assigné pendant
 *      le déroulement de l'algorithme
 *
 */

//Probleme : "Un algorithme qui ajoute 2 nombres et affiche le résultat
void add2(){
    //1: START
    //2: déclare 3 entiers: a,b,c
    int a, b, c;
    //3: définie la valeur de a et b
    a = 5; b = 5;
    //4: ajouter a valeur a et b
    //5: mettre la valeur de 4: dans c
    c = a + b;
    //6: afficher la valeur de c
    printf("%d\n", c);
    //7: STOP
}

void add2_simple(){
    //1: START
    //2: prendre les valeurs de a et b
    int a = 5, b = 5;
    //3: c <- a + b
    int c = a + b;
    //4: afficher la valeur de c
    printf("%d\n", c);
    //5: STOP
}

