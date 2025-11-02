

/**
 * Declaración de un set de tipo T
 */
std::set<T> set;

/**
 * Retorna el tamaño del set
 * CT: O(1)
 */
set.size();

/**
 * Inserta un elemento al set
 * CT: O(\log{n})
 */
set.insert(item);

/**
 * Elimina el elemento del set
 * CT: O()
 */
set.erase(item);

/**
 * Retorna un iterador al elemento item. En caso que no existe retorna un iterador al final
 * CT: O(\log{n})
 */
set.find(item);

/**
 * Recorrer el set con un iterador. Permite obtener los elementos en orden basado en red-black-tree
 * CT: O(n)
 */
for(auto itr = set.begin(); itr != set.end(); itr++){}