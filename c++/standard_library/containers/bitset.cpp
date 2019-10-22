#include <bitset>

//créé des flags
std::bitset<9> bs1 {"110001111"};
std::bitset<9> bs2 {0b1'1000'1111}; //binary litteral
std::bitset<9> bs3 = ~bs1;
std::bitset<9> bs4 = bs1&bs3;
std::bitset<9> bs5 = bs1<<2;

std::cout << bs1.to_string();
std::cout << bs1.to_ullong();

