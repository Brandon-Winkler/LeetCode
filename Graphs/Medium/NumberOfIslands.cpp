#include<vector>
#include<utility>
#include<queue>
#include<iostream>

const int dRow[] = {-1, 0, 1, 0}; // directional row vector
const int dCol[] = {0, 1, 0, -1}; // directional column vector

class Solution {
public:
    void bfs(std::vector<std::vector<char>>& grid, int rIdx, int cIdx){
        grid[rIdx][cIdx] = '0';                             // set current value at current index to zero

        std::queue<std::pair<int,int>> indices;             // create a queue to hold indices for bfs
        indices.push({rIdx,cIdx});                          // push current indices onto que to begin bfs

        while(!indices.empty()){                            // while que is not empty do bfs
            std::pair<int,int> cell = indices.front();      // create variable to set to front of que
            int x = cell.first;                             // create variable to keep track of row value of index
            int y = cell.second;                            // create variable to keep track of column value of index

            indices.pop();                                  // pop from index que to continue traversal

            for(int i=0;i<4;++i){                           // loop through directional vectors
                int adjx = x+dRow[i];                       // seek adjacent rows
                int adjy = y+dCol[i];                       // seek adjacent columns
                if(                                         // don't traverse if...
                    adjx >= grid.size() ||                  // adjacent row is greater than row size
                    adjy >= grid[0].size() ||               // adjacent column is greater than column size
                    adjx < 0 ||                             // adjacent row is less than zero
                    adjy < 0                                // adjacent column is less than zero
                ){
                    continue;
                }
                else if(grid[adjx][adjy] == '0'){           // don't traverse if adjacent cell is zero
                    continue;
                }
                else{                                       // otherwise set adjacent cells to 0 and push them into the que
                    grid[adjx][adjy] = '0';
                    indices.push({adjx, adjy});
                }
            }
        }
    }
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;                              // initialize count variable to zero

        for(int r=0;r<grid.size();++r){             // loop through rows
            for(int c=0;c<grid[0].size();++c){      // loop through columns
                if(grid[r][c] == '1'){              // if value at current index is one increase count and do bfs
                    ++count;
                    bfs(grid, r, c);
                }
            }
        }
        return count;
    }
};

// driver program
int main(){
    // initialize graphs
    std::vector<std::vector<char>> g1 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
     std::vector<std::vector<char>> g2 = {
        {'0','1','0','0','1'},
        {'0','1','0','0','0'},
        {'0','1','1','0','0'},
        {'0','1','0','0','1'},
        {'1','0','0','1','1'},
        
    };

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The number of islands in graph one is "<<Solution.numIslands(g1)<<'\n';
    std::cout<<"The number of islands in graph two is "<<Solution.numIslands(g2)<<'\n';
    
    return 0;
}
