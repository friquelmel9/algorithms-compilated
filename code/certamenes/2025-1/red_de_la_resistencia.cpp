/** Problem Statement
Despu´es de que el brote del Cordyceps colapsara la civilizaci´on, las pocas zonas seguras que a´un exis-
ten sobreviven como pueden. En su misi´on por encontrar una cura, Ellie y Joel descubren en una base
abandonada de las Luci´ernagas los planos de un sistema antiguo de comunicaciones conocido como la Red
Silenciosa.

Esta red fue dise˜nada para conectar diferentes asentamientos sin depender de electricidad, mediante dispo-
sitivos que funcionan con bater´ıas. Aunque muchas de las rutas originales est´an destruidas, se ha logrado
generar un mapa para un conjunto de conexiones posibles entre zonas a´un habitadas. Cada conexi´on requiere
una cierta cantidad de bater´ıas para restaurarse.

Pero el sistema tiene una limitaci´on cr´ıtica: si se restauran conexiones que forman un ciclo, se activa una
alarma que atrae hordas de infectados. Por ello, deben evitar cualquier ciclo en la red.
El objetivo de Ellie y Joel es activar la Red Silenciosa de forma que todas las zonas seguras queden comunica-
das, de manera directa o indirecta, usando la menor cantidad total de bater´ıas, y sin activar conexiones
redundantes que generen ciclos.

Ellie y Joel han recurrido a los alumnos de Algoritmos y Complejidad en busca de ayuda para encontrar la
estrategia ´optima. ¿Podr´as ayudarlos a completar esta peligrosa misi´on?

Entrada
La entrada consiste en:

- Una l´ınea con dos enteros N y M (1 ≤ N ≤ 10^5, 0 ≤ M ≤ 2 · 10^5): el n´umero de zonas seguras y la
cantidad de rutas disponibles.

- Luego siguen M l´ıneas, cada una con tres enteros u, v y b:

    - u y v (1 ≤ u, v ≤ N ): identificadores de las zonas conectadas
    - b (1 ≤ b ≤ 104): bater´ıas necesarias para restaurar la ruta.

Salida
Imprime un solo n´umero: la cantidad m´ınima total de bater´ıas necesarias para restaurar la red cum-
pliendo las condiciones.

Ejemplos

Ejemplo de entrada 1

4 5
1 2 3
1 3 5
2 3 4
3 4 2
1 4 10

Salida 1

9

 * @source: https://codeforces.com/gym/615921/problem/B
*/

#include <bits/stdc++.h>

#define optimize() std::ios_base::sync_with_stdio(false) ; std::cin.tie(NULL) ; std::cout.tie(NULL) ;

// kill yourself
#define ll long long

class DisjointSetUnion{
    
    private:
        
        std::vector<int> parent;
        std::vector<int> rank;
    
    public:
    
        DisjointSetUnion(int n){
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
            rank.assign(n,0);
        }
        
        int find(int i){
            if(parent[i] == i){return i;}
            return parent[i] = find(parent[i]);
        }
        
        bool unite(int x, int y){
            int root_x = find(x);
            int root_y = find(y);
            
            if(root_x != root_y){
                if(rank[root_x] < rank[root_y]){
                    parent[root_x] = root_y;
                } else if (rank[root_x] > rank[root_y]){
                    parent[root_y] = root_x;
                } else{
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
    
        struct Edge{
            int node_v;
            int weight; // weight == batterries
        };
        
        struct Node{
            int state;
            std::vector<Edge> adj;
        };
        
        int n_nodes; // N zonas
        int m_edges; // M edges
        
        std::vector<Node> nodes; // nodos con indice 1. => node[0] = 1;
    
    public:
    
        GraphAdjacency(){
            n_nodes = 0;
            m_edges = 0;
        }
        
        GraphAdjacency(int n){
            n_nodes = n;
            m_edges = 0;
            nodes.resize(n);
        }
        
        int obtainNodeIdx(int node_value){
            return node_value-1;
        }
        
        void addEdge(int node_u, int node_v, int weight){
            
            if(node_u < n_nodes && node_v < n_nodes){
                
                std::vector<Edge> &adj = nodes[node_u].adj;
                
                adj.push_back({node_v,weight});
                m_edges++;
                
            }
            
        }
        
        struct KruskalEdge{
            int node_u;
            int node_v;
            int weight; // weight == baterries
        };
        
        std::vector<KruskalEdge> minimumSpanningTree(){
            
            std::vector<KruskalEdge> aint_edges;
            
            for(int node_u = 0; node_u < n_nodes; node_u++){
                
                std::vector<Edge>& adj = nodes[node_u].adj;
                
                for(Edge edge : adj){
                    
                    int node_v = edge.node_v;
                    
                    if(node_u < node_v){
                        aint_edges.push_back({node_u,node_v,edge.weight});
                    }
                }
                
            }
            
            std::sort(aint_edges.begin(), aint_edges.end(), [](const KruskalEdge a, const KruskalEdge b){
                return a.weight < b.weight;
            });
            
            DisjointSetUnion dsu(n_nodes);
            std::vector<KruskalEdge> mst_edges;
            
            for(KruskalEdge k_edge : aint_edges){
                if(dsu.unite(k_edge.node_u, k_edge.node_v)){
                    mst_edges.push_back(k_edge);
                }
                if(mst_edges.size() == n_nodes-1){
                    break;
                }
            }
            
            return mst_edges;
        }
        
        int red_silenciosa(){
            
            std::vector<KruskalEdge> mst = minimumSpanningTree();
            
            int curr_bateries = 0;
            
            for(KruskalEdge k_edge : mst){
                curr_bateries += k_edge.weight;
            }
            
            return curr_bateries;
            
        }
    
};

void solve(){
    
    int n_zonas, m_rutas;
    std::cin >> n_zonas >> m_rutas;
    
    GraphAdjacency grafo(n_zonas);
    
    for(int curr_ruta = 0; curr_ruta < m_rutas; curr_ruta++){
        
        int node_u, node_v, weight;
        std::cin >> node_u >> node_v >> weight;
        
        node_u = grafo.obtainNodeIdx(node_u);
        node_v = grafo.obtainNodeIdx(node_v);
        
        // Recordar poner para los dos lados para que el grafo sea unidireccionado
        grafo.addEdge(node_u,node_v,weight);
        grafo.addEdge(node_v,node_u,weight);
        
    }
    
    std::cout << grafo.red_silenciosa() << std::endl;
    
}

int main(){
    optimize();
    solve();
    return 0;
}