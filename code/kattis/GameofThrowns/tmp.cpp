#include <iostream>

int main(){
    int h, t, n;
    h = 2;
    t = -3;
    n = 5;
    
    std::cout << "test1: " << (2+-3) % 5 << std::endl;
    std::cout << "test1: " << (h+t) % n << std::endl;
    std::cout << "test1: " << ((2+-3) % 5)+5 << std::endl;
    std::cout << "test1: " << ((h+t) % n)+n << std::endl;
}