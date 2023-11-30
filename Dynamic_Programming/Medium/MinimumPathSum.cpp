#include<vector>
#include<map>
#include<utility>
#include<iostream>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int n, int m, map<pair<int,int>,int>& memo){
        if(i == n-1 && j == m-1) return grid[i][j];             // base case: if we are at the bottom right corner return the value at that corner

        if(memo[{i,j}]) return memo[{i,j}];                     // if the value already exists in memo then return that value

        int ans = 0;                                            // intialize answer to be 0

        if(i+1 < n && j+1 < m){                                 // if we are within the bounds of the grid then set the answer equal to the minimum of the next cell right or next cell down  
            ans = min(
                grid[i][j]+solve(i+1, j, grid, n, m, memo),
                grid[i][j]+solve(i, j+1, grid, n, m, memo)
            );
        }
        else if(i+1 < n){                                       // if the cell down is within bounds of row size then add the current sum to the cell value down
            ans = grid[i][j]+solve(i+1, j, grid, n, m, memo);
        }
        else if(j+1 < m){                                       // if the cell to the right is within the bounds of the column size then add the current sum to the cell value to the right 
            ans = grid[i][j]+solve(i, j+1, grid, n, m, memo);
        }

        memo[{i,j}] = ans;                                      // store current answer value in memory
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();                    // variable for size of rows
        int m = grid[0].size();                 // variable for size of columns
        map<pair<int,int>,int> memo;            // map for memory
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