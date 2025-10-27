#include <iostream>
#include <vector>
#include <map>
#include <string>

void backtracking(std::map<int, std::string> &priorities, std::map<std::string, int> &index_colors,
                    std::vector<std::vector<bool>> &restrictions,
                    int &n, int &not_hideous_count,
                    std::vector<std::string> &favorite_painting, std::vector<std::string> curr_painting){
    
    // base case
    
    // std::cout << "curr painting: " << curr_painting.size() << std::endl;
    
    if(curr_painting.size() == n){
        
        not_hideous_count++;
        
        // if not current favorite painting yet
        if(favorite_painting.empty()){
            favorite_painting = curr_painting;
        }
        else{
            // compare the paintings
            
            int i=0;
            while(i < n){
                
                int curr_priority = index_colors[curr_painting[i]];
                int favorite_priority = index_colors[favorite_painting[i]];
                
                if(curr_priority < favorite_priority){break;}
                if(curr_priority > favorite_priority){ // if one priority better than another, new picture is best
                    favorite_painting = curr_painting;
                    break;  
                }
                i++;
            }
        }
        
    }
    
    else{
        
        //std::cout << "else block" << std::endl;
        
        for(int i=n-1; i>=0; i--){
            
            if(priorities.find(i) == priorities.end()){continue;}
            
            std::string color = priorities[i];
            
            if(curr_painting.size() == 0){
                
                std::pair<std::string,int> tmp = {color, i};
                priorities.erase(i);

                curr_painting.push_back(color);
                backtracking(priorities, index_colors, restrictions, n, not_hideous_count, favorite_painting, curr_painting);
                
                curr_painting.pop_back();
                priorities[tmp.second] = tmp.first;
            }
            else{
                
                // check if the colors can be next to eachother
                
                int idx_color = index_colors[color];
                int idx_prev_color = index_colors[curr_painting[curr_painting.size()-1]]; // obtains the index of the previous elemnt
                if(restrictions[idx_color][idx_prev_color]){continue;} // if restriction exists
                
                // backtracking
                
                std::pair<std::string,int> tmp = {color, i};
                priorities.erase(i);
                
                curr_painting.push_back(color);
                backtracking(priorities, index_colors, restrictions, n, not_hideous_count, favorite_painting, curr_painting);
                
                curr_painting.pop_back();
                priorities[tmp.second] = tmp.first;
            }
            
        }
        
    }
    
}

int main(){
    
    int t; // test cases
    std::cin >> t;
    
    while(t > 0){
        
        // std::cout << "test case: " << t << std::endl;
        
        int n; // number of colors
        std::cin >> n;
        
        std::map<std::string, int> index_colors;
        std::map<int, std::string> priorities;
        std::string input;
        
        for(int i=n-1; i>=0; i--){
            std::cin >> input;
            index_colors[input] = i; // index are priorities
            priorities[i] = input;
        }
        
        int m; // restrictions
        std::cin >> m;
        
        std::string input2;
        std::vector<std::vector<bool>> restrictions(n, std::vector<bool>(n,false));
        for(int i=0; i<m; i++){
            std::cin >> input >> input2;
            
            int index1 = index_colors[input];
            int index2 = index_colors[input2];
            
            restrictions[index1][index2] = true;
            restrictions[index2][index1] = true;
        }
        
        std::vector<std::string> favorite_painting;
        std::vector<std::string> curr_painting;
        int not_hideous_count = 0;
        
        backtracking(priorities,index_colors,restrictions,n,not_hideous_count,favorite_painting,curr_painting);
        
        std::cout << not_hideous_count << std::endl;
        int i=0;
        while(i<n-1){
            std::cout << favorite_painting[i] << " ";
            i++;
        }
        std::cout << favorite_painting[n-1] << std::endl;
        
        t--;
    }
    
    return 0;
}
