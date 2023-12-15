#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);                         // initialize vector to be the capacity of amount and fill it with the ammount plus one

        dp[0] = 0;                                                  // set first value in vector to be zero

        for(int n=1;n<=amount;++n) for(int c=0;c<coins.size();++c){ // loop through the amount starting at 1 and size of coin vector
            /* 
            if the current amount minus the current coin is greather than or equal to zero 
            then set vector at the amount index to minimum between the current amount at index 
            and the index of the current amount minus the current coin plus 1
            */
            if(n-coins[c] >= 0) dp[n] = min(dp[n], dp[n-coins[c]]+1);
        }
        if(dp[amount] == amount+1) return -1;                       // if the vector at the amount index is equal to amount plus one return -1
        return dp[amount];                                          // otherwise return the value at the amount index of the vector
    }
};

// driver program
int main(){
    // initialize coin arrays
    vector<int> v1 = {1,2,5};
    vector<int> v2 = {1,2,5,10,25};
    
    // solution class instance
    Solution Solution;

    // output
    cout<<"The minimum number of coins to make 11 in vector one is "<<Solution.coinChange(v1,11)<<'\n';
    cout<<"The minimum number of coins to make 47 in vector two is "<<Solution.coinChange(v2,47)<<'\n';
    return 0;
}