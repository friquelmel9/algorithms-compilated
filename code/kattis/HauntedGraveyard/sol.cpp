/**Problem Statement
Tonight is Halloween and Scared John and his friends have decided to do something fun to celebrate the occasion: crossing the graveyard. Although Scared John does not find this fun at all, he finally agreed to join them in their adventure. Once at the entrance, the friends have begun to cross the graveyard one by one, and now it is the time for Scared John. He still remembers the tales his grandmother told him when he was a child. She told him that, on Halloween night, “haunted holes” appear in the graveyard. These are not usual holes, but they transport people who fall inside to some point in the graveyard, possibly far away. But the scariest feature of these holes is that they allow one to travel in time as well as in space; i.e., if you fall inside a “haunted hole”, you appear somewhere in the graveyard a certain time before (or after) you entered the hole, in a parallel universe otherwise identical to ours.

The graveyard is organized as a grid of W×HW×H cells, with the entrance in the cell at position (0,0)(0,0) and the exit at (W−1,H−1)(W−1,H−1). Despite the darkness, Scared John can always recognize the exit, and he will leave as soon as he reaches it, determined never to set foot anywhere in the graveyard again. On his way to the exit, he can walk from one cell to an adjacent one, and he can only head to the North, East, South or West. In each cell there can be either one gravestone, one “haunted hole”, or grass:

    If the cell contains a gravestone, you cannot walk over it, because gravestones are too high to climb.

    If the cell contains a “haunted hole” and you walk over it, you will appear somewhere in the graveyard at a possibly different moment in time. The time difference depends on the particular “haunted hole” you fell into, and can be positive, negative or zero.

    Otherwise, the cell has only grass, and you can walk freely over it.

He is terrified, so he wants to cross the graveyard as quickly as possible. And that is the reason why he has phoned you, a renowned programmer. He wants you to write a program that, given the description of the graveyard, computes the minimum time needed to go from the entrance to the exit. Scared John accepts using “haunted holes” if they permit him to cross the graveyard quicker, but he is frightened to death of the possibility of getting lost and being able to travel back in time indefinitely using the holes, so your program must report these situations.
\includegraphics{graveyard}
Figure 1: Sample graveyard

Figure 3 illustrates a possible graveyard (the second test case from the sample input). In this case there are two gravestones in cells (2,1)(2,1) and (3,1)(3,1), and a “haunted hole” from cell (3,0)(3,0) to cell (2,2)(2,2) with a difference in time of 00 seconds. The minimum time to cross the graveyard is 44 seconds, corresponding to the path:
\begin{equation*} (0,0) \xrightarrow [\text {1 sec}]{\text {East}} (1,0) \xrightarrow [\text {1 sec}]{\text {East}} (2,0) \xrightarrow [\text {1 sec}]{\text {East}} (3,0) \xrightarrow [\text {0 sec}]{\text {hole}} (2,2) \xrightarrow [\text {1 sec}]{\text {East}} (3,2) \end{equation*}

If you do not use the “haunted hole”, you need at least 55 seconds.

Note that the destination of a “haunted hole” may have the entrance to another “haunted hole”. In this situation, Scared John will enter the second hole as soon as he exits the first one.

Scared John will leave the graveyard as soon as he reaches the exit, even if he would be able to travel back in time by continuing walking through the graveyard.
Input

The input consists of several test cases (at most 2525). Each test case begins with a line containing two integers WW and HH (1≤W,H≤301≤W,H≤30). These integers represent the width WW and height HH of the graveyard. The next line contains an integer GG (G≥0G≥0), the number of gravestones in the graveyard, and is followed by GG lines containing the positions of the gravestones. Each position is given by two integers XX and YY (0≤X<W0≤X<W and 0≤Y<H0≤Y<H).

The next line contains an integer EE (E≥0E≥0), the number of “haunted holes”, and is followed by EE lines. Each of these contains five integers X1,Y1,X2,Y2,TX1​,Y1​,X2​,Y2​,T. (X1,Y1)(X1​,Y1​) is the position of the “haunted hole” (0≤X1<W0≤X1​<W and 0≤Y1<H0≤Y1​<H). (X2,Y2)(X2​,Y2​) is the destination of the “haunted hole” (0≤X2<W0≤X2​<W and 0≤Y2<H0≤Y2​<H). TT (−10 000≤T≤10 000−10000≤T≤10000) is the difference in seconds between the moment somebody enters the “haunted hole” and the moment he appears in the destination position; a positive number indicates that he reaches the destination after entering the hole.

You can safely assume that there are no two “haunted holes” with the same origin, and that neither the entrance nor the destination of a “haunted hole” contains a gravestone. Furthermore, there are neither gravestones nor “haunted holes” at positions (0,0)(0,0) and (W−1,H−1)(W−1,H−1).

The input will finish with a line containing 0 0, which should not be processed.
Output

For each test case, if it is possible for Scared John to travel back in time indefinitely without passing by the exit, output Never. Otherwise, print the minimum time in seconds that it takes him to cross the graveyard from the entrance to the exit if it is reachable, and Impossible if not.

Sample 1

Input 

3 3
2
2 1
1 2
0
4 3
2
2 1
3 1
1
3 0 2 2 0
4 2
0
1
2 0 1 0 -3
0 0

Output

Impossible
4
Never

* @source: https://vjudge.net/contest/761487#problem/F
* @notes: Solucion incompleta (funciona unicamente los casos de ejemplo).
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

#define ll long long

#define INF LLONG_MAX
#define MINF LLONG_MIN


class Graph{
    
    public:
    
        ll n_nodes;
        ll m_edges;
        ll W_width;
        ll H_height;
        
        struct Edge{
            ll node_u;
            ll node_v;
            ll time;
        };
        
        std::map<std::pair<ll,ll>, ll> edges; // Llave los nodos u,v. Valor el peso
        
        ll valueNode(ll x, ll y){
            return y*W_width+x;
        }
        
        void insertEdge(Edge edge){
            
            edges[{edge.node_u,edge.node_v}] = edge.time;
            m_edges++;
            
        }
        
        void deleteEdge(ll node_u, ll node_v){
            
            if(edges.find({node_u,node_v}) != edges.end()){
                edges.erase({node_u, node_v});
                m_edges--;
            }
            
            
        }
        
        void deleteNode(ll x, ll y){
            
            ll curr_node = valueNode(x,y);
            
            ll next_node;
                if(x + 1 < W_width){
                    next_node = valueNode(x+1,y);
                    deleteEdge(curr_node,next_node);
                }
                
                if(y + 1 < H_height){
                    next_node = valueNode(x,y+1);
                    deleteEdge(curr_node,next_node);
                }
                
                if(x - 1 >= 0){
                    next_node = valueNode(x-1,y);
                    deleteEdge(curr_node,next_node);
                }
                
                if(y - 1 >= 0){
                    next_node = valueNode(x,y-1);
                    deleteEdge(curr_node,next_node);
                }
        }
        
        // Retorna el peso del edge u, v. -1 si no existe
        ll findEdge(ll node_u, ll node_v){
            
            if(edges.find({node_u,node_v}) == edges.end()){
                return -1;
            }
            else{
                return edges[{node_u,node_v}];
            }
            
        }
        
        Graph(ll width, ll height){
            W_width = width;
            H_height = height;
            
            n_nodes = W_width * H_height;
            
            for(ll x = 0; x < W_width; x++){
                for(ll y = 0; y < H_height; y++){
                    ll curr_node = valueNode(x,y);
                    
                    ll next_node;
                    if(x + 1 < W_width){
                        next_node = valueNode(x+1,y);
                        insertEdge({curr_node,next_node,1});
                    }
                    
                    if(y + 1 < H_height){
                        next_node = valueNode(x,y+1);
                        insertEdge({curr_node,next_node,1});
                    }
                    
                    if(x - 1 >= 0){
                        next_node = valueNode(x-1,y);
                        insertEdge({curr_node,next_node,1});
                    }
                    
                    if(y - 1 >= 0){
                        next_node = valueNode(x,y-1);
                        insertEdge({curr_node,next_node,1});
                    }
                    
                }
            }
        }
        
    std::string bellman_algorithm(){
        
        // 
        std::vector<ll> dp_distances(n_nodes, INF);
        std::vector<bool> dp_negative_cycle(n_nodes, false);
        
        // Caso base, en la posición 0 (nodo 0) tardo un tiempo t = 0
        dp_distances[0] = 0;
        
        // Iteración: Suavizar
        
        for(ll curr_iteration = 0; curr_iteration < n_nodes - 1; curr_iteration++){
            
            for(auto itr = edges.begin(); itr != edges.end(); itr++){
                
                ll node_u = itr->first.first;
                ll node_v = itr->first.second;
                ll weight = itr->second;
                
                if(dp_distances[node_u] != INF){
                    
                    dp_distances[node_v] = std::min(dp_distances[node_u] + weight, dp_distances[node_v]);
                    
                }
                
            }
            
        }
        
        // Iterar: Loops negativos
        
        for(ll curr_iteration = 0; curr_iteration < n_nodes; curr_iteration++){
            for(auto itr = edges.begin(); itr != edges.end(); itr++){
                
                ll node_u = itr->first.first;
                ll node_v = itr->first.second;
                ll weight = itr->second;
                
                if(dp_distances[node_u] != INF && dp_distances[node_u] + weight < dp_distances[node_v]){
                    dp_negative_cycle[node_v] = true;
                }
                
                if (dp_negative_cycle[node_u] && dp_distances[node_u] != INF) {
                    dp_negative_cycle[node_v] = true;
                }
                
            }
        }
        
        ll end_node = valueNode(W_width-1,H_height-1);
        
        if(dp_negative_cycle[end_node]){return "Never";}
        if(dp_distances[end_node] == INF) {return "Impossible";}
        return std::to_string(dp_distances[end_node]);
        
    }
    
};

void solve(){
    
    ll W_width, H_height;
    while(std::cin >> W_width >> H_height && (W_width != 0 && H_height != 0)){
        
        Graph graph(W_width,H_height);
        
        ll G_gravestones;
        std::cin >> G_gravestones;
        
        for(ll curr_grave = 0; curr_grave < G_gravestones; curr_grave++){
            
            ll x, y;
            std::cin >> x >> y;
            
            graph.deleteNode(x,y);
            
        }
        
        ll E_haunted_holes;
        std::cin >> E_haunted_holes;
        
        for(ll curr_hole = 0; curr_hole < E_haunted_holes; curr_hole++){
            
            ll x1, x2, y1, y2, time;
            std::cin >> x1 >> y1 >> x2 >> y2 >> time;
            
            ll node_u = graph.valueNode(x1,y1);
            ll node_v = graph.valueNode(x2,y2);
            
            graph.insertEdge({node_u,node_v,time});
            
        }
        
        std::cout << graph.bellman_algorithm() << std::endl;
        
    }
    
}

int main(){
    optimize();
    solve();
    return 0;
}