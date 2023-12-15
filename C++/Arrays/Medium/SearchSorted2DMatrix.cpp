#include <vector>
#include <iostream>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size()-1; // intialize row and col variables to traverse matrix
        while(row < matrix.size() && col >= 0){ // while row is less than matrix size and col is greater than or equal to 0
            if(matrix[row][col] == target){ // if we find the target at the row and col indices then return true
                return 1;
            }
            else if(matrix[row][col] < target){ // if the target at the row and col indices is less than the target
                ++row; // we can increment the row index because the columns are sorted
            }
            else{
                --col; // otherwise decrement the col index because the rows are sorted
            }
        }
        return 0; // if we don't find the target return false
    }
};

// Driver program
int main() {
    // initialize matrix and targets
     std::vector<std::vector<int>> matrix = {
        {0,2,3,4},
        {1,4,6,10},
        {3,5,11,12},
        {6,13,17,18}
    };
    int t1 = 5, t2 = 14;

    // solution class instance
    Solution Solution;

    //output
    std::cout<<"Does "<<t1<<" exist in the matrix?: "<<Solution.searchMatrix(matrix, t1)<<'\n';
    std::cout<<"Does "<<t2<<" exist in the matrix?: "<<Solution.searchMatrix(matrix, t2)<<'\n';

    return 0;
}

