#include <bits/stdc++.h>

#define ll long long

int main(){
    
    ll t;
    std::cin >> t;
    
    while(t--){
        
        ll l, n;
        std::cin >> l >> n;
        
        ll input;
        std::vector<ll> positions;
        
        for(int i=0; i<n; i++){
            std::cin >> input;
            positions.push_back(input);
        }
        
        ll min = 0;
        ll max = 0;
        
        for(int i=0; i<n; i++){
            
            ll curr_pos = positions[i];
            
            ll left_distance = curr_pos;
            ll right_distance = l - curr_pos;
            
            ll min_curr_distance = std::min(left_distance,right_distance);
            min = std::max(min_curr_distance,min);
            
            ll max_curr_distance = std::max(left_distance,right_distance);
            max = std::max(max_curr_distance,max);
        }
        
        std::cout << min << " " << max << std::endl;
        
    }

    return 0;
}