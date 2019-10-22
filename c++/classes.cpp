//class
class complex{ //definition d'une classe
        double re, im;
    public:
        complex(double r, double i) : re{r}, im{i}{} //constructeur
        complex(double r) : re{r}, im{0}{} //constructeur
        complex() :re{0}, im{0}{}
        ~complex(){} //destructor, utile si il y a de la mémoire
                     //dynamique à allouer
        double real() const { return re; }
        void real(double d){ re=d; }
        double imag() const { return im; }
        void imag(double d) const { im=d; }

        complex& operator+=(complex z){
            re+=z.re;
            im+=z.im;
            return *this;
        }

        complex& operator-=(complex z){
            re-=z.re;
            im-=z.im;
            return *this;
        }
};

complex operator+(complex a, complex b) { return a+= b; } //pas besoin de la représentation interne de
                                                        //la classe, peut être déclaré en dehors
class Vec{
        double *v;
        int s;
    public:
        Vec(size) : v{new double[size]}, s{size}{};
        Vec(std::initializer_list<double> lst) :v{new double[lst.size()], sz{static_cast<int>(lst.size())}}{
            copy(lst.begin, lst.end(), v);
        }; //initalize avec un truc standard pour avoir les élements
        ~Vec(){ delete[] v }; //RAII, le delete[] est dans le destructeur de l'objet,
                              //ainsi, à la fin du scope ou le Vec est défini, il est délété.

}

//class abstraite (abstract type)
class a{
    public:
        virtual void f1() = 0; //une fonction virtual est une fonction qui va
                           //eventuellement être définie plus tard.
                           //
                           //Une classe avec une fonction virtual, est une classe abstraite
        void f2() const{
            std::cout << "coucou" << std::endl;
        }
        virtual void ~a(); //destructeur
        //= 0 indique que la fonction est "full virtual", les classes qui dérivent
        //de celles-si doivent obligatoirement redéfinir les fonctions
        //notées = 0!
}

class b : a{ //class enfant
    b(){} //constructeur
    ~b(){} //destructeur
    //utilise les fonctions mères, si non redéfinies
    f2() const override{ //override signifie que la fonction est redéfinie.
            std::cout << "hello" << std::endl;
    }

    //override est optionel, mais permet au compilateur de faire
    //plus d'optimisations et d'erreur handling
}


