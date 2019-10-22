//template <class T> (class et typename sont équivalent, typename est plus récent et préférable
template <typename T> class Vector{
    private:
        T* elem;
        int sz;
    public:
        explicit Vector(int s);
        ~Vector(){delete[] elem;}
        /*...*/
        T& operator[](int i);
        const T& operator[](int i) const;
        int size() const { return sz; }

        T* begin(Vector<T> &x);
        T* end(Vector<T> &x);
        template <typename Iter> Vector(Iter a, Iter b); //constructeur avec un itérateur
                                                         //le compilateur ne sais 'rien'
                                                         //sur le type de Iter
        //c++ 2017
        template <typename Iter> Vector(Iter a, Iter b) -> Vector2<typename Iter::value_type>;
        //"deduction guide" indique le type de Iter pour éviter les ambiguitées


}

//template avec plusieurs arguments:
template <typename T, int N> class Buffer{
    using value_type = T; //acces exterieur aux template arguments (read-only)
    constexpr int size() { return N; } //acces exterieur aux template arguments (read-only)
    //à développer
    T[N];
    /* ... */
}
Buffer<char,1024> //on déclare le "value_type" plutôt qu'une valeur


//utilisation de la classe pair
std::pair p = {1,5.2}; //cpp 2017 (utilie les template arguments pour inférer) le type et créer l'élément
auto p = make_pair(1,5.2); //cpp -2017 utilise une fonction standard pour créer l'élement (et inférer le type)




//déclarer des vecteurs de différents types
Vector<char>vc(200);
Vector<std::string>vs(17);
Vector<std::list<int>> vli(45); //vecteur de list de int

//fonction uniquement sur les Vector<std::string>
void write(const Vector<std::string> &vs){
    for(int i = 0; i !=vs.size(); ++i)
        std::cout << vs[i] << std::endl;
}

//définition de begin et end pour l'itérateur
template<typename T> T* begin(Vector<T> &x){
    return x.size() ? &x[0] : nullptr;
}

template<typename T> T* end(Vector<T> &x){
    return x.size() ? &x[0]+x.size() : nullptr;
}

void f2(Vector<int> &vi){
    for(auto &i : vi){
        std::cout << i << std::endl;
    }
}


//template du type de retour de la fonction
template<typename Sequence, typename Value>
Value sum(const Sequence &s, Value v){
    for(auto x: s) v+=x;
    return v;
}


//define
template <class T> constexpr T viscosity = 0.4;
template <class T> constexpr space_vector<T> external_acceleration = { T{}, T{-9.8}, T{}};
auto vis2 = 2*viscosity<double>
auto acc = external_acceleration<float>;


