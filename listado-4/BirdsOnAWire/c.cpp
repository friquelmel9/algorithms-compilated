#include <bits/stdc++.h>

#define ll long long

int main(){
    
    ll l,d,n;
    std::cin >> l >> d >> n;
    
    std::vector<ll> positions;
    ll input;
    for(int i=0; i<n; i++){
        std::cin >> input;
        positions.push_back(input);
    }
    
    if(n>0){std::sort(positions.begin(), positions.end());}
    
    ll new_birds = 0;
    
    // case birds
    for(ll i=0; i<n-1; i++){
        
        ll pos1 = positions[i];
        ll pos2 = positions[i+1];
        
        new_birds += std::max((pos2-pos1)/d - 1, 0ll);
    }
    
    // edge cases
    if(n > 0){
        new_birds += (positions[0]-6)/d;
        new_birds += (l-6-positions[n-1])/d;
    }
    else if(l >= 12) // no birds but string
        new_birds += (l-12)/d + 1;
    
    std::cout << new_birds << std::endl;
    return 0;
}