#include <vector>
#include <iostream>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        // iterate through matrix rows and columns
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = i; j < matrix.size(); ++j) {
                // swap indices
                std::swap(matrix[i][j], matrix[j][i]);
            }
            // reverse rows
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// utility function for printing a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    // initialize matrix
    std::vector<std::vector<int>> matrix = {
        {3, 4, 3, 6, 6},
        {2, 2, 2, 2, 2},
        {6, 4, 3, 2, 1},
        {9, 3, 4, 2, 6},
        {5, 7, 6, 8, 9}
    };

    std::cout << "original matrix: " << '\n';
    printMatrix(matrix);

    // solution class and rotation
    Solution Solution;
    Solution.rotate(matrix);

    std::cout << "rotated matrix: " << '\n';
    printMatrix(matrix);

    return 0;
}