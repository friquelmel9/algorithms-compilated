#include <iostream>


struct Node{
    char value;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class LinkedList{
    
    private:
        Node* head;
        Node* tail;
        Node* curr; // Cursor 
        int size;
        bool isHome;
    
    public:
        
        LinkedList(){
            head = tail = curr = nullptr;
            size = 0;
            isHome = false;
        }
        
        ~LinkedList(){
            curr = head;
            Node* tmp;
            while(curr != nullptr){
                tmp = curr->next;
                delete curr;
                curr = tmp;
            }
        }
        
        void move_to_head(){
            if(size == 0){return;}
            curr = head;
            isHome = true;
        }
        
        void move_to_tail(){
            curr = tail;
        }
        
        void erase(){
            std::cout << "erase" << std::endl;
            if(curr == nullptr || size==0){ return; }
            if(isHome){ return; }
            
            Node* tmpRight = curr->next;
            Node* tmpLeft = curr->prev;
            
            if(tmpLeft == nullptr){
                tmpRight->prev = nullptr;
                head = tmpRight;
                isHome = true;
            }
            
            if(tmpRight == nullptr){
                tmpLeft->next = nullptr;
                tail = tmpLeft;
            }
            
            if(tmpLeft != nullptr){tmpLeft->next = tmpRight;}
            if(tmpRight != nullptr){tmpRight->prev = tmpLeft;}
            delete curr;
            size--;
            
            if(isHome){
                curr = head;
            }
            else{
                curr = tmpLeft;
            }
            
        }
        
        void insert(char value){
            std::cout << "insert" << std::endl;
            Node* tmp = new Node;
            tmp->value = value;
            
            if(size == 0){
                head = tail = curr = tmp;
                size++;
            }
            else{
                if(isHome){ // 1
                    curr->prev = tmp;
                    tmp->next = curr;
                    tmp->prev = nullptr;
                    curr = tmp;
                    head = curr;
                    isHome = false;
                }
                else{
                    curr->next = tmp;
                    tmp->prev = curr;
                    curr = tmp;
                }
                size++;
            }
            
            
        }
    
        void print(){
            std::cout << "print" << std::endl;
            Node* tmp = head;
            while(tmp != nullptr){
                std::cout << tmp->value;
                tmp = tmp->next;
            }
            std::cout << std::endl;
            inverse_print();
        }
        
        void inverse_print(){
            std::cout << "print inverse" << std::endl;
            Node* tmp = tail;
            while(tmp != nullptr){
                std::cout << tmp->value;
                tmp = tmp->prev;
            }
            std::cout << std::endl;
        }
};

void test_case(std::string line){
    
    int n = line.size();
    
    LinkedList linkedList;
    char input;
    
    for(int i=0; i<n; i++){
        input = line[i];
        
        switch(input){
            
            case '[':
                linkedList.move_to_head();
                break;
            case ']':
                linkedList.move_to_tail();
                break;
            case '<':
                linkedList.erase();
                break;
            default:
                linkedList.insert(input);
                break;
        }
    }
    
    linkedList.print();
    
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