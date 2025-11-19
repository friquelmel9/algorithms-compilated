/**
 * Problem Statement:
 * @source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/J
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

int calle_magica(std::string caracteres){
    
    // dp
    int n_baldosas = caracteres.size();
    
    std::vector<int> dp_distancias(n_baldosas, INT_MAX);
    std::unordered_map<char,int> min_chars;
    
    // caso base, desde la baldosa (caracter) inicial llego con 0 pasos
    
    dp_distancias[0] = 0;
    min_chars[caracteres[0]] = 0;
    
    for(int curr_idx = 1; curr_idx < n_baldosas; curr_idx++){
        
        char curr_char = caracteres[curr_idx];
        
        if(min_chars.find(curr_char) != min_chars.end()){
            //std::cout << "caso A: " << std::endl;
            dp_distancias[curr_idx] = std::min(min_chars[curr_char], dp_distancias[curr_idx-1]+1);
            
        }
        else{
            //std::cout << "caso B: " << std::endl;
            dp_distancias[curr_idx] = dp_distancias[curr_idx-1]+1;
            min_chars[curr_char] = dp_distancias[curr_idx];
            
        }
        
        if (dp_distancias[curr_idx] < min_chars[curr_char] || min_chars.find(curr_char) == min_chars.end()) {
            //std::cout << "Caso C: " << std::endl;
            min_chars[curr_char] = dp_distancias[curr_idx];
        }
        
        //std::cout << "curr idx (" << curr_idx << ") tiene letra (" << curr_char << "). Termina con distancia = " << dp_distancias[curr_idx] << std::endl;
        
        //std::cout << "valores diccionario: " << std::endl;
        //for(auto car_val : min_chars){
            //std::cout << "Letra: " << car_val.first << " = " << car_val.second << std::endl;
        //}
    }
    
    return dp_distancias[n_baldosas-1];
    
}

void solve(){
    
    std::string caracteres;
    std::cin >> caracteres;
    
    std::cout << calle_magica(caracteres) << std::endl;
    
}

int main(){
    optimize();
    solve();
    return 0;
}