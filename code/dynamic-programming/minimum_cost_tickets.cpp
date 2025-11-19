/**
 * Problem Statement
 * @source: https://leetcode.com/problems/minimum-cost-for-tickets/submissions/1834687714/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n_travels = days.size();
        
        int one_day_pass = costs[0];
        int seven_day_pass = costs[1];
        int thirty_day_pass = costs[2];

        // dp

        std::vector<int> dp_costs(365 + 1, INT_MAX);
        std::vector<bool> isTravel(365 + 1, false);

        // Inicializacion

        // Viajar 0 dias es 0 costo
        dp_costs[0] = 0;

        // Guardar los dias que debemos viajar
        for(int day : days){
            isTravel[day] = true;
        }

        // Iteraciones

        for(int curr_day = 1; curr_day <= 365; curr_day++){

            if(!isTravel[curr_day]){
                dp_costs[curr_day] = dp_costs[curr_day-1];
            }

            else{

                dp_costs[curr_day] = std::min((dp_costs[curr_day-1]+one_day_pass), (dp_costs[std::max(0,curr_day-7)]+seven_day_pass));
                dp_costs[curr_day] = std::min(dp_costs[curr_day], (dp_costs[std::max(0,curr_day-30)]+thirty_day_pass));

            }

        }

        return dp_costs[365];

        

    }
};