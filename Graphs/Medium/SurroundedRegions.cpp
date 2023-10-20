#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, stack<pair<int,int>>& stk, vector<vector<bool>>& vis){
        int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};     // directional vector to traverse grid

        while(!stk.empty()){                                // while the stack is not empty
            pair<int,int> cell = stk.top();                 // set cell variable to top of stack
            stk.pop();                                      // pop from stack to continue traversal
            int r = cell.first;                             // set row variable
            int c = cell.second;                            // set column variable
            vis[r][c] = true;                               // set visited to true so we don't loop infinitely

            for(int i=0;i<4;++i){                           // traverse using directional vector
                int adjr = r+dir[i][0];                     // set variable to adjacent row
                int adjc = c+dir[i][1];                     // set variable to adjacent column

                if(                                         // do not traverse if...
                    adjr < 0 ||                             // adjacent row is less than 0
                    adjc < 0 ||                             // adjacent column is less than 0
                    adjr >= grid.size() ||                  // adjacent row is greater than or equal to grid size
                    adjc >= grid[0].size() ||               // adjacent column is greater than or equal to grid size
                    vis[adjr][adjc] == true ||              // we have already visited the cell
                    grid[adjr][adjc] == 'X'                 // the adjacent cell has an X in it
                ){
                    continue;
                }
                else{                                       // otherwise set visited to true and push index onto stack to continue traversal
                    vis[r][c] = true;
                    stk.push({adjr, adjc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        stack<pair<int,int>> indices;                                               // initialize stack to hold indices
        int rows = board.size();                                                    // set variable for rows
        int cols = board[0].size();                                                 // set variable for columns
        vector<vector<bool>> lut(rows, vector<bool>(cols, false));                  // create lookup table for keeping track of which cells shouldn't be flipped

        for(int c=0;c<cols;++c){                                                    // loop through columns
            if(board[0][c] == 'O') indices.push({0, c});                            // if cell in first row contains an O then push its index onto stack
            if(board[rows-1][c] == 'O') indices.push({rows-1, c});                  // if cell in last row contains an O then push its index onto stack
        }

        for(int r=0;r<rows;++r){                                                    // loop through rows
            if(board[r][0] == 'O') indices.push({r, 0});                            // if cell in first column contains an O then push its index onto stack
            if(board[r][cols-1] == 'O') indices.push({r, cols-1});                  // if cell in last column contain an O then push its index onto stack
        }

        dfs(board, indices, lut);                                                   // perform dfs to update lookup table

        for(int r=0;r<rows;++r) for(int c=0;c<cols;++c){                            // loop through board: if there is a O with a correlating false statement flip that cell to an X
            if(board[r][c] == 'O' && lut[r][c] == false) board[r][c] = 'X';
        }
        return;
    }
};

// utility function for printing a matrix
void printMatrix(const vector<vector<char>>& matrix){
    for(const auto& row : matrix){
        for(char element : row){
            cout<<element<< " ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

// driver program
int main(){
    // initialize boards
    vector<vector<char>> b1 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    vector<vector<char>> b2 = {
        {'O','O','O','O'},
        {'O','O','O','O'},
        {'O','O','O','O'},
        {'O','O','O','O'}
    };

    vector<vector<char>> b3 = {
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','X','X','X'},
        {'X','X','X','X'}
    };

    vector<vector<char>> b4 = {
        {'X','X','O','X'},
        {'X','X','O','O'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','X','X','X'}

    };

    // solution class instance
    Solution Solution;

    cout<<"Boards before flipping:"<<'\n';
    printMatrix(b1);
    cout<<'\n';
    printMatrix(b2);
    cout<<'\n';
    printMatrix(b3);
    cout<<'\n';
    printMatrix(b4);
    cout<<'\n';

    Solution.solve(b1);
    Solution.solve(b2);
    Solution.solve(b3);
    Solution.solve(b4);

    cout<<"Boards after flipping:"<<'\n';
    printMatrix(b1);
    cout<<'\n';
    printMatrix(b2);
    cout<<'\n';
    printMatrix(b3);
    cout<<'\n';
    printMatrix(b4);
    cout<<'\n';

    return 0;
}