#include <bits/stdc++.h>
#include "disjoint_set_union.cpp"

/**
 * Clase que implementa un grafo mediante lista de adyacencia
 * 
 * Esta implementación tiene los siguientes supuestos
 * - El valor del nodo corresponde a su indice. (Nodo 0 == nodes[0])
 * - No habra multiples aristas en la misma dirección
 * - No es posible borrar nodos (Es programable, pero depende del problema)
 */
class GraphAdjacency{
    
    
    private:
        
        /**
         * @brief Representa una arista con dirección a v y peso w
         */
        struct Edge{
            int node_v; // Indice / Valor de la variable de destino
            int weight; // Peso de la arista
        };
        
        // Definición de estados 
        const int ACTIVE = 1;
        const int INACTIVE = 0;
        
        // Defincion de estados para DFS
        const int NOT_VISITED = 0;
        const int IN_PROCESS = 1;
        const int VISITED = 2;
        
        /**
         * @brief Representa un nodo con valor asociado y estado, utilizado par avarios algoritmos
         */
        struct Node{
            int node_val; // Posible valor a guardar si indice no equivale
            int state; // Estado del nodo (Utilizado para algoritmos)
            std::vector<Edge> adj; // Lista de adyacencia del nodo actual
        };
        
        int n_nodes; // Cantidad de nodos en el grafo
        int m_edges; // Cantidad de aristas en el grafo
        
        std::vector<Node> nodes; // Vector que guardas los nodos relacionados al grafo.
        
        
    
    public:
    
        GraphAdjacency(){
            n_nodes = 0;
            m_edges = 0;
        }
        
        /**
         * Agrega un nodo al grafo
         * Por convención, este sera accesible por el indice, no su valor guardado
         * 
         * @param node_val Valor para guardar dentro del nodo,
         */
        void addNode(int node_val){
            
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
        void addEdge(int node_u, int node_v, int weight){
            
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
        void deleteEdge(int node_u, int node_v){
            
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
        void modifyEdge(int node_u, int node_v, int new_weight){
            
            if(node_u < n_nodes && node_v < n_nodes){
                for(auto itr = nodes[node_u].adj.begin(); itr != nodes[node_u].adj.end(); itr++){
                    if(itr->node_v == node_v){itr->weight = new_weight;}
                }
            }
        }
        
        /**
         * Modifica el estado de un nodo
         * 
         * @param node_u Indice para acceder al nodo inicial
         * @param new_state Nuevo estado para el nodo.
         */
        void modifyNodeState(int node_u, int new_state){
            
            if(node_u < n_nodes){
                nodes[node_u].state = new_state;
            }
        }
        
        struct KruskalEdge{
            int node_u;
            int node_v;
            int weight;
        };
        
        /**
         * Obtiene el Minimum Spanning Tree usando Kruskal
         * 
         * @pre El grafo debe ser unidireccionado. Para esto, asegurarse de usar AddEdge en ambos sentidos
         * @pre Debe incluirse una implementación de Disjoint Set Union (DSU)
         * @pre Utilizar el struct definido para guardar el MSP, KruskalEdge
         * 
         * @return Valor
         */
        std::vector<KruskalEdge> minimumSpanningTreeKruskal(){
            
            std::vector<KruskalEdge> all_edges;
            
            for (int node_u = 0; node_u < n_nodes; node_u++) {
                
                std::vector<Edge>& adj = nodes[node_u].adj;
                
                for (Edge edge : adj) {
                    int v = edge.node_v;
                    if (node_u < v) { 
                        all_edges.push_back({node_u, v, edge.weight});
                    }
                }
            }
            
            std::sort(all_edges.begin(), all_edges.end(), [](const KruskalEdge& a, const KruskalEdge& b) {
                return a.weight < b.weight;
            });
            
            DisjointSetUnion dsu(n_nodes);
            std::vector<KruskalEdge> mst_edges;
            
            for (KruskalEdge edge : all_edges) {
                if (dsu.unite(edge.node_u, edge.node_v)) {
                    mst_edges.push_back(edge); 
                }
                
                if (mst_edges.size() == n_nodes - 1) {
                    break;
                }
            }
            
            return mst_edges;
        }
        
};