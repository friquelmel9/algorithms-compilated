#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

#define VOWEL 0
#define CONSONANT 1
#define L 2
#define UNDERSCORE 3

#define VAL_VOWEL 5
#define VAL_CONSONANT 21
#define VAL_L 1

#define POSIBLE_VOWEL 102
#define POSIBLE_CONSONANT 103
#define POSIBLE_L 104
#define END 105

std::set<char> vowels = {'A','E','I','O','U'};
std::set<char> consonants = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','X','Y','Z'};

void backtracking(long long &pleasant_words, std::vector<int>&mask, std::vector<int>& underscores, 
    std::vector<int>&values, bool isL, int curr){
        
    //std::cout << "curr: " << curr << std::endl;
    
    //std::cout << "underscore: " << underscores[curr] << std::endl;
    if(underscores[curr] == END && isL){
        
        long long new_words = 1;
        for(int i=0; i<values.size(); i++){ 
            
            //std::cout << "value found ";
            
            new_words *= values[i];
            
            //std::cout << "+" << values[i];
            
        }
        //std::cout << std::endl;
        pleasant_words += new_words;
    }
    
    else if(underscores[curr] < mask.size()){
        
        int curr_idx = underscores[curr];
        
        //std::cout << "check vowel in curr: " << curr << std::endl;
        bool canVowel = true;
        if(curr_idx - 2 >= 0 && curr_idx - 1 >= 0
            && mask[curr_idx-2] == VOWEL && mask[curr_idx-1] == VOWEL){canVowel = false;}
        if(curr_idx - 1 >= 0 && curr_idx + 1 < mask.size() 
            && mask[curr_idx-1] == VOWEL && mask[curr_idx+1] == VOWEL){canVowel = false;}
        if(curr_idx + 1 < mask.size() && curr_idx + 2 < mask.size() 
            && mask[curr_idx+1] == VOWEL && mask[curr_idx+2] == VOWEL){canVowel = false;}
        
        if(canVowel){
            
            //std::cout << "can Vowel" << std::endl;
            mask[curr_idx] = VOWEL;
            values.push_back(VAL_VOWEL);
            backtracking(pleasant_words,mask,underscores,values,isL,curr+1);
            values.pop_back();
            
        }
        
        mask[curr_idx] = UNDERSCORE;
        
        //std::cout << "check consonant in curr: " << curr << std::endl;
        bool canConsonant = true;
        if(curr_idx - 2 >= 0 && curr_idx - 1 >= 0
            && mask[curr_idx-2] == CONSONANT && mask[curr_idx-1] == CONSONANT){canConsonant = false;}
        if(curr_idx - 1 >= 0 && curr_idx + 1 < mask.size() 
            && mask[curr_idx-1] == CONSONANT && mask[curr_idx+1] == CONSONANT){canConsonant = false;}
        if(curr_idx + 1 < mask.size() && curr_idx + 2 < mask.size() 
            && mask[curr_idx+1] == CONSONANT && mask[curr_idx+2] == CONSONANT){canConsonant = false;}
        
        
        if(canConsonant){
            
            mask[curr_idx] = CONSONANT;
            
            values.push_back(VAL_CONSONANT - VAL_L); 
            backtracking(pleasant_words, mask, underscores, values, isL, curr + 1);
            values.pop_back();

            values.push_back(VAL_L); 
            backtracking(pleasant_words, mask, underscores, values, isL || true, curr + 1); 
            values.pop_back();
           
        }
        
        mask[curr_idx] = UNDERSCORE;
    }
    
    
}

int main(){
    
    std::string template_word;
    int i = 0;
    bool isL = false;
    
    char input;
    std::getline(std::cin, template_word);
    
    std::stringstream ss_template(template_word);
    std::vector<int> mask;
    std::vector<int> underscores;
    
    while (ss_template >> input) {
        
        if(vowels.find(input) != vowels.end()){mask.push_back(VOWEL);}
        else if(input == '_'){
            underscores.push_back(i);
            mask.push_back(UNDERSCORE);}
        else if(input == 'L'){
            isL = true;
            mask.push_back(CONSONANT);
        }
        else{mask.push_back(CONSONANT);}
        i++;
    }
    
    underscores.push_back(END);
    
    long long pleasant_words = 0;
    
    std::vector<int> values = {};
    backtracking(pleasant_words,mask,underscores,values,isL,0);
    
    std::cout << pleasant_words << std::endl;
    
    return 0;
}