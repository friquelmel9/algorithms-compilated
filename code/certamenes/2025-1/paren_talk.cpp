/** Problem Statement
E. ParenTalk
time limit per test
1 second
memory limit per test
256 megabytes

En la plataforma de mensajería ParenTalk, los usuarios expresan sus emociones utilizando únicamente dos caracteres: "(" para sorpresa y ")" para alivio. Una secuencia de estos caracteres se denomina emoticón. Para que un emoticón transmita correctamente una emoción, la secuencia debe estar correctamente balanceada (1).

Sin embargo, a veces los emoticones llegan desbalanceados, lo que dificulta interpretar la emoción transmitida. Para mejorar la interfaz, el equipo de desarrollo desea detectar, dentro de cada emoticón, la subcadena contigua (2) más larga que constituya un emoticón correctamente balanceado; es decir, una secuencia que transmita adecuadamente una emoción.

(1) Una secuencia correctamente balanceada de "(" y ")" es una combinación de paréntesis donde cada paréntesis de apertura "(" tiene un paréntesis de cierre ")" correspondiente, y el orden es el adecuado.

Ejemplos válidos (balanceados):

    "()"
    "(())"
    "(()())" 

Ejemplos no válidos (desbalanceados):

    "(()"
    "())("
    ")" 

(2) Una subcadena contigua es una parte de un texto formada por caracteres consecutivos, sin omitir ninguno.

Por ejemplo, en el mensaje "(()())", algunas subcadenas contiguas son:

    "(()"
    "()()"
    "()" 

Input

La primera línea de la entrada contiene un entero n (1 ≤ n ≤ 100 000), correspondiente a la longitud del emoticón recibido.

La segunda línea contiene el emoticón recibido, de longitud n, formado únicamente por los caracteres "(" y ")".
Output

Imprime un único entero, correspondiente la longitud de la subcadena contigua más larga que sea un emoticón correctamente balanceado y que pueda transmitir la emoción de forma adecuada.

Input 1:

6
)()())

Output 1

4

Input 2

4
((((

Output 2

0

Input 3

8
)(()())(


Output 3

6
 * @source: https://codeforces.com/gym/615921/problem/E
 * @timecomplexity: O(n). Avanza por los n elementos en parenTalk
 * @spacecomplexity: O(n). Hay un vector n para parentesis, y en el peor de los casos, el stack mantendra como maximo n/2 elementos,,
 * lo cual es O(n/2) = O(n)
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

ll parenTalk(std::vector<char> parenthesis, ll n_size){
    
    std::stack<ll> state;
    state.push(-1); 
    
    ll max_valid = 0;
    
    for(ll curr_idx = 0;  curr_idx < n_size; curr_idx++){
        
        if(parenthesis[curr_idx] == '('){ // O(1)
            
            state.push(curr_idx); // O(1)
            
        }
        else { 
            
            state.pop();  // O(1)
            
            if(state.empty()){
                state.push(curr_idx);
            }
            else {
                ll current_length = curr_idx - state.top();
                max_valid = std::max(max_valid, current_length);
            }
        }
    }
    
    return max_valid;
}

void solve(){
    
    ll n_size;
    std::cin >> n_size;
    
    std::vector<char> parenthesis(n_size);
    for(ll curr_idx = 0; curr_idx < n_size; curr_idx++){
        std::cin >> parenthesis[curr_idx];
    }
    
    std::cout << parenTalk(parenthesis, n_size);
    
}

int main(){
    optimize()
    solve();
    return 0;
}

