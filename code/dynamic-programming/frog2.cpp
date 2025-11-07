/** Problem Statement
Problem Statement

There are
N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is

hi​.

There is a frog who is initially on Stone
1. He will repeat the following action some number of times to reach Stone

N:

    If the frog is currently on Stone 

i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of ∣hi​−hj​∣ is incurred, where

    j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone

N.
Constraints

    All values in input are integers.

2≤N≤105
1≤K≤100

    1≤hi​≤104

Input

Input is given from Standard Input in the following format:

N 

K

h1​ 

h2​ 

… 

hN​

Output

Print the minimum possible total cost incurred.
Sample Input 1


5 3
10 30 40 50 20

Sample Output 1


30

If we follow the path
1 → 2 → 5, the total cost incurred would be

∣10−30∣+∣30−20∣=30.
Sample Input 2


3 1
10 20 10

Sample Output 2


20

If we follow the path
1 → 2 → 3, the total cost incurred would be

∣10−20∣+∣20−10∣=20.
Sample Input 3


2 100
10 10

Sample Output 3


0

If we follow the path
1 → 2, the total cost incurred would be

∣10−10∣=0.
Sample Input 4


10 4
40 10 20 70 80 10 20 70 80 60

Sample Output 4


40

If we follow the path
1 → 4 → 8 → 10, the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.
 * @source: https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include <bits/stdc++.h>

#define ll long long

/**
 * Realiza el Dynamic programming al problema, obtiene el valor del salto en el index
 * 
 * @param curr_pos Posición actual (en index)
 * @param K_jump Maximo salto
 * @param heights Alturas de las piedras
 * @param dp Tabla basada en memorización que guarda los estados previamente calculados
 */
ll jump(ll curr_pos, ll K_jump, std::vector<ll>&heights, std::vector<ll>&dp){
    
    if(curr_pos == heights.size()-1){return 0;}
    if(dp[curr_pos] != -1) { return dp[curr_pos]; }
    
    ll min_jump = LONG_LONG_MAX;
    for(ll k = 1; k <= K_jump; k++){
        if(curr_pos+k >= heights.size()){break;}
        ll curr_jump = std::abs(heights[curr_pos] - heights[curr_pos+k]) + jump(curr_pos+k,K_jump,heights,dp);
        min_jump = std::min(min_jump, curr_jump);
    }
    
    dp[curr_pos] = min_jump;
    return dp[curr_pos];
}

/**
 * Obtiene las mediciones del testcases
 */
void testcase(){
    
    ll N_stones, K_jump;
    std::cin >> N_stones >> K_jump;
    
    std::vector<ll> heights(N_stones);
    for(ll i = 0; i < N_stones; i++){ std::cin >> heights[i]; }
    
    ll sum;
    std::vector<ll> dp(100000+K_jump,-1);
    
    sum = jump(0,K_jump,heights,dp);
    std::cout << sum << std::endl;
}

int main(){
    testcase();
    return 0;
} 