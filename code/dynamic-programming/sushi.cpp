/**
 * Problem Statement:
 * @source: https://atcoder.jp/contests/dp/tasks/dp_j
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

#define vvvfloat std::vector<std::vector<std::vector<float>>>
#define NOTCALCULATED -1

float markov_sushi(std::unordered_map<int,int>& sushi_pieces, int n_plates){
    
    int start_one_plates = sushi_pieces[1];
    int start_two_plates = sushi_pieces[2];
    int start_three_plates = sushi_pieces[3];
    
    // Dp[c1][c2][c3]: Cantidad expectante de valores para cambiar de estado
    // c1 indica cantidad de platos que les queda una pieza de sushi, y asi sucesivamente con c2 y c3
    
    vvvfloat dp_expected(n_plates+1, std::vector<std::vector<float>>(n_plates+1, std::vector<float>(n_plates+1, NOTCALCULATED)));
    
    // Caso base: Con 0 piezas de sushi restante en cada plato, la cantidad de pasos necesarios para terminar es 0
    
    dp_expected[0][0][0] = 0;
    
    // Iteraciones
    
    for(int c3 = 0; c3 <= n_plates; c3++){
        for(int c2 = 0; c2 <= n_plates; c2++){
            for(int c1 = 0; c1 <= n_plates; c1++){
                
                if(c1+c2+c3 > n_plates){ continue; } // Si la cantidad sobrestima el problema
                if(c1 == 0 && c2 == 0 && c3 == 0) { continue; } // No considerar caso base 
                
                int curr_plates = c1+c2+c3;
                
                float expected_value = 0.0;
                
                if(c1 >= 1){
                    expected_value += float(c1) * dp_expected[c1-1][c2][c3];
                }
                if(c2 >= 1){
                    expected_value += float(c2) * dp_expected[c1+1][c2-1][c3];
                }
                if(c3 >= 1){
                    expected_value += float(c3) * dp_expected[c1][c2+1][c3-1];
                }
                
                dp_expected[c1][c2][c3] = (n_plates+expected_value)/curr_plates;
                
            }
        }
    }
    
    return dp_expected[start_one_plates][start_two_plates][start_three_plates];
    
}

void solve(){
    
    int n_plates;
    std::cin >> n_plates;
    
    std::unordered_map<int,int> plates_sushi;
    plates_sushi[1] = 0;
    plates_sushi[2] = 0;
    plates_sushi[3] = 0;
    
    for(int i=0; i<n_plates; i++){
        int input;
        std::cin >> input;
        plates_sushi[input]++;
    }
    
    std::cout << markov_sushi(plates_sushi, n_plates) << std::endl;
    
}

int main(){
    optimize();
    solve();
    return 0;
}