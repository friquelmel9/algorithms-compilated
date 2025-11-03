#include "../header.hpp"

/**
 * Takes a partition and sorts the array based on it. 
 * Assumes that the last element is the pivot
 * 
 * @param array Array to be sorted
 * @param lowest left side of the array
 * @param highest right side of the array
 */
int partition(std::vector<int> &array, int lowest, int highest){
    
    int n = highest-lowest+1;
    int i = lowest - 1;
    
    int pivot_value = array[highest];
    
    for(int j=lowest; j<highest; j++){
        if(array[j] < pivot_value){
            std::swap(array[i+1], array[j]);
            i++;
        }
    }
    
    std::swap(array[i+1], array[highest]);
    return i+1;
}

/**
 * Implementation of quick sort using random pivoting
 * 
 * @timecomplexity: O(n^2), \Theta(n\log{n})
 * @spacecomplexity: O(1)
 * @stable: false
 * 
 * @param array Array to be sorted
 * @param lowest left side of the array
 * @param highest right side of the array
 */
void quickSort(std::vector<int> &array, int lowest, int highest){
    int n = highest - lowest + 1;
    if(n>1 && lowest >= 0 && highest < array.size()){
        
        int pivot = lowest + rand() % n;
        std::swap(array[pivot],array[highest]);
        pivot = partition(array, lowest, highest);
        quickSort(array, lowest, pivot-1);
        quickSort(array, pivot+1, highest);
    }
}