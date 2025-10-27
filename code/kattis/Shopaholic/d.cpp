#include <bits/stdc++.h>

#define ll long long

int main(){
    
    ll n;
    std::cin >> n;
    
    std::priority_queue<ll> prices;
    
    while(n--){
        ll item_price;
        std::cin >> item_price;
        prices.push(item_price);
    }
    
    std::vector<ll> trio;
    ll discounts = 0;
    
    while(!prices.empty()){
        
        trio.push_back(prices.top());
        prices.pop();
        
        if(trio.size() == 3){ 
            discounts += *std::min_element(trio.begin(), trio.end());
            trio.clear();
        }
        
    }
    
    std::cout << discounts;
    
    return 0;
}