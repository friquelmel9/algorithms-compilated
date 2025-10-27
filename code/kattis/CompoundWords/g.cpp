#include <iostream>
#include <string>
#include <sstream>
#include <set>

void compound_words_generator(std::set<std::string> &words, std::set<std::string> &compoundWords){
    std::set<std::string>::iterator itr1;
    std::set<std::string>::iterator itr2;
    std::string compoundWord;
    
    for(itr1 = words.begin(); itr1 != words.end(); itr1++){
        itr2 = itr1;
        itr2++;
        for(itr2 = words.begin(); itr2 != words.end(); itr2++){
            if(*itr1 == *itr2) {continue;}
            compoundWord.clear();
            compoundWord.append(*itr1);
            compoundWord.append(*itr2);
            compoundWords.insert(compoundWord);
            compoundWord.clear();
            compoundWord.append(*itr2);
            compoundWord.append(*itr1);
            compoundWords.insert(compoundWord);
        }
    }
}

int main(){
    
    std::set<std::string> words;
    std::string word;
    std::string line;
    
    
    while(std::getline(std::cin, line)){
        std::istringstream iss(line);
        while(std::getline(iss,line,' ')){
            words.insert(line);
        }
    }
    
    std::set<std::string> compoundWords;
    compound_words_generator(words,compoundWords);
    
    // https://www.geeksforgeeks.org/cpp/different-ways-to-iterate-over-a-set-in-c/
    
    std::set<std::string>::iterator itr;
    for(itr = compoundWords.begin(); itr != compoundWords.end(); itr++){std::cout << *itr << std::endl;}
    
    return 0;
}