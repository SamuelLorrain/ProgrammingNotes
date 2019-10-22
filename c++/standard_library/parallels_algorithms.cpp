#include <execution> //contient des objets sur
//les executions parallelles (mulitple thread)
//et vectorisées, séquentielles (SIMD)
//
//Quand on utilise les executions parallèle,
//il faut gérer les mutex et tout pour
//éviter deadlocks et undefined

std::sort(std::seq,v.begin(),v.end()); //sequentielles (par défaut)
std::sort(std::par,v.begin(),v.end()); //parallèle
std::sort(std::par_unseq,v.begin(),v.end()); //parallèle et/ou vectorisé



