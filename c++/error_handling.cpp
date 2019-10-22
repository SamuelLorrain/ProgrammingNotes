#include <iostream>
#include <stdexcept> //include des erreurs

int constexpr MAX_SIZE = 255;

int function(int size){
    if (size < 0 || size > MAX_SIZE){
        throw std::out_of_range{"function(int) out of range!"}; //throw an exception
    }
}

void f_no_except(int size) noexcept //une fonction/méthode taggée noexcept ne peut
{                                   //recevoir d'exception
                                    //elle termine le programme si
                                    //il y en a une qui intervient
                                    //dans la fonction
    function(size);
}


int main(){
    static_assert(5==5); //static assert fonction avec toutes les valeur connues à la compilation

    int x = y = 5;
    assert(x==y) //assert fonction avec les valeurs connues at runtime
    try{
        function(300); //throw
    }
    catch (std::out_of_range &err){
        std::cerr << err.what() << std::endl; //lookup error
    }
    catch (std::bad_alloc &){
        printf("hmm\n");
    }

    try{
        f_no_except(300); //noexcept, quitte le programme à cette ligne
    }
    catch (std::out_of_range &err){
        std::cerr << err.what() << std::endl; //n'arrive jamais ici
    }

}
