#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int r1 = 0;                             // variable to keep track of first previous sum
        int r2 = 0;                             // variable to keep track of second previous sum
        for(int i=0;i<nums.size();++i){         // loop through nums
            int temp = max(nums[i]+r1, r2);     // store the max of current value at ith index plus first previous value and second previous value
            r1 = r2;                            // update first to second
            r2 = temp;                          // and update second to current max
        }
        return r2;                              // return current max
    }
};

// driver program
int main(){
    // initialize house vectors
    vector<int> h1 = {1,2,3,1};
    vector<int> h2 = {1};
    vector<int> h3 = {2,1,1,2};
    vector<int> h4 = {1,3,6,2,8,9,11,1,2,3};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The max we can get from neighborhood one is "<<Solution.rob(h1)<<'\n';
    cout<<"The max we can get from neighborhood two is "<<Solution.rob(h2)<<'\n';
    cout<<"The max we can get from neighborhood three is "<<Solution.rob(h3)<<'\n';
    cout<<"The max we can get from neighborhood four is "<<Solution.rob(h4)<<'\n';
    
    return 0;
}