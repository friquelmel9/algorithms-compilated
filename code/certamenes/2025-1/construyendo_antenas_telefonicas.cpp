/**
Una famosa empresa de telecomunicaciones se ha contactado con los alumnos de Algoritmos para resolver
un problema vital. 

Deben construir antenas telefónicas para comunicar a la mayor cantidad de personas
posibles, sin embargo, no saben como hacerlo. 

En particular, se tienen n ciudades donde cada una de estás
tiene una población pi para 0 ≤ i < n, se pueden construir antenas telefónicas en cualquier ciudad, sin
embargo, no lo pueden hacer en ciudades adyacentes por temas legales. 

Además, cada antena es capaz de
proporcionar señal a la ciudad en donde es construida. Por ahora a la empresa les interesa saber la máxima
cantidad de personas que pueden comunicar.

Input

La entrada comienza con un entero n que indica el número de ciudades (1 ≤ n ≤ 10^5 ).
En la lı́nea siguiente, le siguen n enteros separados por espacio que representan las poblaciones de cada
ciudad (1 ≤ pi ≤ 10^7 ).

Output

Imprime un único entero que indica la maxima cantidad de personas que se pueden comunicar.

 * @source: https://codeforces.com/gym/615921/problem/D
 * @timecomplexity: O(n). Revisa las n ciudades para maximizar las antenas
 * @spacecomplexity: O(n). Se crea un arreglo dp_poblacion de tamaño n mas un poblacion de tamaño n. O(n+n) = O(n)
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

ll maximize_antenas(std::vector<ll> &poblacion, ll n_cities){
    
    std::vector<ll> dp_poblacion(n_cities+1, 0);
    
    // Caso base: cada ciudad empieza con 0, al asumir que no robaba
    
    dp_poblacion[0] = 0;
    dp_poblacion[1] = std::max(dp_poblacion[0], dp_poblacion[1]+poblacion[0]);
    
    
    for(ll curr_city = 2; curr_city <= n_cities; curr_city++){
        
        ll prev_city = curr_city - 1;
        
        dp_poblacion[curr_city] = std::max(dp_poblacion[prev_city], dp_poblacion[curr_city-2] + poblacion[curr_city-1]);
        
    }
    
    return dp_poblacion[n_cities];
    
}

void solve(){
    
    ll n_cities;
    std::cin >> n_cities;
    
    std::vector<ll> poblacion(n_cities);
    for(ll curr_city = 0; curr_city < n_cities; curr_city++){
        std::cin >> poblacion[curr_city];
    }
    
    std::cout << maximize_antenas(poblacion, n_cities) << std::endl;
    
}

int main(){
    optimize();
    solve();
    return 0;
}