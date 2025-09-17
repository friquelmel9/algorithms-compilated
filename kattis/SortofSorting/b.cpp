#include <string>
#include <vector>
#include <iostream>
#include <map>


int main(){
    
    int t;
    
    while(std::cin >> t && t != 0){
        
        std::map<int, std::map<int, std::vector<std::string>>> names;
        
        for(int i=0; i<t; i++){
            
            std::string input;
            std::cin >> input;
            
            // I assume first letter starts with mayus, second in minus. distinct numbers
            names[input[0]][input[1]].push_back(input);
        }
        
        std::map<int, std::map<int, std::vector<std::string>>>::iterator itr1;
        std::map<int, std::vector<std::string>>::iterator itr2;
        
        for(itr1 = names.begin(); itr1 != names.end(); itr1++){
            for(itr2 = itr1->second.begin(); itr2 != itr1->second.end(); itr2++){
                for(int i=0; i<itr2->second.size(); i++){
                    std::cout << itr2->second[i] << std::endl;
                }
            }
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}