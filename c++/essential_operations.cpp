//initialisation
//assignment
//copy
//move
//
//
//&& : "rvalue reference", c'est une référence à laquelle on peut attacher une rvalue.
//Une rvalue donc la partie droite d'une opération d'assignation (=), soit une valeur
//qu'on ne peut assigner, comme un int retourné par un appel de fonction.
//C'est donc une référence vers quelque chose qu'on ne peut pas assigner.
//On peut donc "voler" cette valeur.
//Un constructeur "move" ne prend pas d'argument const.
//Une opération move est appliquée quand une rvalue est utilisé comme initializer.

class X{
    public:
        X(a); //constructeur "ordinaire", creer un objet
        X(); //constructeur par défaut, généré sans avoir besoin de le définir
        X(const X&); //constructeur par copie
        X(X&&); //move constructeur
        X&operator=(const X&); //copy assignment
        X&operator=(X&&); //move assignment
        ~(); //destructor
        /* ... */
}

class Y{
    public:
        Y(a) = default; //demander à ce que ce soit le défault copy constructor
        Y(Y&&) = default; //default move constructor
        Y();
        ~Y() = delete; //indique que la fonction ne doit pas être générée
        /* ... */
        //quand il y a un default, les constructeurs
        //défini par défaut ne sont pas générés
}

class Z{
    public:
        explicit Z(int s); //interdit la conversion implicite
}

class Vector{
    Vector(const Vector&a); //copy
    Vector&operator=(const Vector&a); //copy
    Vector(Vector&&a); //move
    Vector&operator=(Vector&&a); //move
}

Vector f(){
    Vector x(1000);
    Vector y(2000);
    Vector z(3000);
    z = x; //copy
    y = std::move(x); //move
    return z; //move
}


