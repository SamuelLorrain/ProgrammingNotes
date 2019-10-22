#include <variant>

/*
 * variant est un objet qui contient une valeur
 * d'un type sur plusieurs défini
 * (c'est une sorte d'union plus safe)
 */

int main(){
    variant<int,float> a {7.5} //float
    if(holds_alternative<float>(a)){ //si a est un float
        std::cout << get<float>(a) << std::endl; //get la valeur float de variant
    }
}


