/**

La Gran Competencia Profesional de Gato organizada por la UTFSM fue un gran éxito, con más de 831, 361 participantes. 
El Gato es un juego de dos jugadores, donde uno usa el símbolo X y el otro O, alternando turnos para colocar sus símbolos en una cuadrícula 
de 3 × 3. El objetivo es alinear tres símbolos consecutivos, ya sea en fila, columna o diagonal.

Si un jugador lo consigue, es declarado ganador; si todas las casillas se llenan sin un ganador, el juego termina en empate.

Dado el gran número de jugadores, el juez tiene dificultades para revisar manualmente cada partido y determinar al ganador. 
Tu tarea es crear un programa que, al recibir una partida de Gato TERMINADA y VÁLIDA, determine si ganó el jugador de X, el de O, 
o si el juego terminó en empate.
Input

El input consiste en tres líneas, donde cada una contiene tres carácteres. Cada carácter puede tener valor X, O o -.

    X indica que en la casilla jugó el jugador que usa el símbolo X
    O indica que en la casilla jugó el jugador que usa el símbolo O
    - indica que ningún jugador uso su símbolo en esa casilla. 

Output

El output debe contener la palabra X si es que ganó el jugador que usa el símbolo X, 
O si es que ganó el jugador que usa el símbolo O, - en caso de empate.

 * @source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/H
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

bool charWon(std::vector<std::vector<char>> &result, char player){
    
    if(player == result[0][0] && result[0][0] == result[0][1] && result[0][1] == result[0][2]){return true;}
    if(player == result[1][0] && result[1][0] == result[1][1] && result[1][1] == result[1][2]){return true;}
    if(player == result[2][0] && result[2][0] == result[2][1] && result[2][1] == result[2][2]){return true;}
    
    if(player == result[0][0] && result[0][0] == result[1][0] && result[1][0] == result[2][0]){return true;}
    if(player == result[0][1] && result[0][1] == result[1][1] && result[1][1] == result[2][1]){return true;}
    if(player == result[0][2] && result[0][2] == result[1][2] && result[1][2] == result[2][2]){return true;}
    
    if(player == result[0][0] && result[0][0] == result[1][1] && result[1][1] == result[2][2]){return true;}
    if(player == result[0][2] && result[0][2] == result[1][1] && result[1][1] == result[2][0]){return true;}
    
    return false;
}

void solve(){
    
    std::vector<std::vector<char>> result(3,std::vector<char>(3));
    
    for(int col_idx = 0; col_idx<3; col_idx++){
        for(int fil_idx = 0; fil_idx<3; fil_idx++){
            
            std::cin >> result[col_idx][fil_idx];
            
        }
    }
    
    if(charWon(result,'X')){std::cout << 'X';}
    else if(charWon(result,'O')){std::cout << 'O';}
    else{std::cout << '-';}
    
    
}

int main(){
    optimize();
    solve();
    return 0;
}