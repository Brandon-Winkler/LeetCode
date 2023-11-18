#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;

        for(int n=1;n<=amount;++n) for(int c=0;c<coins.size();++c){
            if(n-coins[c] >= 0) dp[n] = min(dp[n], dp[n-coins[c]]+1);
        }
        if(dp[amount] == amount+1) return -1;
        return dp[amount];
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