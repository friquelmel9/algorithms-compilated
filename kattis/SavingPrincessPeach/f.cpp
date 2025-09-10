#include <iostream>
#include <unordered_set>

int main(){
    
    unsigned int n;
    unsigned int y;
    unsigned int b;
    
    std::cin >> n;
    std::cin >> y;
    
    std::unordered_set<unsigned int> obstacles;
    
    for(int i=0; i<y; i++) {
        std::cin >> b;
        obstacles.insert(b);
    }
    
    for(int i=0; i<n; i++) {
        if(obstacles.find(i) == obstacles.end()) {std::cout << i << std::endl; }
    }
    
    std::cout << "Mario got " << obstacles.size() << " of the dangerous obstacles.";
    return 0;
}