#include <bits/stdc++.h>

#define ll long long

struct Object{
    ll value;
    ll weight;
};

/** Problem Statement:
Implement a solution to the classic knapsack problem. You are given a knapsack that can hold up to a certain weight (its capacity), 
and several items you may choose to put in the knapsack. 
Each item has a weight and a value. 
Choose a subset of the items (which could be all of them, or none of them) having the greatest value that fit into the knapsack 
(i.e. the sum of the weights of the items you choose must be less than or equal to the knapsack capacity).

Input

The input consists of between 1 and 30 test cases. Each test case begins with an integer 1≤C≤2000, 
giving the capacity of the knapsack, and an integer 1≤n≤2 0001≤n≤2000, giving the number of objects. 
Then follow nn lines, each giving the value and weight of the nn objects. Both values and weights are integers between 11 and 10 00010000.
Output

For each test case, output a line containing the number of items chosen, followed by a line containing the indices of the chosen items (the first item has index 00, the second index 11, and so on). The indices can be given in any order.

Sample 1:

Input:
5 3
1 5
10 5
100 5
6 4
5 4
4 3
3 2
2 1

Output:
1
2
3
1 2 3

 * @source: https://vjudge.net/contest/761487#problem/A
*/

void knapstack(ll capacity, std::vector<Object>& objects, std::vector<std::vector<ll>>& dp){
    
    // Tablutaion approach to calculate values
    
    for(ll i=1; i<=objects.size(); i++){
        ll curr_value = objects[i-1].value;
        ll curr_weight = objects[i-1].weight;
        
        for(ll w=1; w<=capacity; w++){ 
            if(curr_weight > w){ dp[i][w] = dp[i-1][w]; } // if can't take
            else{
                ll not_take_value = dp[i-1][w];
                ll take_value = curr_value + dp[i-1][w - curr_weight];
                dp[i][w] = std::max(not_take_value, take_value);
            }
        }
        
    }
    
    // Reconstructing the best set
    
    std::vector<ll> selected_objects;
    ll curr_weight = capacity;
    
    for(ll i = objects.size(); i > 0; i--){
        
        if(dp[i][curr_weight] != dp[i-1][curr_weight]){ // If it changed, an item was included
            selected_objects.push_back(i-1);
            curr_weight -= objects[i-1].weight;
        }
    }
    
    // Output
    
    std::cout << selected_objects.size() << std::endl;
    for(ll i=0; i<selected_objects.size(); i++){
        std::string s = " ";
        if(i == selected_objects.size()-1){ s = ""; }
        std::cout << selected_objects[i] << s; 
    }
    std::cout << std::endl;
}

int main(){
    
    ll capacity, n_objects;
    while(std::cin >> capacity >> n_objects){
        std::vector<Object> objects(n_objects);
        for(ll i=0; i<n_objects; i++) { std::cin >> objects[i].value >> objects[i].weight; }
        
        std::vector<std::vector<ll>> dp(n_objects+1, std::vector<ll>(capacity+1, 0));
        knapstack(capacity,objects,dp);
    }
    
    return 0;
}