#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // sort numbers so that the minimum is always the first of the pairs
        int sum = 0;                        // initialize sum variable for output

        for(int i=0;i<nums.size();i+=2){    // loop through sorted nums and increase i by 2 each iteration
            sum += min(nums[i],nums[i+1]);  // add the minimum of the ith index and the index after i to the sum
        }
        return sum;
    }
};

// driver program
int main(){
    // create vectors
    vector<int> v1 = {1,4,3,2};
    vector<int> v2 = {6,2,6,5,1,2};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The maximized sum for all of the minimums in vector 1 is "<<Solution.arrayPairSum(v1)<<'\n';
    cout<<"The maximized sum for all of the minimums in vector 2 is "<<Solution.arrayPairSum(v2)<<'\n';
    return 0;
}