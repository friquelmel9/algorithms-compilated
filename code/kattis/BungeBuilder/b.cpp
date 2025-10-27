#include <iostream>
#include <vector>
#include <random>

int main(){
    
    int n;
    std::cin >> n;
    std::vector<int> height(n);
    
    for(int i = 0; i < n ; i++){ std::cin >> height[i]; }
    
    std::cout << rand()%n;
    
}