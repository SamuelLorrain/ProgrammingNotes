#include <vector>

//container
//
//implémentation de vector:
//struct Vector{
//  elem    //pointeur sur le premier element
//  space   //quantité de donnée allouée par le vecteur
//  last    //pointeur sur le dernier élement
//  alloc   //opération d'allocation pour ajouter de
//          //l'espace mémoire si besoin
//}

//vector est un type très performant, ne pas l'utiliser
//pour des raisons de performance n'est pas une super idée!

vector<int> v1 {1,2,3}; //size3
vector<int>v2(20); //size 20, premier élement : nullptr
vector<int>v2(20, 30); //size 20, premier élement : 30

v1.push_back(4); //ajoute un élement

v1.size(); //taille du vector
v1.capacity(); //nbr de cases allouées
v1.reserve(5); //augmente la capacité de 5 élements




