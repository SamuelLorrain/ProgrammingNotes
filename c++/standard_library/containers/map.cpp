#include <map>
//map est un balanced binary tree (hashmap)
//avec comme complexité O(log(n))

map<string,int> phone_book {
    {"David Hume",123456},
    {"Karl Popper",234567},
    {"W. Russel",345678}
};

phone_book["David Hume"]; //renvoi 123456
phone_book.find("Karl Popper"); //renvoi 23456, ne renvoi pas d'exception si il n'est pas dans le map
phone_book.insert("x", 1234); //insert dnas une map qui n'existe pas

#include <unordered_map>
//comme map, mais sans ordonnancement
