#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

int main(){
    
    int n;
    while(std::cin >> n && n != 0){
        
        std::vector<int> array1, array2;
        std::map<int, int> map;
        int input;
        
        //first array
        for(int i=0; i<n; i++){
            std::cin >> input;
            array1.push_back(input);
            map[input] = i;
        }
        std::sort(array1.begin(), array1.end());
        
        std::vector<int> pos(n);
        
        // for each value, stores the relative position
        for(int i=0; i<n; i++){
            pos[map[array1[i]]] = i;
        }
        
        // second array
        for(int i=0; i<n; i++){
            std::cin >> input;
            array2.push_back(input);
        }
        std::sort(array2.begin(), array2.end());
        
        // for each pos stored in value, search the relative one on the second array. Print each value
        for(int i=0; i<n; i++){
            std::cout << array2[pos[i]] << std::endl;
        }
        
        std::cout << std::endl;
    }
    
    
    return 0;
}