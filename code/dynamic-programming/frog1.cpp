/** Problem Statement
Problem Statement

There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h_i​.

There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi​−hj​∣ is incurred, where
j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints

All values in input are integers.

2≤N≤10^5
1≤hi​≤10^4

Input

Input is given from Standard Input in the following format:

N, h1​, h2​ … hN​

Output

Input 1

4
10 30 40 20

Output

30

If we follow the path 1 → 2 → 4, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Input 2

2
10 10

Output

0

If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.

Input

6
30 10 60 10 60 50

Output

40

If we follow the path 1 → 3 → 5 → 6, the total cost incurred would be ∣30−60∣+∣60−60∣+∣60−50∣=40.

Print the minimum possible total cost incurred.


 * @source: https://atcoder.jp/contests/dp/tasks/dp_a
*/

#include <bits/stdc++.h>

#define ll long long

/**
 * Realiza el Dynamic programming al problema, obtiene el valor del salto en el index
 * 
 * @param curr_pos Posición actual (en index)
 * @param heights Alturas de las piedras
 * @param dp Tabla basada en memorización que guarda los estados previamente calculados
 */
ll jump(ll curr_pos, std::vector<ll>&heights, std::vector<ll>&dp){
    
    if(curr_pos == heights.size()-1){return 0;}
    if(dp[curr_pos] != -1) { return dp[curr_pos]; }
    
    ll jump_one = std::abs(heights[curr_pos] - heights[curr_pos+1]) + jump(curr_pos+1,heights,dp );
    
    ll jump_two;
    if(curr_pos + 2 >= heights.size()){ jump_two = LONG_LONG_MAX; }
    else{ jump_two = std::abs( heights[curr_pos] - heights[curr_pos+2]) + jump(curr_pos+2,heights,dp);}
    
    dp[curr_pos] = std::min(jump_one,jump_two);
    return dp[curr_pos];
    
    
}

/**
 * Obtiene las mediciones del testcase
 */
void testcase(){
    
    ll N_stones;
    std::cin >> N_stones;
    
    std::vector<ll> heights(N_stones);
    for(ll i = 0; i < N_stones; i++){ std::cin >> heights[i]; }
    
    ll sum;
    std::vector<ll> dp(100002,-1);
    
    sum = jump(0,heights,dp);
    std::cout << sum << std::endl;
}

int main(){
    testcase();
    return 0;
} 