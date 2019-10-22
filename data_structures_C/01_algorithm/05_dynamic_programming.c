/*
 * Similaire au divide and conquer sauf que les problèmes
 * ne sont pas résolu indépendamment.
 * Les solutions à ces sous problèmes sont utilisé pour résoudre d'autres sous-problèmes
 *
 * Cette méthode est utilisé quand un problème peut-êtredivisé en sous problèmes
 * qu'on peut ensuite réutiliser. Utilisé beaucoup en optimisation.
 * - Le problème peut être divisé en sous problèmes,
 * - Une solution optimal peut être achevée en utilisant la solution optimal des
 *   sous problèmes
 * - utilisation de la memoization
 *
 *
 * Ex:
 *  - fibonnacci number serie,
 *  - knapsack problem,
 *  - tower of hanoi,
 *  - all par shortest path by Floyd-Warshall,
 *  - Shortest path by Dijkstra,
 *  - Project scheduling.
 *
 */
