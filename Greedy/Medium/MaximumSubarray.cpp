#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];                  // initialize result to first value in vector because it cannot be 0 since we have negative values in vector
        int sum = 0;                        // initialize current sum

        for(int i=0;i<nums.size();++i){     // loop through the vector
            if(sum < 0) sum = 0;            // if the sum is less than 0 reset to 0 so that we can keep the least amount of negative values in the subarray
            sum += nums[i];                 // add current value to sum
            res = max(res, sum);            // set the result to the max between the current result and sum
        }
        return res;
    }
};

// driver program
int main(){
    // initialize nums arrays
    vector<int> n1 = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> n2 = {1};
    vector<int> n3 = {5,4,-1,7,8};
    vector<int> n4 = {1,2,-1,-2,2,1,-2,1,4,-5,4};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The maximum sum in the first array is "<<Solution.maxSubArray(n1)<<'\n';
    cout<<"The maximum sum in the second array is "<<Solution.maxSubArray(n2)<<'\n';
    cout<<"The maximum sum in the third array is "<<Solution.maxSubArray(n3)<<'\n';
    cout<<"The maximum sum in the fourth array is "<<Solution.maxSubArray(n4)<<'\n';
    return 0;
}