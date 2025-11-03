#include "../header.hpp"

/**
 * @timecomplexity: O(n^2)
 * @spacecomplexity: O(1)
 * @stable: true
 */
template <typename T>
void bubbleSort(std::vector<T> &array){
    
    bool swap;
    do{
        swap = false;
        for(size_t i = 0; i<array.size()-1; i++){
            if(array[i] > array[i+1]){
                std::swap(array[i], array[i+1]);
                swap = true;
            }
        }
    }while(swap);
}