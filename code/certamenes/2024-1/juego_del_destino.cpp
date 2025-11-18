/**
Robert y Rachele estaban diseñando problemas para una competencia de programación competitiva cuando apareció Federic 
con una propuesta llrigante. Federic generó un mapa compuesto por puntos y calles que conectan esos puntos, 
y en cada calle colocó una cantidad específica de fichas.

Siempre juguetón, Federic les propuso un desafío: un juego. Las reglas eran simples: 
Robert y Rachele deben elegir un punto inicial (que podría ser distllo para cada uno) y, desde allí, 
visitar todos los puntos del mapa. Cada vez que uno de ellos cruza una calle, obtendría las fichas asociadas a esa calle.
Si ambos cruzan la misma calle, ambos obtendrían las fichas. No puedes usar una calle que lleva a un punto ya visitado. 
Te puedes devolver a cualquier punto ya visitado

El objetivo del juego, según Federic, es maximizar la diferencia en la cantidad de fichas recolectadas entre Robert y Rachele. 
Sin embargo, había un giro dramático: si no logran maximizar esta diferencia, Federic amenaza con destruir el mundo.

Angustiados por la amenaza, Robert y Rachele recurrieron a ti en busca de ayuda para encontrar la estrategia óptima que les permitiera 
alcanzar la mayor diferencia posible en la cantidad de fichas recolectadas. ¿Podrás ayudarlos a salvar el mundo?

Input

La primera línea del input contiene dos enteros, n y m (1 ≤ n ≤ 105, m ≤ 2·105), que representan la cantidad de puntos y calles, 
respectivamente.

A continuación, se presentan m líneas, cada una con tres enteros: a, b y f. Estos indican que existe una calle entre los puntos a y b,
en la cual hay f fichas. Los puntos están enumerados de 1 a n, y la cantidad de fichas f está en el rango de 1 a 109.

Se asegura que todos los puntos están conectados por algún subconjunto de calles.

Output

El output debe consistir en un único entero que represente la diferencia máxima de fichas que pueden obtener Robert y Rachele.

Input 1

5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Output 1:

10

 * @source: https://codeforces.com/group/wA0CSxKsVV/contest/568840/problem/E
 *
 * @timecomplexity: 
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; //std::cout.tie(NULL) ;

#define ll long long

class DisjollSetUnion{
    
    private:
    
        std::vector<ll> parent;
        std::vector<ll> rank; // Para mantener la altura del arbol
    
    public:
    
        /**
         * 
         * @time_complexity: O(n)
         * @space_complexity: O(n)
         */
        DisjollSetUnion(ll n){
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
            rank.assign(n, 0);
        }
        
        /**
         * 
         * @time_complexity: O(\alpha(N))*
         * @space_complexity: O(n)
         */
        ll find(ll i) {
            if (parent[i] == i) {return i; }
            return parent[i] = find(parent[i]);
        }
        
        /**
         * 
         * @time_complexity: O(\alpha(N))*
         * @space_complexity: O(n)
         */
        bool unite(ll x, ll y){
            ll root_x = find(x);
            ll root_y = find(y);
            
            if(root_x != root_y){
                
                if (rank[root_x] < rank[root_y]) {
                parent[root_x] = root_y;
                } else if (rank[root_x] > rank[root_y]) {
                    parent[root_y] = root_x;
                } else {
                    parent[root_y] = root_x;
                    rank[root_x]++; 
                }
                return true;
                
            }
            
            return false;
        }
    
};

class GraphAdjacency{
    
    
    private:
        
        /**
         * @brief Representa una arista con dirección a v y peso w
         */
        struct Edge{
            ll node_v; // Indice / Valor de la variable de destino
            ll weight; // Peso de la arista (fichas)
        };
        
        // Definición de estados 
        const ll ACTIVE = 1;
        const ll INACTIVE = 0;
        
        // Defincion de estados para DFS
        const ll NOT_VISITED = 0;
        const ll IN_PROCESS = 1;
        const ll VISITED = 2;
        
        // Definición de estados para Bellman
        const ll INF = LLONG_MAX;
        const ll MINF = LLONG_MIN;
        
        /**
         * @brief Representa un nodo con valor asociado y estado, utilizado par avarios algoritmos
         */
        struct Node{
            ll node_val; // Posible valor a guardar si indice no equivale
            ll state; // Estado del nodo (Utilizado para algoritmos)
            std::vector<Edge> adj; // Lista de adyacencia del nodo actual
        };
        
        ll n_nodes; // Cantidad de nodos en el grafo
        ll m_edges; // Cantidad de aristas en el grafo
        
        std::vector<Node> nodes; // Vector que guardas los nodos relacionados al grafo.
        
        
    
    public:
    
        GraphAdjacency(){
            n_nodes = 0;
            m_edges = 0;
        }
        
        GraphAdjacency(ll n){
            n_nodes = n;
            nodes.resize(n);
            m_edges = 0;
        }
        
        /**
         * Agrega un nodo al grafo
         * Por convención, este sera accesible por el indice, no su valor guardado
         * 
         * @param node_val Valor para guardar dentro del nodo,
         */
        void addNode(ll node_val){
            
            Node new_node = {node_val,ACTIVE,{}};
            nodes.push_back(new_node);
            n_nodes++;
            
        }
        
