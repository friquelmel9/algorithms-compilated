#include "../header.hpp"

/**
 * Function that merges two subarrays
 * 
 * @param array Complete array
 * @param left left side of the array
 * @param middle middle side of the array
 * @param right right side of the array
 */
template <typename T>
void merge(std::vector<T> &array, size_t left, size_t middle, size_t right){
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;
    
    std::vector<T> L(n1);
    for(size_t i=0; i<n1; i++){ L[i] = array[left+i];}
    
    std::vector<T> R(n2);
    for(size_t j=0; j<n2; j++){ L[j] = array[middle+1+j];}
    
    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    
    while(i<n1 && j<n2){
        if(L[i] < R[j]){
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        array[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2){
        array[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Function that sorts an array using mergeSort
 * 
 * @timecomplexity: O(n\log{n})
 * @memorycomplexity: O(n)
 * @stable: true
 * 
 * @param array Array to be sorted
 * @param left left side of the array
 * @param right right side of the array
 * 
 * 
 */
template <typename T>
void mergeSort(std::vector<T> &array, size_t left, size_t right){
    if(left < right){
        size_t middle = left + (right - left)/2;
        mergeSort(array,left,middle);
        mergeSort(array,middle+1,right);
    }
}