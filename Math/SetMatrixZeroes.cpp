#include<iostream>
#include<vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<bool> zeroRows(rows, false);
        std::vector<bool> zeroCols(cols, false);

        // First pass: Identify zero rows and columns
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(matrix[row][col] == 0){
                    zeroRows[row] = true;
                    zeroCols[col] = true;
                }
            }
        }
        // Second pass: Set zero rows and columns to zero
        for(int row=0;row<rows;++row){
            for(int col=0;col<cols;++col){
                if(zeroRows[row] || zeroCols[col]){
                    matrix[row][col] = 0;
                }
            }
        }
    }
};

// utility function for printing a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for(const auto& row : matrix){
        for(int element : row){
            std::cout<<element<<" ";
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

// driver program
int main(){
    // initialize matrix
    std::vector<std::vector<int>> matrix = {
        {3, 4, 3, 6, 6},
        {2, 2, 0, 2, 2},
        {6, 4, 3, 2, 0},
        {9, 3, 4, 2, 6},
        {0, 7, 6, 8, 9}
    };

    // solution class instance
    Solution Solution;

    std::cout<<"Matrix before setting zeroes:"<<'\n';
    printMatrix(matrix);
    std::cout<<'\n';

    Solution.setZeroes(matrix);

    std::cout<<"Matrix after setting zeroes: "<<'\n';
    printMatrix(matrix);
    
    return 0;
}
