#include <stdio.h>
#include "algorithm/algorithm.h"

/*
 * - Une structure de donnée est composée d'une interface, et d'une implémentation.
 *
 * - Une datastructure est charactérisée par:
 *      - sa correctness,
 *      - sa complexité en mémoire,
 *      - sa complexité en temps
 *
 * - Une datastructure est utile pour:
 *      - chercher des données
 *      - faire des calculs rapides
 *      - faire des requêtes multiples
 *
 * - En algorithmique, il y a plusieurs cas d'execution d'un algorithme:
 *      - Worst case,
 *      - Average case,
 *      - Best case
 *
 * - Terminologie:
 *      - Data : Valeurs ou ensemble de valeurs,
 *      - Data item : Unité de valeur,
 *      - Group items : Data items qui peuvent être divisé dans
 *          des sous-items,
 *      - Elementary items: Data item qui ne peuvent être divisés,
 *      - Attribut and Entity : une Entity contient des Attributs,
 *          qui peuvent être des valeurs assignées,
 *      - Entity Set : les Entities qui ont des Attributs similaires
 *          forme un Entity Set,
 *      - Field: Elementary item qui représente un attribut d'une entité,
 *      - Record: Collection de Fields d'une Entity particulière,
 *      - File : Collection de Records
 */

int main(int argc, char* argv[]){
    add2();
    add2_simple();
    return 0;
}
