module; //defini un module à la compilation, le fichier est considéré comme un module
export module Vector; //export module indique que le module s'appelle "Vector"
                      //cette ligne à indiquer sous quel nom on doit utiliser un
                      //autre fichier

//le module n'exporte que les objets qui commencent pas "export"

export class Vector{ //le module exporte la class
    public:
        Vector(int s);
        double&operator[](int i);
        int size();

    private:
        double *elem;
        int sz;
}

Vector::Vector(int s) :elem{new double[s]}, sz{s} {}
double&Vector::operator[](int i){
    return elem[i];
}
int Vector::size(){
    return sz;
}

export int size(const Vector&v) { return v.size(); }

int truc(){ //cette fonction n'est pas exportée
    return 5;
}
