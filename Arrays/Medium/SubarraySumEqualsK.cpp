#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
    }
};

// driver program
int main(){
    // initalize arrays
    vector<int> a1 = {1,1,1};
    vector<int> a2 = {1,2,3};
    vector<int> a3 = {1,-1,0};
    vector<int> a4 = {1};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The number of subarrays whose sum is equal to 2 for array 1 is "<<Solution.subarraySum(a1,2)<<'\n';
    cout<<"The number of subarrays whose sum is equal to 3 for array 2 is "<<Solution.subarraySum(a2,3)<<'\n';
    cout<<"The number of subarrays whose sum is equal to 0 for array 3 is "<<Solution.subarraySum(a3,0)<<'\n';
    cout<<"The number of subarrays whose sum is equal to 1 for array 4 is "<<Solution.subarraySum(a3,1)<<'\n';
    return 0;
}