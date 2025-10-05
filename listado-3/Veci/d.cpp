#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

int main(){
    
    long long x;
    std::cin >> x;
    
    std::string number = std::to_string(x);
    int n = number.size();
    
    int pivot = n-2;
    
    while(pivot >= 0){
        
        char digit1 = number[pivot];
        char digit2 = number[pivot+1];
        
        if(digit1 < digit2){ break; }
        pivot--;
    }
    
    if (pivot == -1){ std::cout << "0" << std::endl; }
    else{
        
        int j = n-1;
        while(number[j] <= number[pivot]){ j--; }
        
        std::swap(number[j], number[pivot]);
        
        std::string::iterator itr1 = number.begin() + pivot + 1;
        std::reverse(itr1, number.end());
        
        std::cout << number << std::endl;
    }
    
    return 0;
    
}