

/**
 * Declaración de un set de tipo T
 */
std::set<T> set;

/**
 * Retorna el tamaño del set
 * @timecomplexity: O(1)
 */
set.size();

/**
 * Inserta un elemento al set
 * @timecomplexity: O(\log{n})
 */
set.insert(item);

/**
 * Elimina el elemento del set
 * @timecomplexity: O()
 */
set.erase(item);

/**
 * Retorna un iterador al elemento item. En caso que no existe retorna un iterador al final
 * @timecomplexity: O(\log{n})
 */
set.find(item);

/**
 * Recorrer el set con un iterador. Permite obtener los elementos en orden basado en red-black-tree
 * @timecomplexity: O(n)
 */
for(auto itr = set.begin(); itr != set.end(); itr++){}