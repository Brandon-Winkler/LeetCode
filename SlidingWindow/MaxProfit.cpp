#include <vector>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        // if prices are empty or there is only one price then return 0
        if (prices.empty() || prices.size() == 1) return 0;

        // initialize minimum price and max profit
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i=1;i<prices.size();++i){
            int currentPrice = prices[i]; // set current prince to prices at i to compare right side of window to left side
            if (currentPrice < minPrice){ // case where right side of window is less than left side
                minPrice = currentPrice; // set min price to current price to increment left side of window
            } 
            else{ // case where right side of window is greater than left side
                int currentProfit = currentPrice - minPrice; // set current profit to right side minus left side
                if (currentProfit > maxProfit) maxProfit = currentProfit; // if current profit is greater than max profit set max equal to current
            }
        }
        return maxProfit;
    }
};

int main() {

    // initialize vector of prices
    std::vector<int> prices = {7,2,8,1,6,3,10};

    // create class instance
    Solution Solution;

    //print result
    std::cout << Solution.maxProfit(prices) << '\n';

    return 0;
}

