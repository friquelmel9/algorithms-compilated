

/**
 * Declaración de un unordered_map con llave del tipo T1 y valor del tipo T2
 */
std::unordered_map<T1,T2> unordered_map;

/**
 * Retorna el tamaño del unordered_map
 * CT: O(1)
 */
unordered_map.size();

/**
 * Inserta un par llave - valor dentro del unordered_map
 * CT: O(1)
 */
unordered_map.insert({llave,valor});

/**
 * Elimina el par que contenga la llave
 * CT: O(1)
 */
unordered_map.erase(llave);

/**
 * Retorna un iterador hacia item. Retorna un iterador al final si no existe
 * CT: O(1)
 * 
 */
itr = unordered_map.find(llave);

/**
 * Acceso al primer elemento (llave)
 */
itr -> first;

/**
 * Acceso al segundo elemento (valor)
 */
itr -> second;