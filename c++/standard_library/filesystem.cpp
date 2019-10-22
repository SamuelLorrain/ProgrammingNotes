#include <filesystem>

std::path f = "dir/test.cpp";
assert(std::exists(f));
if(std::is_regular_file(f))
    cout << f << "is a file; its size is " << file_size(f) << '\n';

#include <fstream>
std::path p = "dir/test.cpp";
ofstream file {p}; //utiliser un path pour ouvrir un fichier

//quelques méthodes de filesystem 
std::path p = "/un/path/quelconque/avec/un/fichier/à/la/fin/ou/pas";
std::is_directory(p);


try{
    if(is_directory(p)){
        for(const std::directory_entry &x : std::directory_iterator{p}){
            std::cout << " " << x.path() << '\n';
        }
    }
}
catch(const filesystem_error &ex){
    std::cerr << ex.what() << '\n';
}

//plein d'autres opérateurs...
