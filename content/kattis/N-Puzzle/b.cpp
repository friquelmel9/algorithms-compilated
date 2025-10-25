#include <vector>
#include <string>
#include <iostream>
#include <cmath>


int scatter(int row, int col, int letter){
    
    if(letter == '.'){return 0;}
    
    int position = letter - 65; // 65 == Ascii code for A
    int correct_row = position / 4;
    int correct_col = position % 4;
    
    int scatter_row = row - correct_row;
    int scatter_col = col - correct_col;
    
    //std::cout << "diff row = " << scatter_row << ", diff col = " << scatter_col << " for letter: " << letter << std::endl;
    
    return std::abs(scatter_row) + std::abs(scatter_col);
}

int main(){
    
    std::vector<std::vector<char>> grid(4, std::vector<char>(4));
    char input;

    int row = 0;
    int col = 0;
    
    int sum = 0;
    
    for(int i=0; i<16; i++){
        std::cin >> input;
        sum += scatter(row / 4, col % 4, input);
        
        row++;  
        col++;
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}