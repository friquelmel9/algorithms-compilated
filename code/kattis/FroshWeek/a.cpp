#include <iostream>
#include <queue>

int main(){
    
    unsigned long long t, l;
    std::cin >> t >> l;
    
    std::priority_queue<unsigned long long> task_durations;
    std::priority_queue<unsigned long long> quiet_intervals;        
        
    unsigned long long duration;
    
    for(unsigned long long i=0; i<t; i++){
        std::cin >> duration;
        task_durations.push(duration);
    }
    
    for(unsigned long long i=0; i<l; i++){
        std::cin >> duration;
        quiet_intervals.push(duration);
    }
    
    unsigned long long achieved_task = 0;
    while(!task_durations.empty() && !quiet_intervals.empty()){
        
        // case 1: current largest task can be in the largest interval (mientras quepa en el intervalo)
        
        if(task_durations.top() <= quiet_intervals.top()){
            achieved_task++;
            task_durations.pop();
            quiet_intervals.pop();
        }
        
        // case 2: current largest task can not be in the largest interval
        else{
            task_durations.pop();
        }
        
    }
    
    std::cout << achieved_task;
        
    return 0;
}