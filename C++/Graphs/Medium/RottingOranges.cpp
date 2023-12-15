#include<vector>
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>> que, int sum){
        int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // directional vector to traverse matrix

        while(!que.empty()){
            ++sum;                                      // increment sum at each level of que
            int queSize = que.size();                   // initialize the que size variable to only traverse on current level

            for(int q=0;q<queSize;++q){
                pair<int,int> cell = que.front();       // set cell variable to front of que to begin bfs
                que.pop();                              // pop from que to continue traversal
                int r = cell.first;                     // set row variable
                int c = cell.second;                    // set column variable

                for(int i=0;i<4;++i){                   // to traverse loop through directional vector
                    int adjr = r+dir[i][0];             // add row variable to ith index at 0 to find adjacent row
                    int adjc = c+dir[i][1];             // add column variable to ith index at 1 to find adjacent column

                    if(                                 // only traverse if..
                        adjr >= 0 &&                    // adjacent row is greater than or equal to 0
                        adjc >= 0 &&                    // adjacent column is greater than or equal to 0
                        adjr < grid.size() &&           // adjacent row is less than row size
                        adjc < grid[0].size() &&        // adjacent column is less than column size
                        grid[adjr][adjc] != 0 &&        // adjacent index is not equal to 0 
                        grid[adjr][adjc] != 2           // adjacent index is not equal to 2
                    ){
                        que.push({adjr,adjc});          // push adjacent index onto que
                        grid[adjr][adjc] = 2;           // set adjacent value to 2 to mark visited
                    }
                }
            }
        }
        return sum;                                     // return minutes
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;                                                            // answer variable for output
        int count = 0;                                                          // count variable for edge case where matrix is only 0's
        queue<pair<int,int>> indices;                                           // que of indices for bfs

        for(int r=0;r<grid.size();++r) for(int c=0;c<grid[0].size();++c){
            if(grid[r][c] != 0) ++count;                                        // count all elements not equal to zero in matrix
        }

        if(count == 0) return 0;                                                // if matrix is filled with 0's return 0

        for(int r=0;r<grid.size();++r) for(int c=0;c<grid[0].size();++c){
            if(grid[r][c] == 2) indices.push({r,c});                            // push indices with a value of 2 onto que
        }

        ans = bfs(grid, indices, ans);                                          // set answer to return value of bfs

        for(int r=0;r<grid.size();++r) for(int c=0;c<grid[0].size();++c){
            if(grid[r][c] == 1) return -1;                                      // if there is even a single 1 in matrix after bfs we return -1
        }

        return ans-1;                                                           // otherwise return the answer minus to 1 to account for 0 based
    }
};

int main(){
    // initialize grids
    vector<vector<int>> o1 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

     vector<vector<int>> o2 = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };

    vector<vector<int>> o3 = {
        {0,2}
    };

    // solution class instance
    Solution Solution;

    // outputs
    cout<<"The number of minutes for all oranges to rot for first grid is: "<<Solution.orangesRotting(o1)<<'\n';
    cout<<"The second grid will always have one orange that doesn't rot: "<<Solution.orangesRotting(o2)<<'\n';
    cout<<"The number of minutes for all oranges to rot for third grid is: "<<Solution.orangesRotting(o3)<<'\n';
    
    return 0;
}
