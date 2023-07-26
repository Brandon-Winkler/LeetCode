#include <vector>
#include <iostream>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat) {
        // create sum variable to add values
        int sum = 0;

        // first diagonal: add all values with indices where row index == col index
        for(int i = 0; i < mat.size(); ++i) for(int j = 0; j < mat[0].size(); ++j){
            if(i == j) sum += mat[i][j];
        }
        // second diagonal: add all values with indices where row index == numberOfRows - col - 1
        for(int i = 0; i < mat.size(); ++i) for(int j = 0; j < mat[0].size(); ++j) {
            if((i + j) == (mat[0].size() - 1)) {
                if(i == j) continue;
                else sum += mat[i][j];
            }
        }
        return sum;
    }
};

int main() {
    // initialize matrix
   std::vector<std::vector<int>> matrix = {
        {3, 4, 3, 6, 6},
        {2, 2, 2, 2, 2},
        {6, 4, 3, 2, 1},
        {9, 3, 4, 2, 6},
        {5, 7, 6, 8, 9}
    };
    
    // class instance
   Solution Solution;

    // output
    std::cout << Solution.diagonalSum(matrix) << '\n';

    return 0;
}