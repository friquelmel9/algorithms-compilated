#include <bits/stdc++.h>

#define ll long long

struct Worker{
    ll arrive_time;
    ll duration;
};

struct Workstation{
    ll start;
    ll end;
};



int main(){
    
    ll n, m;
    std::cin >> n >> m;
    
    std::priority_queue<ll> inactive_time;
    std::vector<Worker> workers;
    
    for(int i=0; i<n; i++){
        
        ll arrive_time, duration;
        std::cin >> arrive_time >> duration;
        
        Worker worker;
        worker.arrive_time = arrive_time;
        worker.duration = duration;
        
        workers.push_back(worker);
        
    }
        
    std::sort(workers.begin(), workers.end(), [](const Worker&a, const Worker&b){
        return a.arrive_time < b.arrive_time;
    });
    
    ll unlockings_saved = 0;
    
    for(int i=0; i<n; i++){
        
        ll curr_workstation;
        Worker curr_worker = workers[i];
        
        while(!inactive_time.empty()){
            
            ll curr_workstation_inactive = -inactive_time.top();
            
            // no activity has started the inactive period
            if(curr_workstation_inactive > curr_worker.arrive_time){
                break;
            }
            
            // In the inactive period
            else if(curr_workstation_inactive <= curr_worker.arrive_time && curr_worker.arrive_time <= curr_workstation_inactive+m){
                unlockings_saved++;
                inactive_time.pop();
                break;
            }
            
            // inactive_time already ended
            else{
                inactive_time.pop();
            }
            
        }
        
        curr_workstation = curr_worker.arrive_time + curr_worker.duration;
        inactive_time.push(-curr_workstation);
        
        
        
    }
    
    std::cout << unlockings_saved << std::endl;
    
    return 0;
}