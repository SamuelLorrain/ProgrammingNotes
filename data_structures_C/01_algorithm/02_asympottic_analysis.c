#include <stdio.h>
#include "algorithm/algorithm.h"

/*
 * Asomptotic analysis d'un algorithme :
 *  - Définir les bord de sa performance.
 *  - L'analyse asymptotique ne s'effectue que sur un algo avec au moins
 *      une entrée (sinon on considère que sa complexité est constante)
 *
 * Notation:
 *  - O(n) "Big O notation" est une notation qui exprime
 *  le bord supérieur du temps d'execution d'un algorithme
 *      => worst case time complexity (le temps maximal qu'un
 *      algorithme peut mettre pour s'executer)
 *
 *      Ex:
 *      O(f(n)) = { g(n) : il existe c > 0 et n_0 tel que f(n) <= c*g(n) pour tout
 *      n > n_0 }
 *
 *  - Ω(n), notation qui exprime le bord inférieur du temps
 *  d'execution d'un algorithme.
 *  Ex:
 *  Ω(f(n) { g(n) : il existe c > 0 et n_0 tel que g(n) <= c*f(n) pour tout
 *  n > n_0 }
 *
 *  - θ(n), notation qui exprime à la fois le lower et upper bound d'un
 *  algorithme.
 *  θ(f(n)) = { g(n) ssi g(n) = O(f(n)) et g(n) = Ω(f(n)) pour tout n > n_0 }
 *
 *
 * Commom asympotic notations:
 *  - constant = O(1)
 *  - logarithmique = O(log n)
 *  - linear = O(n)
 *  - n log n = O(n log n)
 *  - quadratic = O(n^2)
 *  - cubic = O(n^3)
 *  - polynomial = n^(O(1))
 *  - exponential = 2^(O(n))
 */
