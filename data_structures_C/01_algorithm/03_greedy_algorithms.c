/*
 * Un algorithme greedy (glouton) crée des décisions sous des sous-problemes,
 * puis les assemble pour donner la solution la plus
 * proche possible de l'optimum.
 *
 *
 * Ex: compter de l'argent:
 * Compter une valeur donnée avec un nombre possible de valeurs:
 *  - 1 centime,
 *  - 2 centimes,
 *  - 5 centimes,
 *  - 10 centimes,
 *
 * Pour compter 18 centimes:
 *  1: Selectionner une pièce de 10, il reste 8 à trouver
 *  2: Selectionner une pièce de 5, il reste 3 à trouver
 *  3: Selectionner une pièce de 2, il reste 1 à trouver
 *  4: Selectionner une pièce de 1, on a bien 18 au final.
 *
 *  Cette solution n'est pas optimum pour toutes les entrées.
 *  Si on a que des pièces de 1, 7 et 10. Pour compter 15,
 *  un algoritme greedy va faire (10 + 1 + 1 + 1 + 1 + 1).
 *  alors que la solution optimum est (7 + 7 + 1)
 *
 *
 *  Quelques algorithmes gloutons:
 *      - Travelling salesman problem,
 *      - Prim's minimal spanning tree algorithm,
 *      - Kruskal's minimal spanning tree algorithm,
 *      - Dijkstra's minimal spanning tree algorithm,
 *      - Graph - Map Coloring,
 *      - Graph - Vertex Cover,
 *      - Knapsack Problem,
 *      - Job Scheduling Problem.
 */


