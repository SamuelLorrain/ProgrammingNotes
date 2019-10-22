#include <ostream>
//std::cout est un objet de type output stream (ostream)

std::cout << "sortie standard\n";
std::cerr << "sortie d'erreur standard\n";
int i = 0;
std::cout << "the value of i is " << i << "\n"; //<< en cascade

#include <istream> //std::cin est un objet de type input stream (istream)

int j;
std::cin >> j; //lit un int dans l'entrée standard
               //>> est bloqué par un white space, un saut de ligne etc.


std::string str;
std::getline(std::cin, str); //lire une ligne entière dans l'entrée

#include <iostream>
#include <vector>

//io state
std::vector<int> read_ints(istream &is, const std::string& terminator){
    vector<int> res;
    for(int i; is>>i;){ //un istream renvoi true si il est prèt pour une nouvelle opération
        res.push_back(i);
    }
    if(is.eof()){ //end of file
        return res
    }
    if(is.fail()){ //failed to read an int
        is.clear(); //reset de state to .good()
        is.unget(); //put the non-digit back into the stream
        std::string s;
        if(std::cin >> s && s == terminator){
            return res;
        }
        std::cin.setstate(ios_base::failbit); //add fail() to cin's state

    }
    return res;
}
auto v = read_ints(std::cin,"stop");

//User defined iostream
struct Entry{
    std::string name;
    int number;
}

ostream& operator<<(ostream &os, const Entry &e){
    return os << "{\"" << e.name << "\", " << e.number << "}";
}

istream& operator>>(istream &is, Entry &e){
    char c, c2;
    if(is>>c && c=='{' && is>>c2 && c2 =='"'){
        std::string name;
        while(is.ge(c) && c!='"'){
            name += c;
        }
        if(is>>c && c==','){
            int number = 0;
            if(is >> number >> c && c == '}'){
                    e = {name, number};
                    return is;
            }
        }
    }
}

#include <ios>
#include <iomanip>
std::cout << 1234 << ',' <<hex << 1234 << ',' << oct << 1234 << '\n'; //print 1234,4d2,2322

constexpr double d = 123.456
std::cout << d << ";"
            << scientific << d << ";"
            << hexfloat << d << ";"
            << fixed << d << ";"
            << defaultfloat << d << ";" << '\n';

std::cout.precision(4); //modifier la précision des nombres floatant affichés dans std::cout

#include <fstream>
//ifstream, ecrire dans un fichier
//ofstream, lire un fichier
ofstream ofs {"target"};
if(!ofs)
    error("couldn't open 'target' for writing");
ifstream ifs {"source"};
if(!ifs)
    error("couldn't open 'source' for writing");
//si ils existent ofs et ifs peuvent être considérés comme
//des istreams et ostreams "normaux"


#include <cstring>
std::ios_base::sync_with_stdio(false); //sans cette ligne, iostream peut être plus lent à cause
                                       //del a synchro avec stdio
