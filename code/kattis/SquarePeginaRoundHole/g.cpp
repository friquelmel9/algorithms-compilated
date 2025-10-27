#include <bits/stdc++.h>

#define ld long double

int main(){
    
    ld n,m,k;
    std::cin >> n >> m >> k;
    
    std::priority_queue<ld> plot_radius;
    std::priority_queue<ld> house_radius;
    
    ld input;
    while(n--){
        std::cin >> input;
        plot_radius.push(input);
    }
    
    while(m--){
        std::cin >> input;
        house_radius.push(input);
    }
    
    while(k--){
        std::cin >> input;
        house_radius.push(input / std::sqrt(2.0));
    }
    
    long long solution = 0;
    
    while(!plot_radius.empty() && !house_radius.empty()){
        
        ld curr_plot_radius = plot_radius.top();
        plot_radius.pop();
        
        while(!house_radius.empty()){
            
            ld curr_house_radius = house_radius.top();
            house_radius.pop();
            if(curr_house_radius < curr_plot_radius){
                solution++;
                break;
            }
        }
    }
    
    std::cout << solution;
    
    
    return 0;
}