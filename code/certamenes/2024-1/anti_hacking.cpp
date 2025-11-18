/** Problem Statement
D. Anti-Hacking
time limit per test
3 seconds
memory limit per test
256 megabytes

Sebastián necesita crear una contraseña para la cuenta de vjudge que controla los listados de problemas problemas del 
curso de Algoritmos y Complejidad. Sin embargo, está preocupado porque sabe que existe un programa malicioso llamado Brute Forcetor 3000, 
diseñado para descifrar contraseñas mediante fuerza bruta. Debido a sus optimizaciones e "inteligencia", 
el software tiene problemas con contraseñas que tienen ciertas características. 

Las características de las contraseñas "fuertes" para Brute Forcetor 3000 son las siguientes:

    Si el conjunto tiene letras repetidas, éstas nunca estarán presentes de forma consecutiva en la contraseña.
    La contraseña no debe comenzar por el caracter lexicográficamente menor.
    La contraseña debe usar todos los caracteres del conjunto. 

Por ejemplo, si Brute Forcetor 3000 utiliza el conjunto de letras {b, c, d, b}, generaría todas las palabras débiles. 
Esto es todas las posibles secuencias con esos caracteres, exceptuando:


    cbdb
    dbcb

Sebastián sabe que su contraseña debe ser fuerte para Brute Forcetor 3000 
y quiere saber cuántas contraseñas seguras se pueden formar con un conjunto de letras que ha escogido, 
entre las que incluirá su letra favorita. 
Por eso, ha decidido usar el Torneo Sansano de Programación para obtener un programa que sirva a sus fines.

Input

La primera línea del input contiene un entero n (1 ≤ n ≤ 10), correspondiente a la cantidad de letras con las que 
Sebastián quiere probar Brute Forcetor 3000.

La segunda línea del input contiene n letras del alfabeto inglés separados por un espacio. Las letras podrían repetirse.
Output

Input 1:

4
b c d b

Output 2:

2

El output debe contener una única línea indicando cuántas constraseñas fuertes diferentes se pueden generar con el conjunto de letras de entrada.
 * @source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/D
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

bool checkStrong(std::string password, char first){
    
    // si la contraseña es la misma
    if(password[0] == first){
        return false;
    }
    
    // chequear dos continuos
    for(int curr_idx = 0; curr_idx<password.size()-1; curr_idx++){
        
        if(password[curr_idx] == password[curr_idx+1]){
            return false;
        }
        
    }
    
    return true;
    
}

void solve(){
    
    ll n_letras;
    std::cin >> n_letras;
    
    std::string letras;
    for(int curr_idx = 0; curr_idx < n_letras; curr_idx++){
        char input;
        std::cin >> input;
        letras.push_back(input);
    }
    
    std::sort(letras.begin(), letras.end());
    
    char min_char = letras[0];
    
    ll fuertes = 0;
    
    do{
        
        if(checkStrong(letras,min_char)){
            fuertes++;
        }
        
    }while(std::next_permutation(letras.begin(), letras.end()));
    
    std::cout << fuertes << std::endl;
    
}

int main(){
    optimize();
    solve();
    return 0;
}