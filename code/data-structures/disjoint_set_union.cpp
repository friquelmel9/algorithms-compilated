#include <bits/stdc++.h>

/**
 * Clase que implementa un Disjoint Set Union (DSU)
 * Falta agregar comentarios de las funciones.
 */
class DisjointSetUnion{
    
    private:
    
        std::vector<int> parent;
        std::vector<int> rank; // Para mantener la altura del arbol
    
    public:
    
        /**
         * 
         * @time_complexity: O(n)
         * @space_complexity: O(n)
         */
        DisjointSetUnion(int n){
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
            rank.assign(n, 0);
        }
        
        /**
         * 
         * @time_complexity: O(\alpha(N))*
         * @space_complexity: O(n)
         */
        int find(int i) {
            if (parent[i] == i) {return i; }
            return parent[i] = find(parent[i]);
        }
        
        /**
         * 
         * @time_complexity: O(\alpha(N))*
         * @space_complexity: O(n)
         */
        bool unite(int x, int y){
            int root_x = find(x);
            int root_y = find(y);
            
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