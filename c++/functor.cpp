//Functor, "function objet"
//Une classe qui implémente un call operator ()
//est un fonctor
template <typename T> class Less_than{
        const T val;
    public:
        Less_than(const T& v) :val{v}{}
        bool operator()(const T&x) const { return x<val; } //implémente le function call operator
};

Less_than lti {42};
Less_than lts {"Backus"s};
Less_than<std::string>lts2 {"Naur"};
lti(30); //function call, return true;



//lambda
[&](int a){ return a<x; } //notation lambda
                          //créé un fonctor
//[&] est une liste de capture des locals names utilisés dans
//le lambda body.
//Ces élements osnt accessibles par référence.
//
//[&x] indique qu'on ne veut que capturer x
//[] ne capture rien
//[=x] capture une copie de x
//[=] copie tous les local names
//
//Voir plus en détail
