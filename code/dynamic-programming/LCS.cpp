/* Problem Statement

You are given strings
s and t. Find one longest string that is a subsequence of both s and

t.
Notes

A subsequence of a string
x is the string obtained by removing zero or more characters from

x and concatenating the remaining characters without changing the order.
Constraints

s and
t are strings consisting of lowercase English letters.

    1≤∣s∣,∣t∣≤3000

Input

Input is given from Standard Input in the following format:

s

t

Output

Print one longest string that is a subsequence of both
s and

t. If there are multiple such strings, any of them will be accepted.
Sample Input 1

axyb
abyxb

Sample Output 1

axb

The answer is axb or ayb; either will be accepted.
Sample Input 2

aa
xayaz

Sample Output 2

aa

Sample Input 3

a
z

Sample Output 3

The answer is (an empty string).
Sample Input 4

abracadabra
avadakedavra

Sample Output 4

aaadara

 * @source https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

/**
 * 
 */
std::string reconstruct(std::string &S_string, std::string &T_string, std::vector<std::vector<ll>>& dp){
    
    ll i = S_string.size();
    ll j = T_string.size();
    std::string result = "";
    
    while(i > 0 && j > 0){
        if(S_string[i-1] == T_string[j-1]){ 
            result.push_back(S_string[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]){ i--; }
        else{ j--; }
        
    }
    
    std::reverse(result.begin(), result.end());
    return result;
    
}

/**
 * 
 */
void tabulation(std::string &S_string, std::string &T_string, std::vector<std::vector<ll>>& dp){
    
    // Ignorable, dado que dp inicio con valores 0.
    dp[S_string.size()][0] = 0;
    dp[0][T_string.size()] = 0;
    
    for(ll i=1; i <= S_string.size(); i++){
        for(ll j=1; j <= T_string.size(); j++){
            
            if(S_string[i-1] == T_string[j-1]){ dp[i][j] = dp[i-1][j-1] + 1; }
            else{ dp[i][j] = std::max( dp[i-1][j], dp[i][j-1]); }
        }
    }
}

void testcase(){
    
    std::string S_string;
    std::string T_string;
    
    std::cin >> S_string >> T_string;
    
    std::vector<std::vector<ll>> dp(S_string.size()+1, std::vector<ll>(T_string.size()+1,0));
    tabulation(S_string,T_string,dp);
    std::cout << reconstruct(S_string,T_string,dp);

}

int main(){
    testcase();
    return 0;
}