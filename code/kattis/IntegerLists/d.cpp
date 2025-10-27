#include <iostream>
#include <deque>
#include <string>

std::string BACP(std::string program, int n, std::string inputArray){
    
    std::deque<int> array;
    
    // Read
    if(n != 0){
        std::string value;
        for(int i=0; i<inputArray.size(); i++){
            if(std::isdigit(inputArray[i])) {value.push_back(inputArray[i]);}
            else{
                if(!value.empty()){
                    array.push_back(std::stoi(value));
                    value.clear();
                }
            }
        }
        if (!value.empty()) {
            array.push_back(std::stoi(value));
        }
    }
    
    char input;
    bool reversed = false;
    
    // BACP
    
    for(int i=0; i<program.size(); i++){
        input = program[i];
        if(input == 'D'){
            if(array.size() <= 0){return "error";}
            if(reversed){
                array.pop_back();
                n--;
            }
            else{
                array.pop_front();
                n--;
            }
        }
        if(input == 'R'){
            reversed = !reversed;
        }
    }
    
    // Output
    
    std::string output;
    
    output.append("[");
    for(int i=0; i<n; i++){
        if(reversed){
            output.append(std::to_string(array.back()));
            array.pop_back();
        }
        else{
            output.append(std::to_string(array.front()));
            array.pop_front();
        }
        if(i!=n-1){output.append(",");}
    }
    output.append("]");
    
    return output;
}

int main(){
    
    int k;
    std::cin >> k;
    
    std::string program;
    int n;
    std::string inputArray;
    std::string result;
        
    for(int i=0; i<k; i++){
        
        std::cin >> program;
        std::cin >> n;
        std::cin >> inputArray;
        
        result = BACP(program,n,inputArray);
        std::cout << result << std::endl;
    }
    
    return 0;
}