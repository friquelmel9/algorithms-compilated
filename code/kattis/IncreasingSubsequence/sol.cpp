/**
---

A strictly increasing sequence is a sequence of numbers $a_1, a_2, \ldots, a_n$ such that, for $1 < i \leq n$, $a_{i-1} < a_i$. A subsequence of $a_1, a_2, \ldots, a_n$ is identified by a strictly increasing sequence of indices, $x_1, x_2, \ldots, x_m$ where $1 \leq x_1$ and $x_m \leq n$. We say $a_{x_1}, a_{x_2}, \ldots, a_{x_m}$ is a subsequence of $a_1, a_2, \ldots, a_n$. For example, given the sequence $8, 90, 4, 10\,000, 2, 18, 60, 172, 99$, we can say that $90, 4, 10\,000, 18$ is a subsequence but $8, 90, 18, 2, 60$ is not. The subsequence $4, 18, 60, 172$ is a subsequence that is, itself, strictly increasing.

Given a sequence of numbers, can you write a program to find a strictly increasing subsequence that is as long as possible?

**Input**

Input has up to $200$ test cases, one per line. Each test case starts with an integer $1 \leq n \leq 200$, followed by $n$ integer values, all in the range $[0, 10^8]$. A value of zero for $n$ marks the end of input.

**Output**

For each test case, output the length of the longest strictly increasing subsequence, followed by the values of the lexicographically-earliest such sequence. A sequence $a_1, a_2, \ldots, a_m$ is lexicographically earlier than $b_1, b_2, \ldots, b_m$ if some $a_i < b_i$ and $a_j = b_j$ for all $j < i$.

**Sample 1**

4 1 25 2 3
4 1 2 2 3
8 90 4 10000 2 18 60 172 99 
0

Output 1:

3 1 2 3
3 1 2 3
4 2 18 60 99

---
* @source: https://vjudge.net/contest/761487#problem/E
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

std::vector<ll> reconstruct(std::vector<ll> &values, std::vector<ll> &dp_last_item, ll last_idx){
    
    std::stack<ll> stack;
    
    while(last_idx != -1){
            
            stack.push(values[last_idx]);
            last_idx = dp_last_item[last_idx];
            
        }
        
        std::vector<ll> result;
        while(!stack.empty()){
            result.push_back(stack.top()); stack.pop();
        }
    
    return result;
    
}

void longestIncreasingSubsequence(std::vector<ll> &values, std::vector<ll> &dp_subsequence, std::vector<ll> &dp_last_item){
    
    ll n = values.size();
    
    for(ll curr_idx = 1; curr_idx < n; curr_idx++){
        for(ll prev_idx = 0; prev_idx < curr_idx; prev_idx++){
            
            if(values[curr_idx] > values[prev_idx]){
                
                if(dp_subsequence[curr_idx] < dp_subsequence[prev_idx] + 1){
                    dp_subsequence[curr_idx] = dp_subsequence[prev_idx] + 1;
                    dp_last_item[curr_idx] = prev_idx;
                }
                else if(dp_subsequence[curr_idx] == dp_subsequence[prev_idx] + 1){
                    
                    std::vector<ll> s1 = reconstruct(values,dp_last_item,curr_idx);
                    std::vector<ll> s2 = reconstruct(values,dp_last_item,prev_idx);
                    s2.push_back(values[curr_idx]);
                    
                    //std::cout << "s1: "; printArray(s1);
                    //std::cout << "s2: "; printArray(s2);
                    
                    if(s2 < s1){
                        dp_last_item[curr_idx] = prev_idx;
                        //std::cout << "winner: s1" << std::endl;
                    }
                    
                }
                
            }
            
        }
    }
}

void solve(){
    
    ll n_values;
    while(std::cin >> n_values && n_values != 0){
        
        std::vector<ll> values(n_values);
        for(ll curr_value_idx = 0; curr_value_idx < n_values; curr_value_idx++){
            std::cin >> values[curr_value_idx];
            
        }
        
        // dp que mantiene guardado el valor de la subsequence mas grande en el index i
        std::vector<ll> dp_subsequence(values.size(), 1);
        // dp que mantiene el ultimo item para forma la subsequencia en el index i
        std::vector<ll> dp_last_item(values.size(),-1);
        
        longestIncreasingSubsequence(values, dp_subsequence, dp_last_item);
        
        ll max_len = 0;
        for(ll curr_idx = 0; curr_idx < values.size(); curr_idx++){
            if( dp_subsequence[curr_idx] > max_len){max_len = dp_subsequence[curr_idx];}
        }
        
        std::vector<ll> LIS;
        bool first = true;
        
        for(ll curr_idx = 0; curr_idx < values.size(); curr_idx++){
            if(dp_subsequence[curr_idx] == max_len){
                std::vector<ll> curr_LIS = reconstruct(values,dp_last_item,curr_idx);
                if(first || curr_LIS < LIS ){
                    LIS = curr_LIS;
                    first = false;
                }
            }
        }
        
        std::cout << LIS.size() << " ";
        for(ll curr_idx = 0; curr_idx < LIS.size(); curr_idx++){
            std::cout << LIS[curr_idx];
            if(curr_idx != LIS.size()-1){std::cout << " ";}
        }
        std::cout << std::endl;
        
    }
    
}

int main(){
    optimize();
    solve();
    return 0;
}