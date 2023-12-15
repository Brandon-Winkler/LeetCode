#include<vector>
#include<iostream>

class Solution {
public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        long long top = grid[0][0];                             // initialize top to first element in first row
        long long bot = 0;                                      // initialize bottom to zero
        long long ans = LONG_MAX;                               // initialize answer to max value to compare to max of top and bottom

        for(int i=1;i<grid[0].size();++i) top += grid[0][i];    // iterate through first row to accumulate the sum of first row

        for(int i=0;i<grid[0].size();++i){                      // loop through grid to find path taken
            top -= grid[0][i];                                  // subtract current element in top row from top variable
            ans = std::min(ans, std::max(top, bot));            // find max between current top and current bottom and then compare max to current answer
            bot += grid[1][i];                                  // add up elements from bottom row to bottom variable
        }
        return ans;
    }
};

// driver program
int main(){
    // intialize grids
    std::vector<std::vector<int>> grid1 = {
        {2,5,4}, 
        {1,5,1}
    }; 
    std::vector<std::vector<int>> grid2 = {
        {1,3,1,15},
        {1,3,3,1}
    };
    std::vector<std::vector<int>> grid3 = {
        {20,3,20,17,2,12,15,17,4,15},
        {20,10,13,14,15,5,2,3,14,3}
    };

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The max sum that robot 2 can get on grid one is: "<<Solution.gridGame(grid1)<<'\n';
    std::cout<<"The max sum that robot 2 can get on grid two is: "<<Solution.gridGame(grid2)<<'\n';
    std::cout<<"The max sum that robot 2 can get on grid three is: "<<Solution.gridGame(grid3)<<'\n';
    
    return 0;
}