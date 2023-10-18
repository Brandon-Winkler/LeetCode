#include<stack>
#include<vector>
#include<utility>
#include<iostream>

class Solution {
public:
    void dfs(std::vector<std::vector<int>>& grid, std::stack<std::pair<int,int>>& stk, std::vector<std::vector<bool>>& vis){
        int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};     // direction all vector to check adjacent cells

        while(!stk.empty()){                                // while stack is not empty
            std::pair<int,int> cell = stk.top();            // set cell variable to top of stack
            stk.pop();                                      // pop from stack to continue traversal

            int x = cell.first;                             // set variable to keep track of current row index
            int y = cell.second;                            // set variable to keep treack of current column index

            for(int i=0;i<4;++i){                           // loop through directional vector to check all 4 directions
                int adjx = x+dir[i][0];                     // set variable to track adjacent row
                int adjy = y+dir[i][1];                     // set variable to track adjacent column

                if(                                         // traverse adjacent index and mark visited if...
                    adjx < grid.size() &&                   // adjacent row is less than row size
                    adjy < grid[0].size() &&                // adjacent column is less than  column size
                    adjx >= 0 &&                            // adjacent row is greater than or equal to zero
                    adjy >= 0 &&                            // adjacent column is greater than or equal to zero
                    grid[adjx][adjy] >= grid[x][y] &&       // value in adjacent cell is greater than or equal to value in current cell
                    !vis[adjx][adjy]                        // we haven't visited adjacent cell
                ){
                    stk.push({adjx, adjy});
                    vis[adjx][adjy] = true;
                }
            }
        }    
    }
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        std::stack<std::pair<int,int>> pac, atl;                                        // stacks to dfs through graph
        int ROWS = heights.size();                                                      // row size variable
        int COLS = heights[0].size();                                                   // column size variable
        std::vector<std::vector<int>> ans;                                              // answer vector for output

        if(heights.empty() || heights[0].empty()) return {{}};                          // graph is empty then return empty answer

        std::vector<std::vector<bool>> pacific(ROWS, std::vector<bool>(COLS, false));   // create pacific grid to track which indices can flow to pacific
        std::vector<std::vector<bool>> atlantic(ROWS, std::vector<bool>(COLS, false));  // create atlantic grid to track which indices can flow to atlantic

        for(int r=0;r<ROWS;++r){                                                        // loop through the size of the rows
           pac.push({r, 0});                                                            // push the first column of the grid onto pacific stack
           atl.push({r, COLS-1});                                                       // push last column of the grid onto atlantic stack
           pacific[r][0] = true;                                                        // set upper left corner of the pacific grid to true
           atlantic[r][COLS-1] = true;                                                  // set lower left of the atlantic grid to true
        }

        for(int c=0;c<COLS;++c){                                                        // loop through the size of the columns
            pac.push({0, c});                                                           // push the top row of the grid onto pacific stack
            atl.push({ROWS-1, c});                                                      // push the bottom row of the grid onto atlantic stack
            pacific[0][c] = true;                                                       // set upper right corner of the pacific grid to true
            atlantic[ROWS-1][c] = true;                                                 // set lower right corner of the atlantic grid to true
        }

        dfs(heights, pac, pacific);                                                     // do dfs on heights using the pacific stack to traverse from the top and left and use pacific grid to track visited
        dfs(heights, atl, atlantic);                                                    // do dfs on heights using the atlantic stack to traverse from the bottom and right and use atlantic grid to track visited

        for(int r=0;r<ROWS;++r) for(int c=0;c<COLS;++c){                                // traverse graph
            if(pacific[r][c] && atlantic[r][c]){                                        // if both pacific and atlantic graphs have true for the same index...
                ans.push_back({r,c});                                                   // push index into answer vector
            }
        }
        return ans;
    }
};

// Utility fuction to print vector of vector
void printVector(std::vector<std::vector<int>> v) {
    for (const auto& innerVec : v){
        std::cout<<'[';
        for (const auto& element : innerVec){
            std::cout<<" "<<element;
        }
        std::cout<<" "<<']'<<'\n';
    }
}

// driver program
int main(){
    // initialize graphs
    std::vector<std::vector<int>> g1 = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };

     std::vector<std::vector<int>> g2 = {
        {3,4,2,1,6},
        {1,4,3,7,5},
        {6,3,2,1,1},
        {5,4,6,8,11},
        {7,3,8,9,10}
    };

     std::vector<std::vector<int>> g3 = {
        {1,4}
    };

     std::vector<std::vector<int>> g4 = {
        {}
    };

    // solution class instance
    Solution Solution;

    // solution variables
    std::vector<std::vector<int>> s1 = Solution.pacificAtlantic(g1);
    std::vector<std::vector<int>> s2 = Solution.pacificAtlantic(g2);
    std::vector<std::vector<int>> s3 = Solution.pacificAtlantic(g3);
    std::vector<std::vector<int>> s4 = Solution.pacificAtlantic(g4);

    // outputs
    std::cout<<"Indices that can reach both pacific and atlantic in first graph are: "<<'\n';
    printVector(s1);
    std::cout<<'\n';

    std::cout<<"Indices that can reach both pacific and atlantic in second graph are: "<<'\n';
    printVector(s2);
    std::cout<<'\n';

    std::cout<<"Indices that can reach both pacific and atlantic in thrid graph are: "<<'\n';
    printVector(s3);
    std::cout<<'\n';

    std::cout<<"Indices that can reach both pacific and atlantic in fourth graph are: "<<'\n';
    printVector(s4);
    std::cout<<'\n';

    return 0;
}