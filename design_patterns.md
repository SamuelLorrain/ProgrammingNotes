# Design Patterns

## Vocabulaire

- Composition : le fait de créer un objet qui contient
                des références vers d'autres objets,
                pour ajouter des fonctionnalités
- Délegation : faire en sorte qu'une classe délègue certaines
               fonctionnalités à un objet en référence.
               En gros, c'est une utilisation de la composition,
               pour éviter d'avoir à faire de l'héritage.
- Interface : classe abstraite pure, si on créé une sous-classe
              héritée d'une interface, on ne fait enfait pas vraiment
              d'héritage, mais on dit qu'on "implémente une interface"
- Aggregation: Un objet est un aggregation si il est composé
               de plusieurs objets. Les objets aggrégés sont détruits
               à la destruction de l'aggrégation (couplage fort)
- Association (Acquaintance) : Au contraire de l'aggregation, un association
               d'objet implique que les objets existent indépendamment
               et ne sont pas détruit quand l'association est
               détruite.

## Principe
1. "Programmer aux interfaces et non aux implémentations" :
    Concrètement, il ne faut pas ajouter de méthodes publiques
    à un objet qui implémente une interface. De plus, si on utilise
    cet objet dans le code, il faut y faire référence avec
    le type de l'interface plutôt qu'avec la classe de l'objet.
    Ex:
    SuperClasse myObj = mySousClasse;

    Ici, myObj est de type SuperClasse, comme l'assigne à un objet
    de type SousClasse, myObj fait du polymorphisme. on aurait pu
    aussi passer un objet de type mySousClasse2 à myObj sans que
    le reste du programme soit affecté.

    Tout ceci permet de rendre le programme plus générique, notamment
    car on peut changer le type de myObj à run-time.

2. "Favoriser la composition d'objet plutôt que l'héritage".
    La Composition et Délégation sont des mécanismes plus flexibles
    que l'héritage. De plus, favoriser la composition permet de
    programmer aux interfaces plus facilement (car il n'y a pas de
    nouvelles méthode avec de la composition, juste l'utilisation
    d'autres objets).
    Bref, les deux principes fonctionnent ensemble.

    
