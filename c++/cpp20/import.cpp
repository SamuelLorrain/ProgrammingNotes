import Vector; //importer le module
#include <iostream> //ancien type d'importation

int main(){
    Vector v = new Vector(5); //créer un vector avec la classe importée
    std::cout << v.size() << std::endl;
}
