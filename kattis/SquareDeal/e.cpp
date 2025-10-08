#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>


bool checkSquare(std::vector<std::pair<int,int>> rects, std::bitset<3> rotation_mask){
    
    // rotate
    for(int i=0; i<3; i++){ if(rotation_mask[i]) { std::swap(rects[i].first, rects[i].second); } }
    
    // case 1: |||
    
    if(rects[0].first == rects[1].first && rects[1].first == rects[2].first 
        && rects[0].second + rects[1].second + rects[2].second == rects[0].first)
    {return true;}
    
    // case 2: |=
    
    if(rects[1].second == rects[2].second && rects[1].first + rects[2].first == rects[0].first
        && rects[0].second + rects[1].second == rects[0].first)
    {return true;}
    
    return false;
}

int main(){
    
    std::vector<std::pair<int,int>> rects;
    
    for(int i=0; i<3; i++){
        
        int height, width;
        std::cin >> height >> width;
        rects.push_back({height,width});
        
    }
    
    bool square = false;
    int permutation = 1;
    
    do{
        for(int i=0; i<8; i++){
            
            std::bitset<3> rotation_mask(i);
            if(checkSquare(rects,rotation_mask)){
                square = true;
                break;
            }
        }
    }while(std::next_permutation(rects.begin(), rects.end()));
    
    if(square){std::cout << "YES" << std::endl;}
    else{std::cout << "NO" << std::endl;}
    
    return 0;
}