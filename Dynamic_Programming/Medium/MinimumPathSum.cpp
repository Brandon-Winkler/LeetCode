#include<vector>
#include<map>
#include<utility>
#include<iostream>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int n, int m, map<pair<int,int>,int>& memo){
        if(i == n-1 && j == m-1) return grid[i][j];

        if(memo[{i,j}]) return memo[{i,j}];

        int ans = 0;

        if(i+1 < n && j+1 < m){  
            ans = min(
                grid[i][j]+solve(i+1, j, grid, n, m, memo),
                grid[i][j]+solve(i, j+1, grid, n, m, memo)
            );
        }
        else if(i+1 < n){
            ans = grid[i][j]+solve(i+1, j, grid, n, m, memo);
        }
        else if(j+1 < m){
            ans = grid[i][j]+solve(i, j+1, grid, n, m, memo);
        }

        memo[{i,j}] = ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<pair<int,int>,int> memo;
        return solve(0, 0, grid, n, m, memo);
    }
};

// driver program
int main(){
    // initialize grids
    vector<vector<int>> g1 = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    vector<vector<int>> g2 = {
        {1,2,3},
        {4,5,6}
    };

    // solution class instance
    Solution Solution;

    // output
    cout<<"The minimum path sum for grid 1 is "<<Solution.minPathSum(g1)<<'\n';
    cout<<"The minimum path sum for grid 2 is "<<Solution.minPathSum(g2)<<'\n';
    return 0;
}