/**
 * Problem Statement:
 * @source: https://atcoder.jp/contests/dp/tasks/dp_i
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long
#define ld long double

ld calculate_probabilites(std::vector<ld> heads_p, int n_coins){
    
    // Dp[cantidad de monedas lanzadas][salga h heads]
    
    std::vector<std::vector<ld>> dp_heads(n_coins+1, std::vector<ld>(n_coins+1, 0.0));
    
    // Caso base: Con 0 monedas lanzadas, tengo 0 probabilidades de tener cualquier numero de heads
    // Esto lo hace el constructor
    // Luego, con 0 moendas, tengo 100 probabilidades de no tener heads
    dp_heads[0][0] = 1.0;
    
    // Iteraciones
    
    for(int curr_coin = 1; curr_coin <= n_coins; curr_coin++){
        
        ld curr_head_p = heads_p[curr_coin-1];
        ld curr_tail_p = 1.0 - curr_head_p;
        
        for(int curr_heads = 0; curr_heads <= n_coins; curr_heads++){
            
            // Caso A: Lanza la moneda `curr-coin` y sale cara
            if(curr_heads>0){
                dp_heads[curr_coin][curr_heads] += dp_heads[curr_coin-1][curr_heads-1] * curr_head_p;
            }
            
            // Caso B: Lanza la moneda`curr-coin` y sale cruz
            dp_heads[curr_coin][curr_heads] += dp_heads[curr_coin-1][curr_heads] * curr_tail_p;
            
        }
        
        
    }
    
    // Se retorna la cantidad para ganar, que es n/2. en caso de Impar (5) este deberia ser 2.5, o sea 3
    int heads_to_win = n_coins/2+1;
    ld total_probabilities = 0.0;
    
    for(int heads = heads_to_win; heads <= n_coins; heads++){
        total_probabilities += dp_heads[n_coins][heads];
    }
    
    std::cout << std::fixed << std::setprecision(10); // Ajustar a que salga con 10 decimales
    return total_probabilities;
    
}

void solve(){
    
    int n_coins;
    std::cin >> n_coins;
    
    std::vector<ld> heads_p(n_coins);
    for(int i=0; i<n_coins; i++){
        std::cin >> heads_p[i];
    }
    
    std::cout << calculate_probabilites(heads_p,n_coins);
    
}

int main(){
    optimize();
    solve();
    return 0;
}