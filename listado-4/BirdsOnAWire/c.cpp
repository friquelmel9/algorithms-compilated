#include <bits/stdc++.h>

#define ll long long

int main(){
    
    ll l,d,n;
    std::cin >> l >> d >> n;
    
    // case 1: pole too short
    if(l <= 12){ 
        std::cout << 0 << std::endl;
        return 0;
    }
    
    // case 2: no birds on wire
    if(n==0){
        std::cout << (l-12)/d << std::endl;
        return 0;
    }
    
    // case 3: birds on wire
    std::vector<ll> positions; // works like nodes
    
    for(ll i=0; i<n; i++){
        
        ll input;
        std::cin >> input;
        positions.push_back(input);
        
    }
    
    positions.push_back(6);
    std::sort(positions.begin(), positions.end());
    positions.push_back(l-5);
    
    ll new_birds = 0;
    
    for(ll i=0; i<n+1; i++){
        
        ll pos1 = positions[i];
        ll pos2 = positions[i+1];
        
        new_birds += (pos2-pos1-1)/2;
        
    }
    
    std::cout << new_birds << std::endl;
    
    return 0;
}