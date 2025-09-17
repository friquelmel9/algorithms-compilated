#include <vector>
#include <iostream>

/**
 * InsertionSort modified to count each number of steps
 * Asummes that the numbers before the last element are already sorted. Is an inverse insertion sort of a kind.
 */
int insertionSortModified(std::vector<int> &array){
    int steps = 0;
    int i = array.size()-1;
    
    while(i-1>=0 && array[i-1] > array[i]){
        std::swap(array[i-1], array[i]);
        i--;
        steps++;
    }
    
    return steps;
}

int main(){
    
    int p; 
    std::cin >> p;
        
    // each dataset
    for(int i=1; i<=p; i++){
        
        int total = 0;
        int count = 20;
        int value;
        std::vector<int> array;
        
        std::cin >> value; // skips first line
        
        while(count > 0){
            
            std::cin >> value;
            array.push_back(value);
            total += insertionSortModified(array);
            
            count--;
        }
        
        std::cout << i << " " << total << std::endl ;
    }
    
    return 0;
}