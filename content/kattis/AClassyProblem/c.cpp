#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

struct Person{
    std::string name;
    std::string clase; // class is a blocked term
};

int main(){
    
    int t;
    std::cin >> t;
    
    for(int i=0; i<t; i++){
        
        int n;
        std::cin >> n;
        
        std::string name, classes;
        std::vector<Person> people; 
        
        // store each person on people
        for(int i=0; i<n; i++){
            std::cin >> name;
            name.pop_back(); 
            
            std::cin >> classes;
            people.push_back({name,classes});
            
            std::cin >> name; // class end
        }
        
        // Comparation using sort std, with lambda function
        std::sort(people.begin(), people.end(), [](const Person&a, const Person&b){
            // compare all classes
            std::stringstream ss_a(a.clase), ss_b(b.clase);
            std::string subclass_a, subclass_b;
            std::vector<std::string> allClases_a, allClases_b;
            
            while(std::getline(ss_a, subclass_a, '-')){
                allClases_a.push_back(subclass_a);
            }
            while(allClases_a.size() != 10){
                allClases_a.insert(allClases_a.begin(), "middle");
            }
            
            while(std::getline(ss_b, subclass_b, '-')){
                allClases_b.push_back(subclass_b);
            }
            while(allClases_b.size() != 10){
                allClases_b.insert(allClases_b.begin(), "middle");
            }
            
            for(int i=9; i>=0; i--){
                int value_a, value_b;
                if(allClases_a[i] == "upper"){value_a = 3;}
                if(allClases_a[i] == "middle"){value_a = 2;}
                if(allClases_a[i] == "lower"){value_a = 1;}
                
                if(allClases_b[i] == "upper"){value_b = 3;}
                if(allClases_b[i] == "middle"){value_b = 2;}
                if(allClases_b[i] == "lower"){value_b = 1;}
                
                if(value_a != value_b){
                    return value_a > value_b;
                }
            }
            
            return a.name < b.name;
            
        });
        
        for(int i=0; i<n; i++){
            std::cout << people[i].name << std::endl;
        }
        std::cout << "==============================" << std::endl;
        
    }
    
    return 0;
}