#include <iostream>
#include <cmath> //include math.c library

int constexpr defineLike = 5; //Comme un define en C, mais plus sur
using size_t = unsigned int; //Comme un typedef

if constexpr(is_pod<int>::value){ //if constexpr comme les ifdef
}

int constexpr deuxPlusdeux(){ //fonction constexpr
    return 2+2;
}

struct V{ //définition d'une structure comme en C
    int sz;
    double* elem;
};

void init_V(V &v, int size){
    v = new double[size]; //allocation dynamique
    sz = size;
}

//class
class Vec{
    public:
        Vec(int size) :elem{new double[size]}, sz{s} {} //Constructeur
        double& operator[](int i) { return elem[i]; }
        int size(){return size;}
    private:
        double* elem;
        int size;
}

enum class Color { red, blue, green}; //enum dans des classes
enum class Traffic_light { red, yellow, green}; //enum dans des classes
Traffic_light& operator++(Traffic_light&t){ //Definition de fonction sur des enum
    //uniquement les operateurs sont alloués
    switch(t){
        case Traffic_light::green: return t=Traffic_light::yellow;
        case Traffic_light::yellow: return t=Traffic_light::red;
        case Traffic_light::red: return t=Traffic_light::green;
    }
}


int alpha(int &a, const int &b){ //utiliser const & pour ne copier que les références aux objets,
                                       //et pas de pures copies, sans pour autant pouvoir les modifier
        a += b;
        return a + b;
}

int beta(const int a, const int b = 10){ //la fonction copie les valeurs de a et de b, et non leur référence
    return a + b;                        //la valeur par défaut de b est 10
}

//unpacking!
struct d{
    int a;
    std::string b;
}

struct d func(){
    int a {10};
    std::string b {"Test"};

    return {a,b}; //retourne une struct d
}


int main(){
    auto [a,b] = func(); //a est un int et b un std::string
    std::cout << a << " " << b << std::endl;

    Color color = Color::red; //color
    auto traffic = Traffic_light::yellow;//
    //Color c2 = Traffic_light::green // ERROR
    V v;
    initV(v,5); //utilisation de la structure
    std::cout << "Hello World" << std::endl; //sortie standard
    Vec w(5) //créé un Vec de 5 élements
    float a {7.5}; //Assignation sans conversion de type
    float &b = a; //Reference à b
    int v[10];
    int *p = nullptr; //utilisation de nullptr à la place de NULL en C
    auto c = "test"; //inférence de type, ici char*
    for(auto &x : v){ //for in
        x = 1;
    }
    for(auto x : v){ //for in
        std::cout << x << std::endl;
    }
    std::cout << defineLike << std::endl;
    delete v //free C++
    return 0;
}
