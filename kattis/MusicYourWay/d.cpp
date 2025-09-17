#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <limits>


int main(){
    
    std::string attributes;
    std::getline(std::cin, attributes);
    
    // obtain each attribute. 
    std::unordered_map<std::string, int> map_attributes;
    std::stringstream ss_attributes(attributes);
    std::string attribute;
    int i = 1;
    while(ss_attributes >> attribute){
        map_attributes[attribute] = i;
        i++;
    }
    
    // store songs
    int m;
    std::cin >> m;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::vector<std::string> songs_list;
    std::string input;
    for(int i=0; i<m; i++){
        std::getline(std::cin, input);
        songs_list.push_back(input);
    }
    
    // print ordered by the input
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // attribute_index represents what word is selected to be sorted
    int attribute_index;
    
    for(int i=0; i<n; i++){
        
        std::getline(std::cin, input);
        attribute_index = map_attributes[input];
        
        // lambda
        std::stable_sort(songs_list.begin(), songs_list.end(), [&attribute_index](const std::string& song1, const std::string& song2){
            std::stringstream ss_song1(song1), ss_song2(song2);
            std::string word1, word2;
            
            for(int i=0; i<attribute_index; i++){
                ss_song1 >> word1;
                ss_song2 >> word2;
            }
        
            return word1 < word2;
            });
        
        // cout
        std::cout << attributes << std::endl;
        for(int j=0; j<m; j++){
            std::cout << songs_list[j] << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}