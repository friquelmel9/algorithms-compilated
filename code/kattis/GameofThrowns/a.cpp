#include <iostream>
#include <string>
#include <stack>

// Digamos 3 % 5 


void ThrowEgg(int &holder, int throws, int n){
    int next = ((holder + throws) % n + n) % n;
    holder = next;
}

int main(){
    
    int n;
    int k;
    
    std::cin >> n;
    std::cin >> k;
    
    int holder = 0; 
    std::string command;
    int throws; 
    int undo; 
    std::stack<int> undo_stack;
    
    for(int i=0; i<k; i++){
        std::cin >> command;
        
        if(command == "undo"){
            
            std::cin >> undo;
            for(int j=0; j<undo; j++){
                ThrowEgg(holder,undo_stack.top(),n);
                undo_stack.pop();
            }
        }
        else{
            throws = std::stoi(command);
            ThrowEgg(holder,throws,n);
            undo_stack.push(-throws);
        }
        
    }
    
    std::cout << holder;
    
    return 0;
}