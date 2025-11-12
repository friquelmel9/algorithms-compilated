/* Problem Statement
In a few weeks time, a new president will be elected in the country of Marecia.
There are two political parties: the Constituents and the Federals.
Each party has one presidential candidate; one of these will become the new president.

This year you are more involved than ever before: you are the candidate for the Constituents! 
With only a few weeks to go, you decide to take stock of the situation. 
Instead of touring blindly through the country, you feel that it is better to focus your attention on certain particular states.

The Marecian electoral system is quite complicated. 
Every registered voter will vote for exactly one of the two candidates, but the totals are not calculated nationwide. 
Instead, every state has a fixed number of delegates. 
After the popular vote is in, the delegates from all states travel by foot to the capital of Marecia, the city of Ashwington. 
One final round of voting is done in Ashwington: every delegate gets to vote for one of the two candidates. 
A delegate is required by law to vote for the candidate who received the majority of the votes in his own home state.

Your campaign team has painstakingly compiled a very accurate list of voting preferences per state. 
Therefore you now have the following information about every state:

    The number of voters who will definitely vote for the Constituents;

    The number of voters who will certainly vote for the Federals;

    The number of voters who have not made up their minds yet.

Voters from the first two categories are not susceptible to any further campaigning, so your focus for the remaining weeks is on people of the third category. 
Specifically, you would like to know the minimum number of people you still have to convince in order to secure a victory.

If there is a tie on either state or national level, the law states that it is resolved in favour of the oldest of the two political parties, 
which unfortunately is the Federal party.

Input

The first line contains a single integer S, the number of states.

The following SS lines each contain four integers Di​, Ci​, Fi​, Ui​, where

    Di​ denotes the number of delegates for the i-th state,

    Ci​ denotes the number of registered voters in the i-th state who will definitely vote for the Constituents,

    Fi​ denotes the number of registered voters in the i-th state who will certainly vote for the Federals,

    Ui​ denotes the number of undecided voters in the i-th state.

There are at most 2016 delegates in total, and the total number of registered voters is at most 10^9. 
Every state has at least one delegate and at least one registered voter. 
There is at least one state.

Output

Output one line with a single integer: the minimum number of voters you have to convince to secure a victory. 
If it is not possible for you to win the election, output “impossible” instead.

Sample 1

Input:

3
7 2401 3299 0
6 2401 2399 0
2 750 750 99

Output:

50

Sample 2

Input:

3
7 100 200 200
8 100 300 200
9 100 400 200

Output:

impossible

Sample 3:

Input:

3
32 0 0 20
32 0 0 20
64 0 0 41

Output:

32

 * @source https://vjudge.net/contest/761487#problem/C
*/

#include <bits/stdc++.h>

#define ll long long 


struct State {
    
    ll delegates;
    ll needed_votes;
    ll possible_votes; // unknoknw votes
    
};

/**
 * @param states Vector con todos los estados
 * @param dp Vector para programación dinamica. Guarda los valores de votos necesarios para una cantidad x de delegados
 * @param min_delegates_to_win Cantidad minima de delegados para ganar
 * 
 * @return La cantidad de votos necesarios para ganar. LLONG_MAX indica imposible
 */
ll tabulation(std::vector<State> states, std::vector<ll> &dp, ll min_delegates_to_win){
    
    dp[0] = 0; // Caso base: Necesito 0 votos para conseguir 0 delegados
    
    for(ll curr_state = 0; curr_state < states.size(); curr_state++){
        
        if(states[curr_state].needed_votes > states[curr_state].possible_votes) {continue; }
        
        ll curr_state_needed_votes =  states[curr_state].needed_votes;
        ll curr_state_delegates = states[curr_state].delegates;
        
        for(ll curr_delegates = dp.size()-1; curr_delegates >= curr_state_delegates ; curr_delegates--){
            
            if(dp[curr_delegates-curr_state_delegates] == LLONG_MAX){ continue; }
            
            // Estado actual: Revisar la cantidad minima de votos necesarios
            
            dp[curr_delegates] = std::min(dp[curr_delegates], dp[curr_delegates-curr_state_delegates] + curr_state_needed_votes);
            
        }
    }
    
    return *std::min_element(dp.begin()+min_delegates_to_win, dp.end());
    
}

/**
 * Resuelve el problema de Presidential Elections
 */
void solve(){
    
    ll S_states;
    std::cin >> S_states;
    
    ll total_delegates = 0;
    std::vector<State> states(S_states);
    
    for(ll curr_state = 0; curr_state<S_states; curr_state++){
        
        ll delegates, constituents, federals, unknown;
        std::cin >> delegates >> constituents >> federals >> unknown; 
        
        ll needed_votes = (constituents+federals+unknown)/2 + 1;
        
        // Minima cantidad de votos para ganar
        
        states[curr_state] = {delegates, std::max(0LL, needed_votes-constituents), unknown};
        total_delegates += delegates;
        
    }
    
    ll min_delegates_to_win = total_delegates/2+1;
    
    // dp: Guarda la cantidad de delegados totales. Sirve para ver los votos necesarios para una cantidad de delegados
    // LLONG MAX para indicar que no hay cantidad de votos para conseguir aquel cantidad de delegados
    std::vector<ll> dp(total_delegates+1,LLONG_MAX);
    ll result = tabulation(states,dp,min_delegates_to_win);
    
    if(result != LLONG_MAX){std::cout << result; }
    else{ std::cout << "impossible";  }
    
}

int main(){
    solve();
    return 0;
}