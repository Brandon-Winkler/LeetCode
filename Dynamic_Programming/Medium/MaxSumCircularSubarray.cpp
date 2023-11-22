#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int gloMin = nums[0], gloMax = nums[0];
        int curMin = 0, curMax = 0;
        int sum = 0;

        for(int i=0;i<nums.size();++i){
            curMin = min(curMin+nums[i], nums[i]);
            curMax = max(curMax+nums[i], nums[i]);
            gloMin = min(curMin, gloMin);
            gloMax = max(curMax, gloMax);
            sum += nums[i];
        }
        if(gloMax > 0) return max(gloMax, sum-gloMin);
        return gloMax;
    }
};

// driver program
int main(){
    // initialize number vectors
    vector<int> n1 = {1,-2,3,-2};
    vector<int> n2 = {5,-3,5};
    vector<int> n3 = {-3,-2,-3};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The sum of the maximum subarray in the first circular array is "<<Solution.maxSubarraySumCircular(n1)<<'\n';
    cout<<"The sum of the maximum subarray in the second circular array is "<<Solution.maxSubarraySumCircular(n2)<<'\n';
    cout<<"The sum of the maximum subarray in the third circular array is "<<Solution.maxSubarraySumCircular(n3)<<'\n';
    return 0;
}