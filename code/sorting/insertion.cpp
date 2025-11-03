#include "../header.hpp"

/**
 * @timecomplexity: O(n^2)
 * @spacecomplexity: O(1)
 * @stable: true
 * 
 */
template <typename T>
void insertionSort(std::vector<T> &array){
    
    for(size_t i = 0; i < array.size(); i++){
        T key = array[i];
        size_t j = i - 1;
        
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}