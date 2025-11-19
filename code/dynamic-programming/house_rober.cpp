/**
 * Problem Statement
 * @source: https://leetcode.com/problems/house-robber/description/
*/

#include <bits/stdc++.h>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        
        int n_casas = nums.size();

        // casos basicos que no necesitan dp
        if(nums.size() == 1){
            return nums[0];
        }

        if(nums.size() == 2){
            return std::max(nums[0], nums[1]);
        }

        // dp 
        std::vector<int> dp_value(n_casas, 0);

        // caso base: El maximo valor que puedo robar en la primera casa es su propio valor
        // Lo mismo para la segunda casa, solo que en esta no se incluye la primera

        dp_value[0] = nums[0];
        dp_value[1] = std::max(nums[1],nums[0]);

        // iteraciones

        for(int curr_idx = 2; curr_idx < n_casas; curr_idx++){

            int curr_house_value = nums[curr_idx];

            dp_value[curr_idx] = std::max(dp_value[curr_idx-1], dp_value[curr_idx-2] + curr_house_value);

        }

        return dp_value[n_casas-1];

    }
};