// Containers génériques:
// vector<T> //vector a taille variable
//
// list<T> //double linked list
// forward_list<T> //simple linked list
// deque<T> //double ended queue
// set<T> //set (map avec juste des key mais pas de valeur)
// multiset<T> //set (multimap)
//
// map<K,V> //hash map associative (key value)
// multimap<K,V> //hash map, une key peut intervenir plusieurs fois
//
// unordered_map
// unordered_multimap
// unordered_set
// unordered_multiset


//Containers spécialisés:
//queue<T>
//stack<T>
//priority_queue<T>
//array<T,N> //fixed size array
//bitset<N>


//Opérations (certaines):
//value_type    //le type d'un élement
//p=c.begin()   //p pointe sur le premier élement de c (voir aussi cbegin() pour const begin())
//p=c.end()
//k=c.size()
//c.empty()
//k=c.capacity()
//c.reserve(k)
//c[k]
//c.at(k)
//c.push_back(k)
//c.emplace_back(k)
//q=c.insert(p,x) //ajoute x avant p (p=pointeur sur un élement)
//q=c.erase(p)
//=
//==, !=
//<, <=, >, >=

