/*
Staying fit is important for every super hero, and Spiderman is no exception. 
Every day he undertakes a climbing exercise in which he climbs a certain distance, rests for a minute, then climbs again, rests again, and so on. 
The exercise is described by a sequence of distances d1,d2,…,dmd1​,d2​,…,dm​ 
telling how many meters he is to climb before the first first break, before the second break, and so on. 

From an exercise perspective it does not really matter if he climbs up or down at the ii:th climbing stage, 
but it is practical to sometimes climb up and sometimes climb down so that he both starts and finishes at street level. 
Obviously, he can never be below street level. Also, he would like to use as low a building as possible 
(he does not like to admit it, but he is actually afraid of heights). 

The building must be at least 2 meters higher than the highest point his feet reach during the workout.

He wants your help in determining when he should go up and when he should go down.
 The answer must be legal: it must start and end at street level (0 meters above ground) and it may never go below street level. 
 Among the legal solutions he wants one that minimizes the required building height. When looking for a solution, you may not reorder the distances.

If the distances are 20 20 20 20 he can either climb up, up, down, down or up, down, up, down. 
Both are legal, but the second one is better (in fact optimal) because it only requires a building of height 22, whereas the first one requires a building of height 42. If the distances are 3 2 5 3 1 2, an optimal legal solution is to go up, up, down, up, down, down. Note that for some distance sequences there is no legal solution at all (e.g., for 3 4 2 1 6 4 5).

Input

The first line of the input contains an integer NN giving the number of test scenarios, 1≤N≤1011≤N≤101. 
The following 2N2N lines specify the test scenarios, two lines per scenario: 
the first line gives a positive integer M≤40M≤40 which is the number of distances, and the following line contains the MM positive integer distances. 
For any scenario, the total distance climbed (the sum of the distances in that scenario) is at most 1000.

Output

For each input scenario a single line should be output. This line should either be the string “IMPOSSIBLE” if no legal solution exists, or it should be a string of length MM containing only the characters “U” and “D”, where the ii:th character indicates if Spiderman should climb up or down at the ii:th stage. If there are several different legal and optimal solutions, output one of them (it does not matter which one as long as it is optimal).

Sample 1

Input

3
4
20 20 20 20
6
3 2 5 3 1 2
7
3 4 2 1 6 4 5

Output

UDUD
UUDUDD
IMPOSSIBLE

* @source: https://vjudge.net/contest/761487#problem/D
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

#define CLIMB_UP true
#define CLIMB_DOWN false

#define MAX_HEIGHT 1000

std::string testcase(std::vector<ll> &distances){
    
    std::vector<std::vector<ll>> dp_min_jumps(MAX_HEIGHT+1, std::vector<ll>(distances.size()+1, LLONG_MAX)); // dp[altura][estado salto]
    std::vector<std::vector<bool>> dp_directions(MAX_HEIGHT+1, std::vector<bool>(distances.size()+1, CLIMB_DOWN));
    
    // Caso base:

    dp_min_jumps[0][0] = 0; // En 0 de altura, con ningun salto, te quedas en 0

    // Iteración

    for(ll curr_distance_idx = 1; curr_distance_idx <= distances.size(); curr_distance_idx++){

        ll curr_distance = distances[curr_distance_idx-1];

        for(ll curr_height = 0; curr_height <= MAX_HEIGHT; curr_height++){

            if(dp_min_jumps[curr_height][curr_distance_idx-1] == LLONG_MAX){continue; } // Si no se pudo llegar desde el paso anterior, no seguir

            // Caso para arriba
            ll new_height = curr_height + curr_distance;
            if(new_height <= MAX_HEIGHT){

                ll posssible_height = std::max(dp_min_jumps[curr_height][curr_distance_idx-1], new_height);

                if(dp_min_jumps[new_height][curr_distance_idx] > posssible_height){
                    dp_min_jumps[new_height][curr_distance_idx] = posssible_height;
                    dp_directions[new_height][curr_distance_idx] = CLIMB_UP;
                }

            }

            // Caso para abajo
            new_height = curr_height - curr_distance;
            if(new_height >= 0){

                ll posssible_height = dp_min_jumps[curr_height][curr_distance_idx-1];

                if(dp_min_jumps[new_height][curr_distance_idx] > posssible_height){
                    dp_min_jumps[new_height][curr_distance_idx] = posssible_height;
                    dp_directions[new_height][curr_distance_idx] = CLIMB_DOWN;
                }

            }

        }

    }

    // Resultado

    if(dp_min_jumps[0][distances.size()] == LLONG_MAX){return "IMPOSSIBLE"; }

    // Reconstrucción

    std::string result;
    ll curr_height = 0;

    for(ll curr_distance_idx = distances.size(); curr_distance_idx >= 1; curr_distance_idx--){
        ll dist = distances[curr_distance_idx-1];
        
        bool move = dp_directions[curr_height][curr_distance_idx];

        if(move == CLIMB_UP){
            result.push_back('U');
            curr_height -= dist; 

        }
        else {
            result.push_back('D');
            curr_height += dist;
        }

    }

    std::reverse(result.begin(), result.end());

    return result;
    
}

void solve(){
    
    ll N_testcases;
    std::cin >> N_testcases;
    
    for(ll curr_testcase = 0; curr_testcase < N_testcases; curr_testcase++){
        
        ll M_distances;
        std::cin >> M_distances;
        
        std::vector<ll> distances(M_distances);
        for(ll curr_distance = 0; curr_distance < M_distances; curr_distance++){ std::cin >> distances[curr_distance]; }
        
        std::cout << testcase(distances) << std::endl;
        
    }
    
}
int main(){
    optimize();
    solve();
    return 0;
}