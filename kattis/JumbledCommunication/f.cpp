#include <iostream>
#include <cmath>


int unscrambling_algorithm(int scrambled_code){
    
    int unscrambled_message = 0;
    int x_prev = 0; 
    
    for(int i=0; i<8; i++){
        
        int byte = (scrambled_code >> i) & 1;
        int x_right = 0; // It compares to the next one by itself
        
        if(i == 0) { x_right = byte; }
        else { x_right = byte ^ x_prev; }
        
        if(x_right == 1){
            unscrambled_message |= (1 << i);
        }
        
        x_prev = x_right;
        
    }
    
    return unscrambled_message;
    
}

int main(){
    
    int n;
    std::cin >> n;
    
    for(int i=0; i<n; i++){
        
        int input;
        std::cin >> input;
        
        int message = unscrambling_algorithm(input);
        std::cout << message << " ";
        
    }
    
    std::cout << std::endl;
    
    return 0;
}