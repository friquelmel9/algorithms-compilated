#include <iostream>
#include <vector>
#include <map>

int main(){
    
    int n;
    int median;
    int pos;
    
    std::cin >> n;
    std::cin >> median;
    
    std::vector<int> array(n);
    for(int i=0; i<n; i++){
        std::cin >> array[i];
        if(array[i] == median){pos = i;}
    }
    
    int offside;
    std::map<int,int> offValues; // stores how much of!!
    
    int total;
    offValues[0] = 1;
    
    offside = 0;
    for(int i=pos+1; i<n; i++){
        if( array[i] > median){offside++;}
        else {offside--; }
        offValues[offside]++; // There's one subarray with balance of offside. That means if offside is +1, there's a subarray that has one element desbalance
    }
    
    total = offValues[0];
    offside = 0;
    for(int i=pos-1; i>=0; i--){
        if( array[i] > median){offside++;}
        else {offside--; }
        total += offValues[-offside]; // if there are one disbalance to the left, it will offside everything on the right that's desbalanced. Negative of the actual offside:
    }
    
    std::cout << total;
    
    return 0;
}