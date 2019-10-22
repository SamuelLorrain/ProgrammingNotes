#include <iostream>


namespace My_Code { //tous les élements défini dans My_Code devronts être précédés de My_Code::
    int function(); //fonction déclarée mais non définie
    int myvar = 19;

    int f2(){ //définition à l'intérieur du namespace
        return 10;
    }
}

namespace dummy{ //2eme namespace
    int function(){
        return 19;
    }
}

int My_Code::function(){ //définition de la fonction en dehors de My_Code
    return 5;
}

int main(){
    std::cout << My_Code::function(); << std::endl; //appelle de la fonction en dehors de My_Code

    using namespace My_Code
    std::cout << function(); << std::endl; //appel de la fonction en dehors de My_Code, avec using namespace

    dummy::function(); //appel de la fontion function() du namespace dummmy

    return 0;
}



