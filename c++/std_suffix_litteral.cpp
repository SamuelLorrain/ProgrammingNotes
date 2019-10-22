//h, min, s, ms, us, ns
//sont des suffix litterals de
//std::literals::chrono_literals
//
//s <string>,sv <string_view>
//sont des suffix litteral de
//std::literals::string_literals
//
//<complex>
//i, il ,if
//sont des suffix litteral de
//std::literals::complex_literals


constexpr complex<double>operator""i(long double arg){
    return {0,arg};
} //imaginary litteral
//permet de définir un nouveau litteral.
//
//operator"" est un indicateur de définition de string litteral
//i est le litteral
//(long double arg) est l'argument