        /**
         * Agrega una arista al grafo
         * Si la arista ya existe, modificara su peso
         * 
         * @param node_u Indice para acceder al nodo inicial
         * @param node_v Indice para acceder al nodo destino
         * @param weight Peso de la arista
         */
        void addEdge(ll node_u, ll node_v, ll weight){
            
            if(node_u < n_nodes && node_v < n_nodes){
                
                std::vector<Edge>& adj = nodes[node_u].adj;
                
                for(Edge edge : adj){
                    if(edge.node_v == node_v){
                        modifyEdge(node_u,node_v,weight);
                        return;
                    }
                }
                
                nodes[node_u].adj.push_back({node_v,weight});
                m_edges++;
            }
            
        }
        
        /**
         * Borra una arista al grafo
         * 
         * @param node_u Indice para acceder al nodo inicial
         * @param node_v Indice para acceder al nodo destino
         */
        void deleteEdge(ll node_u, ll node_v){
            
            if(node_u < n_nodes && node_v < n_nodes){
                
                std::vector<Edge>& adj = nodes[node_u].adj;
                auto itr = adj.begin();
                
                while(itr != adj.end()){
                    if(itr->node_v == node_v){
                        adj.erase(itr);
                        m_edges--;
                        break;
                    }
                    else{itr++;}
                }
            }
            
        }
        
        /**
         * Modifica el peso de una arista del grafo
         * 
         * @param node_u Indice para acceder al nodo inicial
         * @param node_v Indice para acceder al nodo destino
         * @param weight Peso de la arista
         */
        void modifyEdge(ll node_u, ll node_v, ll new_weight){
            
            if(node_u < n_nodes && node_v < n_nodes){
                for(auto itr = nodes[node_u].adj.begin(); itr != nodes[node_u].adj.end(); itr++){
                    if(itr->node_v == node_v){itr->weight = new_weight;}
                }
            }
        }
        
        struct KruskalEdge{
            ll node_u;
            ll node_v;
            ll weight;
        };
        
        ll minimumSpanningTreeKruskal(){
            
            std::vector<KruskalEdge> all_edges;
            
            for (ll node_u = 0; node_u < n_nodes; node_u++) {
                
                std::vector<Edge>& adj = nodes[node_u].adj;
                
                for (Edge edge : adj) {
                    ll v = edge.node_v;
                    if (node_u < v) { 
                        all_edges.push_back({node_u, v, edge.weight});
                    }
                }
            }
            
            std::sort(all_edges.begin(), all_edges.end(), [](const KruskalEdge& a, const KruskalEdge& b) {
                return a.weight < b.weight;
            });
            
            DisjollSetUnion dsu(n_nodes);
            std::vector<KruskalEdge> mst_edges;
            
            for (KruskalEdge edge : all_edges) {
                if (dsu.unite(edge.node_u, edge.node_v)) {
                    mst_edges.push_back(edge); 
                }
                
                if (mst_edges.size() == n_nodes - 1) {
                    break;
                }
            }
            
            ll value = 0;
            //std::cout << "=============== EDGES MINIMUM ================" << std::endl;
            for(KruskalEdge edge : mst_edges){
                value += edge.weight;
                //std::cout << "edge from (" << edge.node_u << ") to edge (" << edge.node_v << ") con fichas = " << edge.weight << std::endl;
            }
            
            return value;
            
            //return mst_edges;
        }
        
        ll maximumSpanningTreeKruskal(){
            
            std::vector<KruskalEdge> all_edges;
            
            for (ll node_u = 0; node_u < n_nodes; node_u++) {
                
                std::vector<Edge>& adj = nodes[node_u].adj;
                
                for (Edge edge : adj) {
                    ll v = edge.node_v;
                    if (node_u < v) { 
                        all_edges.push_back({node_u, v, edge.weight});
                    }
                }
            }
            
            std::sort(all_edges.begin(), all_edges.end(), [](const KruskalEdge& a, const KruskalEdge& b) {
                return a.weight > b.weight;
            });
            
            DisjollSetUnion dsu(n_nodes);
            std::vector<KruskalEdge> mst_edges;
            
            for (KruskalEdge edge : all_edges) {
                if (dsu.unite(edge.node_u, edge.node_v)) {
                    mst_edges.push_back(edge); 
                }
                
                if (mst_edges.size() == n_nodes - 1) {
                    break;
                }
            }
            
            ll value = 0;
            for(KruskalEdge edge : mst_edges){
                value += edge.weight;
            }
            
            return value;
            
            //return mst_edges;
        }
};

void solve(){
    
    ll n_puntos, m_calles;
    std::cin >> n_puntos >> m_calles;
    
    GraphAdjacency grafo(n_puntos);
    
    for(ll curr_edge = 0; curr_edge < m_calles; curr_edge++){
        
        ll node_u, node_v, fichas;
        std::cin >> node_u >> node_v >> fichas;
        
        grafo.addEdge(node_u-1,node_v-1,fichas);
        grafo.addEdge(node_v-1,node_u-1,fichas);
        
    }
    
    ////std::cout << "=====================" << std::endl;
    ll max_value = grafo.maximumSpanningTreeKruskal();
    //std::cout << max_value << std::endl;
    
    ll min_value = grafo.minimumSpanningTreeKruskal();
    //std::cout << min_value << std::endl;
    
    std::cout << max_value-min_value << std::endl; 
    
}

int main(){
    optimize();
    solve();
    return 0;
}