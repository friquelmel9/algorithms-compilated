

/**
 * Declaración de un map con llave del tipo T1 y valor del tipo T2
 */
std::map<T1,T2> map;

/**
 * Retorna el tamaño del map
 * @timecomplexity: O(1)
 */
map.size();

/**
 * Inserta un par llave - valor dentro del map
 * @timecomplexity: O(\log{n})
 */
map.insert({llave,valor});

/**
 * Elimina el par que contenga la llave
 * @timecomplexity: O(\log{n})
 */
map.erase(llave);

/**
 * Retorna un iterador hacia item. Retorna un iterador al final si no existe
 * @timecomplexity: O(\log{n})
 * 
 */
itr = map.find(llave);

/**
 * Acceso al primer elemento (llave)
 */
itr -> first;

/**
 * Acceso al segundo elemento (valor)
 */
itr -> second;