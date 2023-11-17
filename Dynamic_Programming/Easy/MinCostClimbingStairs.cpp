#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();                        // set variable to size of stairs
        vector<int> dp(n+3,0);                      // set vector to be size of stairs plus 3 so that there is no out of bounds and fill with 0's
        for(int i=n-1;i>=0;--i){                    // loop through vector starting at the size of the stairs vector minus one
            dp[i] = cost[i]+min(dp[i+1], dp[i+2]);  // set the ith value in vector to me the cost at ith index plus the minimum of the vector at ith plus one index and ith plus to index
        }
        return min(dp[0], dp[1]);                   // return the minimum of the values at 0 or 1st index
    }
};

// driver program
int main(){
    // initialize stairs
    vector<int> v1 = {10,15,20};
    vector<int> v2 = {1,100,1,1,1,100,1,1,100,1};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The minimum cost for the first flight of stairs is "<<Solution.minCostClimbingStairs(v1)<<'\n';
    cout<<"The minimum cost for the second flight of stairs is "<<Solution.minCostClimbingStairs(v2)<<'\n';
    return 0;
}