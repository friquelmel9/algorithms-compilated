#include <algorithm>
#include <set>
#include <iostream>

int main(){
    
    long long n, m;
    std::cin >> n;
    std::cin >> m;
    long long input;
    
    //paint sizes offered
    std::set<long long> paint_sizes;
    for(int i=0; i<n; i++){
        std::cin >> input;
        paint_sizes.insert(input);
    }
    
    // number of colours needed
    long long spare_paint = 0;
    
    for(int i=0; i<m; i++){
        std::cin >> input;
        std::set<long long>::iterator itr = paint_sizes.lower_bound(input);
        spare_paint += *itr - input;
    }
    
    std::cout << spare_paint << std::endl;
    
    return 0;
}