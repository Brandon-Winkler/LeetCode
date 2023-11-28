#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
    }
};

// driver program
int main(){
    // initialize vectors
    vector<int> v1 = {2,2,2,2,5,5,5,8};
    vector<int> v2 = {11,13,17,23,29,31,7,5,2,3};

    // solution class instance
    Solution Solution;

    // output
    cout<<"The number subarrays with size 3 and a threshold of 4 for vector 1 are: "<<Solution.numOfSubarrays(v1,3,4)<<'\n';
    cout<<"The number subarrays with size 3 and a threshold of 5 for vector 2 are: "<<Solution.numOfSubarrays(v2,3,5)<<'\n';
    return 0;
}