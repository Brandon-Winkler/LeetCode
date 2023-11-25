#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int target, int i, vector<vector<int>>& res, vector<int>& comb){
        if(i >= nums.size() || target < 0) return;
        if(target == 0){
            res.push_back(comb);
            return;
        }

        comb.push_back(nums[i]);
        backtrack(nums, target-nums[i], i, res, comb);
        comb.pop_back();
        backtrack(nums, target, i+1, res, comb);
    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        backtrack(candidates,target,0,res,comb);
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
    vector<int> v1 = {2,3,6,7};
    vector<int> v2 = {2,3,5};
    vector<int> v3 = {2};

    // solution class instance
    Solution Solution;

    vector<vector<int>> s1 = Solution.combinationSum(v1,7);
    vector<vector<int>> s2 = Solution.combinationSum(v2,8);
    vector<vector<int>> s3 = Solution.combinationSum(v3,1);

    // output
    cout<<"All combinations that add up to 7 of vector one: "<<'\n';
    printVectorOfVectors(s1);
    cout<<'\n';

    cout<<"All combinations that add up to 8 of vector two: "<<'\n';
    printVectorOfVectors(s2);
    cout<<'\n';

    cout<<"All combinations that add up to 1 of vector three: "<<'\n';
    printVectorOfVectors(s3);
    cout<<'\n';

    return 0;
}