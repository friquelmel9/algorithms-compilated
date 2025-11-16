/** Problem Statement

There is a grid with
H horizontal rows and W vertical columns. Let (i,j) denote the square at the i-th row from the top and the

j-th column from the left.

For each
i and j (1≤i≤H, 1≤j≤W), Square (i,j) is described by a character ai,j​. If ai,j​ is ., Square (i,j) is an empty square; if ai,j​ is #, Square (i,j) is a wall square. It is guaranteed that Squares (1,1) and

(H,W) are empty squares.

Taro will start from Square
(1,1) and reach

(H,W) by repeatedly moving right or down to an adjacent empty square.

Find the number of Taro's paths from Square
(1,1) to (H,W). As the answer can be extremely large, find the count modulo

109+7.
Constraints

H and
W are integers.
2≤H,W≤1000
ai,j​ is . or #.
Squares
(1,1) and (H,W) are empty squares.

Input

nput is given from Standard Input in the following format:

H W

a1,1​ … a1,W​
:
aH,1​ … aH,W​

Output

Print the number of Taro's paths from Square (1,1) to (H,W), modulo 10^9+7

Sample Input 1

3 4
...#
.#..
....

Sample output 1

3

Sample Input 2

5 2
..
#.
..
.#
..

Sample Output 2

0

Sample Input 3

5 5
..#..
.....
#...#
.....
..#..

Sample Output 3

24

Sample Input 4

20 20
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................


Sample Output 4

345263555

* @source: https://atcoder.jp/contests/dp/tasks/dp_h
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

const int MOD = 1e9+7;

/**
 * Resuelve el problema de grid1
 */
void solve(){
    
    int H_height, W_width;
    std::cin >> H_height >> W_width;
    
    std::set<std::pair<int,int>> wall_squares_pos;
    char block;
    
    for(int y=1; y <= H_height; y++){
        for(int x=1; x <= W_width; x++){
            std::cin >> block;
            if(block == '#'){wall_squares_pos.insert({x,y});}
        }
    }
    
    // Dp mantiene cantidad de rutas que llegan a la posición.
    std::vector<std::vector<int>> dp(W_width+1, std::vector<int>(H_height+1,0));
    
    // Caso base, desde la posición inicial (1,1) tengo una forma de llegar aqui (Ya estoy ahi)
    dp[1][1] = 1;
    
    // Iteraciones:
    // Se comparara con el elemento de abajo o a la derecha, dado que el destino es a la derecha.
    for(int x = 1; x <= W_width; x++ ){
        for(int y = 1; y <= H_height; y++){
            
            // Si es que no es una pared
            if(wall_squares_pos.find({x,y}) == wall_squares_pos.end()){
                
                // Guardo las maneras que se tuvieron de llegar a los bloques anteriores o la actual.
                dp[x][y] = std::max( (dp[x][y-1] + dp[x-1][y]) % MOD, dp[x][y]);
                
            }
            
        }
    }
    
    std::cout << dp[W_width][H_height];
}

int main(){ 
    optimize();
    solve();
    return 0;
}