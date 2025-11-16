/** Problem Statement

## Input

The input consists of several test cases.
Each test case starts with a line with four non-negative integers, $1 \le n \le 1000$, $0 \le m \le 5000$, $1 \le q \le 100$ and $0 \le s < n$, separated by single spaces, 
where $n$ is the numbers of nodes in the graph, $m$ the number of edges, $q$ the number of queries and the index of the starting node. Nodes are numbered from $0$ to $n-1$. 
Then follow $m$ lines, each line consisting of three (space-separated) integers $u$, $v$ and $w$ indicating that there is an edge from $u$ to $v$ 
in the graph with weight $-2000 \le w \le 2000$. 
Then follow $q$ lines of queries, each consisting of a single non-negative integer, asking for the minimum distance from node $s$ to the node number given on the query line.

Input will be terminated by a line containing four zeros, this line should **not** be processed.

---

## Output

For each query, output a single line containing the minimum distance from node $s$ to the node specified in the query, 
the word **“Impossible”** if there is no path from $s$ to that node, 
or **“-Infinity”** if there are arbitrarily short paths from $s$ to that node. 
For clarity, the sample output has a blank line between the output for different cases.

---

## Sample 1

5 4 3 0
0 1 999
1 2 -2
2 1 1
0 3 2
1
3
4
2 1 1 0
0 1 -100
1
0 0 0 0

Output 1

-Infinity
2
Impossible

-100

* @source: https://vjudge.net/contest/761487#problem/G
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

#define INF LLONG_MAX

struct Edge{
    
    ll node_u;
    ll node_v;
    ll weight;
    
};

void bellman_algorithm(ll n_nodes, ll start_node, std::vector<Edge> &edges, std::vector<ll> &dp_distances, std::vector<bool> &dp_negative_loop){
    
    // Caso base: nodo inicial tiene distancia 0
    
    dp_distances[start_node] = 0;
    
    // Iterar n-1 veces para calcular distancias
    
    for(ll curr_iteration = 0; curr_iteration < n_nodes - 1; curr_iteration++){
        
        for(ll curr_edge_idx = 0; curr_edge_idx < edges.size(); curr_edge_idx++){
            
            Edge curr_edge = edges[curr_edge_idx];
            
            // Si se alcanzo el nodo inicial u
            
            if(dp_distances[curr_edge.node_u] != INF){
                
                // Entonces es calculable el camino a seguir
                
                dp_distances[curr_edge.node_v] = std::min(dp_distances[curr_edge.node_v], dp_distances[curr_edge.node_u] + curr_edge.weight);
                
            } 
            
        }
        
    }
    
    // Iterar n-1 veces para encontrar posibles loops negativos
    
    for(ll curr_edge_idx = 0; curr_edge_idx < edges.size(); curr_edge_idx++){
        
        Edge curr_edge = edges[curr_edge_idx];
        
        if(dp_distances[curr_edge.node_u] != INF){
            
            // Checkea si al acceder al nodo baja nuevamente de valor. Indica loop negativo
            if(dp_distances[curr_edge.node_u] + curr_edge.weight < dp_distances[curr_edge.node_v]){
                
                dp_negative_loop[curr_edge.node_v] = true;
                
            }
            
        }
        
        if(dp_negative_loop[curr_edge.node_u]){
                dp_negative_loop[curr_edge.node_v] = true;
        }
        
    }
    
    for(ll curr_iteration = 0; curr_iteration < n_nodes; curr_iteration++){ // N times propagation
        for(ll curr_edge_idx = 0; curr_edge_idx < edges.size(); curr_edge_idx++){
        
            Edge curr_edge = edges[curr_edge_idx];
            
            if(dp_negative_loop[curr_edge.node_u]){dp_negative_loop[curr_edge.node_v] = true; }
            
        }
    }
}

void solve(){
    
    ll n_nodes, m_edges, q_queries, s_start_node;
    while(std::cin >> n_nodes >> m_edges >> q_queries >> s_start_node){
        
        if(n_nodes == 0 && m_edges == 0 && q_queries == 0 && s_start_node == 0) {break; }
        
        std::vector<Edge> edges(m_edges);
        for(ll curr_edge_idx = 0; curr_edge_idx < m_edges; curr_edge_idx++){
            
            std::cin >> edges[curr_edge_idx].node_u >> edges[curr_edge_idx].node_v >> edges[curr_edge_idx].weight; 
            
        }
        
        std::vector<ll> dp_distances(n_nodes,INF); // dp de distancias para el nodo
        std::vector<bool> dp_negative_loop(n_nodes, false); // dp para indicar un nodo con loop negativo
        
        bellman_algorithm(n_nodes,s_start_node,edges,dp_distances,dp_negative_loop);
        
        for(ll curr_querie_idx = 0; curr_querie_idx < q_queries; curr_querie_idx++){
            
            ll curr_querie;
            std::cin >> curr_querie;
            
            if(dp_distances[curr_querie] == INF){std::cout << "Impossible" << std::endl; } // Es imposible llegar
            else if(dp_negative_loop[curr_querie]) {std::cout << "-Infinity" << std::endl; } // Hay loop negativo
            else{ std::cout << dp_distances[curr_querie] << std::endl;}
            
        }
        
        std::cout << std::endl;
        
    }
    
}


int main(){
    solve();
    return 0;
}
