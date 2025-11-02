

/**
 * Creación de un vector 
 */
std::vector<T> vector;

/** 
 * Creación de un vector con tamaño n
 * CT: O(n)
*/
std::vector<T> vector(n);

/**
 * Creación de un vector con tamaño n y sus valores en 0
 * CT: O(n)
*/
std::vector<T> vector(n,0);

/**
 * Retorna un iterador al inicio del vector
 */
vector.begin();

/**
 * Retorna un iterador al final del vector
 */
vector.end();
 
/**
 * Acceso a un elemento especifico de un vector 
 * CT: O(1)
 */
vector[i];

/**
 * Agregar un elemento al final del vector
 * CT: O(1)*
 */
vector.push_back(i);

/**
 * Quitar un elemento del final del vector
 * CT: O(1)
 */
vector.pop_back();

/**
 * Inserta un elemento en la posición i
 * CT: O(n)
 */
vector.insert(vector.begin()+i, item);

/**
 * Elimina un elemento en la posición i
 * CT: O(n)
 */
vector.erase(vector.begin()+i, item);

/**
 * Revisa si el vector esta vacio
 * CT: O(1)
 */
vector.empty();

/**
 * Retorna el tamaño del vector
 * CT: O(1)
 */
vector.size();

