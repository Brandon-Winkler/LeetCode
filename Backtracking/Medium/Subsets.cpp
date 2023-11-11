#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;            // vector for subsets
        vector<vector<int>> res;    // vector for output
        dfs(nums, 0, cur, res);     // backtracking dfs for finding subsets
        return res;
    }
private:
    void dfs(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);                     // push current subset into result vector
        for(int i=start;i<nums.size();++i){     // loop through nums
            cur.push_back(nums[i]);             // push current index into subset
            dfs(nums, i+1, cur, res);           // resursively find subsets
            cur.pop_back();                     // pop from current subset to backtrack
        }
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
    // intialize vectors
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {0};
    vector<int> v3 = {1,3,2,2,4,1};

    // solution class instance
    Solution Solution;

    vector<vector<int>> s1 = Solution.subsets(v1);
    vector<vector<int>> s2 = Solution.subsets(v2);
    vector<vector<int>> s3 = Solution.subsets(v3);

    // output
    cout<<"The subsets for vector one are: "<<'\n';
    printVectorOfVectors(s1);
    cout<<'\n';
    cout<<"The subsets for vector two are: "<<'\n';
    printVectorOfVectors(s2);
    cout<<'\n';
    cout<<"The subsets for vector three are: "<<'\n';
    printVectorOfVectors(s3);
    cout<<'\n';
    return 0;
}