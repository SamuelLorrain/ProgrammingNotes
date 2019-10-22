//Ressource management
#include <memory>
//unique_ptr : unique ownership
//shared_ptr : shared ownership

//L'utilisation basiques de ces smart pointeurs,
//est de prevenir les memory leaks.
//grâce à l'ownership (comme en Rust?)
void f(int i, int j){
    int* p = new int; //allocate new X
    std:unique_ptr<int> sp {new int}; //allocate new X et le mettre dans un
                                      //unique_ptr
    if(p<99) throw Z{}; //on devrait delete p ici
    if(j<77) return; //ici aussi
    /* .. */
    delete p;
    //l'unique_ptr est détruit à la sortie du scope
    //qu'elle que soit la sortie
}

//shared_ptr est comme unique_ptr
//sauf qu'il utilise un mécanisme de copy plutôt que move.
//Le pointeur est supprimé quand la dernière reférence à
//l'objet est supprimée
void user(const std::string&name, ios_base::openmode mode){
    shared_ptr<fstream> fp {new fstream(name,mode)};
    if(!*fp)
        throw No_file();
    //f et g copient l'objet en paramètre
    f(fp);
    g(fp);
}

//autre façon de créer un smart pointeur
//plus efficace car pas besoin de new
auto p1 = std::make_shared<int>(5);
auto p2 = std::make_shared<std::string>("Test");

//move()
//équivalent à un 'rvalue_cast'
//comme tous les cast, il ne doit être utilisé que
//dans des cas très précis.
void f1(){
    auto p = std::make_unique<int>(2);
    auto q = p; //error, on ne peut pas coper un unique_ptr
    auto q = std::move(p); //déplace l'ownership, p est maintenant nullptr
                           //et q pointe vers ce que p pointait avant

}


