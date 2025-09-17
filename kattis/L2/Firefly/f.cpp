#include <algorithm>
#include <vector>
#include <iostream>

int main(){
    
    int n, h;
    std::cin >> n;
    std::cin >> h;
    
    // arrays that stores the numbers of walls per each level. height 0 == 1.
    // I assume no walls that cover fullscreen (size h)
    std::vector<int> heights_walls(h, 0);
    int input;
    bool stalagmite = true;
    
    // heights
    for(int i=0; i<n; i++){
        std::cin >> input;
        if(stalagmite){ //bottom up
            heights_walls[0]++; 
            heights_walls[input]--;
        }
        else{
            heights_walls[h - input]++; 
        }
        stalagmite = !stalagmite;
    }
    
    // searching for every height with the min walls.
    //based on counting sort
    int min_walls = n + 1;
    int counter_heights;
    int curr_walls = 0;
    for(int i=0; i<h; i++){
        curr_walls += heights_walls[i];
        
        if(curr_walls < min_walls){
            min_walls = curr_walls;
            counter_heights = 1;
        }
        else if(curr_walls == min_walls) {counter_heights++;}
    }
    
    std::cout << min_walls << " " << counter_heights << std::endl;
    
    return 0;
}