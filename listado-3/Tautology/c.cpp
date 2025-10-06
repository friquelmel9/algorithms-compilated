#include <iostream>
#include <string>
#include <unordered_set>
#include <bitset>

#define P 0
#define Q 1
#define R 2
#define S 3
#define T 4

std::unordered_set<char> operators = {'K','A','N','C','E'};
std::unordered_set<char> variables = {'p','q','r','s'};


bool evaluateExpression(std::string wff, int &curr_idx){
    
    char expression = wff[curr_idx]; // current expression, can be operator or variable evaluated
    curr_idx++;
    
    if(expression == 'N'){
        bool operand1 = evaluateExpression(wff,curr_idx);
        return !operand1;
    }
    
    else if(operators.find(expression) != operators.end()){ 
        
        bool operand1 = evaluateExpression(wff, curr_idx);
        bool operand2 = evaluateExpression(wff, curr_idx);
        
        switch(expression){
            case 'K':
                return operand1 && operand2; break;
            case 'A':
                return operand1 || operand2; break;
            case 'C':
                return !operand1 || operand2; break;
            case 'E':
                return operand1 == operand2; break;
        }
    }
    
    else{
        if(expression == '1'){
            return true;
        }
        if(expression == '0'){
            return false;
        }
    }
    
}

std::string setValues(std::string wff, bool p, bool q, bool r, bool s, bool t){
    
    for(int i=0; i<wff.size(); i++){
        
        switch(wff[i]){
            case 'p':
                wff[i] = p ? '1': '0'; break;
            case 'q':
                wff[i] = q ? '1': '0'; break;
            case 'r':
                wff[i] = r ? '1': '0'; break;
            case 's':
                wff[i] = s ? '1': '0'; break;
            case 't':
                wff[i] = t ? '1': '0'; break;
            default: break;
        }
        
    }
    
    return wff;
}

bool isTautology(std::string wff){
    
    int i = 0;
    int index;
    bool tautology = true;
    
    while(i < 32){
        
        std::bitset<5> values(i);
        index = 0;
        
        std::string evaluatedWFF = setValues(wff, values[P], values[Q], values[R], values[S], values[T]);
        bool result = evaluateExpression(evaluatedWFF, index);
        
        if(!result){tautology = false; break;}
        
        i++;
    }
    
    return tautology;
    
}

int main(){
    
    std::string input;
    
    do{
        
        
        std::cin >> input;
        
        if(input == "0"){break;}
        
        if(isTautology(input)){
            std::cout << "tautology" << std::endl;
        }
        else{
            std::cout << "not" << std::endl;
        }

        
    } while(input != "0");
    
    
    return 0;
}