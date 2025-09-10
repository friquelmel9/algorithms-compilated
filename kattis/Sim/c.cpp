#include <iostream>
#include <list>


void test_case(std::string line){
    
    int n = line.size();
    
    std::list<char> linkedList;
    std::list<char>::iterator itr = linkedList.begin(); // QUEEEEEEEEE
    char input;
    
    for(int i=0; i<n; i++){
        input = line[i];
        
        switch(input){
            
            case '[':
                //std::cout << "begin" << std::endl;
                itr = linkedList.begin();
                break;
            case ']':
                //std::cout << "end" << std::endl;  
                itr = linkedList.end();
                break;
            case '<':
                //std::cout << "erase" << std::endl;
                if(itr!=linkedList.begin()) {itr = linkedList.erase(--itr); }
                break;
            default:
                //std::cout << "insert" << std::endl;
                linkedList.insert(itr,input);
                break;
        }
    }
    
    itr = linkedList.begin();
    while(itr != linkedList.end()){
        std::cout << *itr;
        itr++;
    }
    std::cout << std::endl;
}

int main(){
    
    int k;
    std::cin >> k;
    
    std::string line;
    std::cin.ignore();
    
    for(int i=0; i<k; i++){
        getline(std::cin, line);
        test_case(line);
    }
    
    return 0;
    
}