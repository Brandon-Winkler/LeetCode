#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        
        // if prices are empty or there is only one price then return 0
        if (prices.empty() || prices.size() == 1) return 0;

        // initialize minimum price and max profit
        int minPrice = prices[0];
        int maxProfit = 0;

        // loop through prices to find the minimum and get max profit
        for (int i = 1; i < prices.size(); ++i) {
            int currentPrice = prices[i];
            if (currentPrice < minPrice) {
                minPrice = currentPrice;
            } else {
                int currentProfit = currentPrice - minPrice;
                if (currentProfit > maxProfit)
                    maxProfit = currentProfit;
            }
        }

        // return max profit
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

