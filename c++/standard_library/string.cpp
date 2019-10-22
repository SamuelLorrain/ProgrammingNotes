#include <string>

std::string name = "Toto";
std::string surname = "Machin";
std::string mail = name + '.' + surname + "@gmail.com"; //concatenation (char et std::string)
//string utilise un move constructor, donc retourner des strings est peu couteux.

std::string name += '\n'; //+= concatenation

char a = name[1] //[] operator

std::string s = mail.substr(5,5); //Machin
mail.replace(0,4, "Toast"); //Toast.Machin@gmail.com
mail[0] = tolower(mail[0]);

//comparaisons avec == (std::string, litteral ou Cstring)

name == surname; //false;

name == "Toto"  //true

printf("%s\n", name.c_str()); //c string représentation (char*)

using std::literals::string_literals
auto s = "Cat"s; //std::string
auto p = "Dog"; //const char*

#include <basic_string> //surclasse de string, permet de
                        //créer des strings utilisant des types de
                        //charactères diffférents
class JapaneseChar{
    /* ... */
}

using JapaneseChar = basic_string<JapaneseChar>;

#include <string_view> //permet de passer des substrings
                       //à des fonctions, à l'aide d'un
                       //itérator
//une string_view est une pair pointeur/length sur une
//chaine de charactère
//Une string view donne accès à un accès contigus d'une
//séquence de charactère, que ce soit une std::string ou une C style string
//(en gros, permet de faire des fonctions utilisable, quelque soit le type
//de string)
//string_view est read-only
std::string cat(string_view sv1, string_view sv2){
    string res(sv1.length()+sv2.length());
    char* p = &res[0];
    for(char c : sv1){ //une façon de copier
        *p++ = c;
    }
    copy(sv2.begin(), sv2.end(), p); //une autre façon de copier
    return res;
}

#include <regex>

std::regex pattern {"\\w{2}\\s*\\d{5} (-\\d{4})?"};
std::regex pattern {R"\w{2}\s*\d{5} (-\d{4})?"}; //R"" permet de ne pas avoir à
                                                 //escaper les charactères

//regex_search
int lineno = 0;
for(string line, getline(cin,line)){
    ++lineno;
    std::smatch matches; //matched strings
                         //matches est un vector
                         //qui stocke les matches
    if(regex_search(line,matches,pattern)){
        cout << lineno << ": " << matches[0] << '\n'; //complete match
        if(1< matches.size() && matches[1].matched){
            cout << "\t: " << matches[1] << '\n'; //optional sub-pattern match "(-\\d{4})?"
        }
    }
}

regex_match(s,pattern); //true si il y a match


//using sregex_iterator == regex_iterator<string> (présent par défaut)
//regex_iterator
//itère sur tous les charactères en trouvant à chaque fois les patterns
//comme regex_iterator est bi-directionnel, on ne peut pas l'utiliser
//sur un istream...
void test(){
    std::string input = "aa as; asd ++e^asdf asdfg";
    std::regex pat {R"(\s+(\w+))"};
    for(std::sregex_iterator p(input.begin(), input.end(), pat); p!=s_regex_iterator{}; ++p){
        std::cout << (*p)[1] << std::endl;
    }
}


#include <sstream>
//istringstream pour ecrire dans une string
//ostringstream pour lire dans une string
//streagstream pour lire et ecrire dans un string

void test(){
    ostringstream oss;
    oss << "{temperature," << scientific << 123.4567890 << "}";
    std::cout << oss.str() << '\n';
}


template<typename Target =string, typename Source =string>
Target to(Source arg){
    stringstream interpreter;
    Target result;
    if(!(interpreter <<arg) || !(interpreter >> result || !(interpreter >>std::ws).eof())
        throw runtime_error{"to<>() failed"};
    return result;
}
auto x = to(1.2);


#include <cstring>
std::ios_base::sync_with_stdio(false); //sans cette ligne, iostream peut être plus lent à cause
                                       //del a synchro avec stdio
