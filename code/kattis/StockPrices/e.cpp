#include <iostream>
#include <queue>


struct Stock{
    int price;
    int quantity;
    bool operator<(const Stock& rhs) const{ return price < rhs.price; }
};

void stock_market(std::priority_queue<Stock> &offers, std::priority_queue<Stock> &demands, int &stockPrice){
    
    while(!offers.empty() && !demands.empty()){
        
        Stock askStock = offers.top();
        askStock.price = -askStock.price;
        Stock bidStock = demands.top();
        
        // deal only if bidPrice>=askPrice
        if(bidStock.price < askStock.price) {break;}
        stockPrice = askStock.price;
        
        if(askStock.quantity > bidStock.quantity){
            askStock.quantity = askStock.quantity - bidStock.quantity;
            bidStock.quantity = 0;
        }
        else if(bidStock.quantity > askStock.quantity){
            bidStock.quantity = bidStock.quantity - askStock.quantity;
            askStock.quantity = 0;
        } 
        else{
            askStock.quantity = 0;
            bidStock.quantity = 0;
        }
        
        offers.pop();
        demands.pop();
        
        if(askStock.quantity > 0){
            askStock.price = -askStock.price;
            offers.push(askStock);
        }
        if(bidStock.quantity > 0){
            demands.push(bidStock);
        }
        
    }
    
    
}

void test_case(){
    
    int n;
    std::cin >> n;
    
    // Input
    
    std::string input;
    int stockPrice = -1;
    
    std::priority_queue<Stock> offers; // I offer x value for y, I sell, askPrice. Ask price in negative because priority queue.
    std::priority_queue<Stock> demands; // I demand y for x price, I buy, bidPrice
    
    for(int i=0; i<n; i++){
        
        bool isOffer = false;
        
        std::cin >> input;
        if(input == "sell"){isOffer = true; }
        
        Stock current;
        
        std::cin >> current.quantity;
        std::cin >> input; std::cin >> input;
        std::cin >> current.price;
        
        
        if(isOffer){
            current.price = -current.price;
            offers.push(current);
        }
        else{demands.push(current);}
        
        stock_market(offers, demands, stockPrice);
        
        // output
        
        if(!offers.empty()){std::cout << -offers.top().price;}
        else{std::cout << "-"; }
        std::cout << " ";
        
        if(!demands.empty()){std::cout << demands.top().price;}
        else{std::cout << "-"; }
        std::cout << " ";
        
        if(stockPrice != -1){std::cout << stockPrice;}
        else{std::cout << "-"; }
        std::cout << std::endl;
    }
    
}

int main(){
    
    int k;
    std::cin >> k;
    
    for(int i=0; i<k; i++){test_case();}
}