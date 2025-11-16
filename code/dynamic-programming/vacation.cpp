/** Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of
N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the

i-th day:

    A: Swim in the sea. Gain 

ai​ points of happiness.
B: Catch bugs in the mountains. Gain
bi​ points of happiness.
C: Do homework at home. Gain

    ci​ points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.
Constraints

    All values in input are integers.

1≤N≤105

    1≤ai​,bi​,ci​≤104

Input

Input is given from Standard Input in the following format:

N

a1​ 

b1​ 

c1​

a2​ 

b2​ 

c2​

:

aN​ 

bN​ 

cN​

Output

Print the maximum possible total points of happiness that Taro gains.
Sample Input 1
Copy

3
10 40 70
20 50 80
30 60 90

Sample Output 1
Copy

210

If Taro does activities in the order C, B, C, he will gain

70+50+90=210 points of happiness.
Sample Input 2
Copy

1
100 10 1

Sample Output 2
Copy

100

Sample Input 3
Copy

7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1

Sample Output 3
Copy

46

Taro should do activities in the order C, A, B, A, C, B, A.
 * @source: https://atcoder.jp/contests/dp/tasks/dp_c
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

#define A_INDEX 0
#define B_INDEX 1
#define C_INDEX 2

struct DayActivity{
    ll A;
    ll B;
    ll C;
};

/**
 * Realiza el Dynamic programming al problema utilizando tabulación
 * 
 * @param activities Vector con las actividades de los dias
 * @param dp Vector que representa la tabulacion del dp
 * 
 * @return Valor maximo obtenido
 */
ll tabulation(std::vector<DayActivity> &activities, std::vector<std::vector<ll>> &dp){
    
    dp[0][A_INDEX] = 0;
    dp[0][B_INDEX] = 0;
    dp[0][C_INDEX] = 0;
    
    for(ll i=1; i<=activities.size(); i++){
        
        dp[i][A_INDEX] = activities[i-1].A + std::max(dp[i-1][B_INDEX], dp[i-1][C_INDEX]);
        dp[i][B_INDEX] = activities[i-1].B + std::max(dp[i-1][A_INDEX], dp[i-1][C_INDEX]);
        dp[i][C_INDEX] = activities[i-1].C + std::max(dp[i-1][A_INDEX], dp[i-1][B_INDEX]);
        
    }
    
    return std::max({dp[activities.size()][A_INDEX],dp[activities.size()][B_INDEX],dp[activities.size()][C_INDEX]});
    
}

/**
 * Realiza la lectura del testcase
 * 
 */
void testcase(){
    
    ll N_DAYS;
    std::cin >> N_DAYS;
    
    std::vector<DayActivity> activities(N_DAYS);
    for(ll i=0; i<N_DAYS; i++){std::cin >> activities[i].A >> activities[i].B >> activities[i].C; }
    
    std::vector<std::vector<ll>> dp(N_DAYS+1, std::vector<ll>(3,0));
    std::cout << tabulation(activities,dp) << std::endl;
    
}

int main(){
    optimize();
    testcase();
    return 0;
}