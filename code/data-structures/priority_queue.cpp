

/**
 * Crea una priority queue del tipo T
 * El elemento al tope de la priority queue sera el de mayor valor
 */
std::priority_queue<T> pq;

/**
 * Crea una priorty queue del tipo T
 * El elemento al tope de la priority queue sera aquel de menor valor
 */
std::priority_queue<T, std::vector<T>, std::greater<T>> min_pq;

/**
 * Retorna el tamaño de la priority queue
 * CT: O(1)
 */
pq.size();

/**
 * Inserta un elemento en la priority queue
 * CT: O(\log{n})
 */
pq.insert(item);

/**
 * Elimina el elemento de mayor prioridad
 * CT: O(\log{n})
 */
pq.pop();

/**
 * Obtiene el elemento al tope de la priority queue
 * CT: O(1)
 */
pq.top();