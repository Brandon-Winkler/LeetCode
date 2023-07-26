#include <iostream>
#include <vector>


class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // return false if matrix is empty
        if (matrix.empty() || matrix[0].empty()) return false;

        // intitialize rows and columns
        int rows = matrix.size();
        int columns = matrix[0].size();

        // create left and right pointers
        int left = 0;
        int right = rows * columns - 1;

        // binary search through matrix
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / columns;
            int col = mid % columns;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main() {

    // matrix initialization
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    // create instance of solution class
    Solution Solution;
    bool result = Solution.searchMatrix(matrix, 3);
    //print results
    std::cout << result << '\n';

    return 0;
}