/** Problem Statement
A friend of yours who is working as a waiter has a problem. A group of xkcd-fans have started to come to the restaurant and order food as in the comic strip below. 
Each order takes him a lot of time to figure out, but maybe you can help him.

Task

You are to write a program that finds out what was ordered given the total cost of the order and the cost of each item on the menu.

Input

The input starts with a line containing one integer nn (1≤n≤100), the number of items on the menu. 
The next line contains nn space-separated positive integers c1,c2,…,cn​, denoting the cost of each item on the menu in Swedish kronor. 
No item costs more than 1000 SEK.

This is followed by a line containing mm (1≤m≤1 0001≤m≤1000), the number of orders placed, and a line with mm orders. 
Each order is given as an integer ss (1≤s≤30000), the total cost of all ordered items in SEK.

Output

For each order in the input output one line as follows. 
If there is one unique order giving the specified total cost, output a space-separated list of the numbers of the items on that order in ascending order. 
If the order contains more than one of the same item, print the corresponding number the appropriate number of times. 
The first item on the menu has number 1, the second 2, and so on.

If there doesn’t exist an order that gives the specified sum, output Impossible. 
If there are more than one order that gives the specified sum, output Ambiguous.

Sample 1:

Input:
3
4 5 8
3
11 13 14

Output:
Impossible
Ambiguous
1 2 2

Input:
6
215 275 335 355 420 580
1
1505

Output
Ambiguous

 * @source: https://vjudge.net/contest/761487#problem/B
*/

#include <bits/stdc++.h>

#define ll long long

#define IMPOSSIBLE 0
#define UNIQUE 1
#define AMBIGOUS 2

/**
 * Reconstruye 
 * 
 * @param items_costs Vector que incluye los datos de costo de cada item en el menu
 * @param dp_reconstruction Vector que incluye los datos del ultimo item ingresado en una respuesta unica
 * @param curr_order Valor de la orden a reconstruir
 * 
 * @return String con el formato de la respuesta
 */
std::string reconstruction(std::vector<ll> &items_costs, std::vector<ll> &dp_reconstruction, ll curr_order){
    
    ll curr_cost = curr_order;
    std::vector<ll> solution_items;
    
    
    while(curr_cost > 0) {
        
        ll curr_item = dp_reconstruction[curr_cost];
        
        solution_items.push_back(curr_item);
        
        curr_cost -= items_costs[curr_item-1];
    }
    
    
    std::reverse(solution_items.begin(), solution_items.end());
    
    std::string solution = "";
    
    for(ll i=0; i<solution_items.size(); i++){
        
        solution = solution + std::to_string(solution_items[i]) + " ";
        
    }
    
    solution.pop_back();

    
    return solution;
}

/**
 * Realiza el proceso de programación dinamica mediante tabulacion
 * 
 * @param items_costs Vector que arregla los valores de costo de cada item
 * @param orders_values Vector que guarda los valores de las ordenes
 * @param dp_values Vector que guarda el estado posible de cada precio
 * @param dp_reconstruction Vector que incluye los datos del ultimo item ingresado en una respuesta unica
 * @param max_order Valor de la maxima orden a pedir (corresponde tambien al tamaño de dp_values)
 */
void tabulation(std::vector<ll> &items_costs, std::vector<ll> &orders_values, std::vector<ll> &dp_values, std::vector<ll> &dp_reconstruction, ll max_order){
    
    dp_values[0] = UNIQUE;
    
    for(ll curr_item = 1; curr_item <= items_costs.size(); curr_item++){
        ll curr_item_value = items_costs[curr_item-1];
        
        for(ll curr_cost = curr_item_value; curr_cost <= max_order; curr_cost++){
            
            ll prev_cost = curr_cost-curr_item_value;
            
            if(dp_values[prev_cost] != IMPOSSIBLE){
                
                if(dp_values[prev_cost] == AMBIGOUS || dp_values[curr_cost] == AMBIGOUS) {dp_values[curr_cost] = AMBIGOUS;}
                else if(dp_values[prev_cost] == UNIQUE){
                    
                    if(dp_values[curr_cost] == IMPOSSIBLE){
                        dp_values[curr_cost] = UNIQUE;
                        dp_reconstruction[curr_cost] = curr_item;
                    }
                    else if(dp_values[curr_cost] == UNIQUE){
                        dp_values[curr_cost] = AMBIGOUS;
                    }
                }
            }
        }
    }
}

/**
 * Realiza la función
 */
void restaurantOrders(){
    
    ll n_items;
    std::cin >> n_items;
    
    std::vector<ll> items_costs(n_items);
    for(ll i=0; i<n_items; i++){std::cin >> items_costs[i];}
    
    ll m_orders;
    std::cin >> m_orders;
    
    ll max_order = LLONG_MIN;
    std::vector<ll> orders_values(m_orders);
    
    for(ll curr_order=0; curr_order<m_orders; curr_order++){
        std::cin >> orders_values[curr_order];
        max_order = std::max(max_order, orders_values[curr_order]);
    }
    
    std::vector<ll> dp_values(max_order+1,IMPOSSIBLE);
    std::vector<ll> dp_reconstruction(max_order+1,-1);
    
    tabulation(items_costs,orders_values,dp_values,dp_reconstruction,max_order);
    
    for(ll curr_order = 0; curr_order < m_orders; curr_order++){
        
        switch(dp_values[orders_values[curr_order]]){
            case IMPOSSIBLE:
                std::cout << "Impossible" << std::endl;
                break;
            case UNIQUE:
                std::cout << reconstruction(items_costs,dp_reconstruction,orders_values[curr_order]) << std::endl;
                break;
            case AMBIGOUS:
                std::cout << "Ambiguous" << std::endl;
                break;
        }
    }
}

int main(){
    restaurantOrders();
    return 0;
}