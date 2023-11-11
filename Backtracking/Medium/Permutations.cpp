#include<vector>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, map<int,bool>& map, vector<vector<int>>& res, vector<int>& state){
        if(state.size() == nums.size()) res.push_back(state);   // if our current vector is the same size as nums push it into the result

        for(int n=0;n<nums.size();++n){                         // iterate through all possible options
            if(map[nums[n]]) continue;                          // if value at nth index already exists in map do nothing

            map[nums[n]] = true;                                // otherwise put value into map and mark as true
            state.push_back(nums[n]);                           // push the current value into state vector

            backtrack(nums, map, res, state);                   // recurse through nums

            state.pop_back();                                   // remove last value added to backtrack
            map[nums[n]] = false;                               // set value in map to false to mark that we haven't seen it
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,bool> map;                                      // map so that we know if we have seen the value in nums
        vector<int> state;                                      // state vector to keep track of permutations
        vector<vector<int>> res;                                // result vector for output
        backtrack(nums, map, res, state);
        return res;
    }
};

// Utility fuction to print vector of vectors
void printVectorOfVectors(const vector<vector<int>>& vec) {
    for(const vector<int>& innerVec : vec){
        for(int num : innerVec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

// driver program
int main(){
    // initialize vectors
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1};
    vector<int> v3 = {0,1,2,3,4};

    // solution class instance
    Solution Solution;

    vector<vector<int>> s1 = Solution.permute(v1);
    vector<vector<int>> s2 = Solution.permute(v2);
    vector<vector<int>> s3 = Solution.permute(v3);

    // outputs
    cout<<"All permutations of vector one: "<<'\n';
    printVectorOfVectors(s1);
    cout<<'\n';

    cout<<"All permutations of vector two: "<<'\n';
    printVectorOfVectors(s2);
    cout<<'\n';

    cout<<"All permutations of vector three: "<<'\n';
    printVectorOfVectors(s3);
    cout<<'\n';

    return 0;
}