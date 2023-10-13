#include<vector>
#include<stack>
#include<utility>
#include<iostream>

class Solution {
public:
    int dfs(std::vector<std::vector<int>>& grid, int rIdx, int cIdx){
        int sum = 1;                                    // create a sum variable and initialze with 1 to account for current cell visited
        grid[rIdx][cIdx] = 0;                           // set current cell to 0 to mark that it has been visited

        std::stack<std::pair<int,int>> indices;         // create stack to keep track of indices to visit
        indices.push({rIdx,cIdx});                      // push indices onto stack to begin dfs

        int dRow[] = {-1, 0, 1, 0};                     // directional vector for rows
        int dCol[] = {0, 1, 0, -1};                     // directional vector for columns

        while(!indices.empty()){                        // do dfs while stack not empty
            std::pair<int,int> cell = indices.top();    // create pair variable to access current index at top of stack
            int x = cell.first;                         // set x variable to current row index
            int y = cell.second;                        // set y variable to current column index

            indices.pop();                              // pop from stack to make sure we don't visit this cell again

            for(int i=0;i<4;++i){                       // loop through directional vectors to check adjacent cells
                int adjx = x+dRow[i];                   // set adjacent x variable to current index plus value in directional vector to check adjacent row
                int adjy = y+dCol[i];                   // set adjacent y variable to current index plus value in directional vector to check adjacent column

                if(                                     // do not traverse if...
                    adjx >= grid.size() ||              // adjacent row index is too high or
                    adjy >= grid[0].size() ||           // adjacent column index is too high or
                    adjx < 0 ||                         // adjacent row index is too low or
                    adjy < 0                            // adjacent column index is too low
                ){
                    continue;
                }
                else if(grid[adjx][adjy] == 0){         // also don't traverse if we have already visited the cell
                    continue;
                }
                else{                                   // otherwise...
                    sum += grid[adjx][adjy];            // add what is in adjacent cells to current sum
                    grid[adjx][adjy] = 0;               // set adjacent cells to 0 to mark that we have visited them
                    indices.push({adjx, adjy});         // push adjacent cells onto stack to continue traversal
                }
            }
        }
        return sum;                                     // return sum of island traversed
    }
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int area = 0;                                                       // initialize current area to 0

        for(int r=0;r<grid.size();++r) for(int c=0;c<grid[0].size();++c){   // loop through matrix
            if(grid[r][c] == 1){                                            // if cell has a 1 in it
                area = std::max(area, dfs(grid, r, c));                     // set area to the max between current area and the sum given from dfs
            }
        }
        return area;                                                        // return max area
    }
};

// driver program
int main(){
    //initialize graphs
    std::vector<std::vector<int>> g1 = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
     std::vector<std::vector<int>> g2 = {
        {0,1,0,0,1},
        {0,1,0,0,0},
        {0,1,1,0,0},
        {0,1,0,0,1},
        {1,0,0,1,1},
        
    };

    // solution class instance
    Solution Solution;

    //outputs
    std::cout<<"The biggest island in graph one has an area of "<<Solution.maxAreaOfIsland(g1)<<'\n';
    std::cout<<"The biggest island in graph two has an area of "<<Solution.maxAreaOfIsland(g2)<<'\n';
    return 0;
}