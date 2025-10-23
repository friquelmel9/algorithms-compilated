#include <bits/stdc++.h>

#define ld float
#define ll long long

using namespace std;

int main(){
    
    ld T;
    cin >> T;
    
    ll N;
    cin >> N;
    
    auto comp = [](const pair<ll,ll> &a, const pair<ll,ll> &b){
        return (a.first/a.second) < (b.first/b.second);
    };
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, decltype(comp)> ratios(comp); 
    
    ld min_value = LONG_LONG_MAX;
    ll weight;
    
    while(N--){
        cin >> weight;
        ratios.push({weight, 1});
        min_value = std::min(min_value, (ld)weight); 
    }
    
    ll cuts = 0;
    
    while(!ratios.empty()){
        pair<ll, ll> max_ratio = ratios.top();    
        if(min_value/(max_ratio.first/max_ratio.second) >= T) break;
        
        
        ratios.pop();
        ratios.push({max_ratio.first, (max_ratio.second + 1)});
        cuts++;
        
        min_value = std::min(min_value, (ld)(max_ratio.first/(max_ratio.second + 1)));
            
    }
    
    std::cout << cuts;
    
    return 0;
}