#include <vector>
#include <iostream>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int rows = matrix.size()-1;    // variable to interate through rows
        int cols = matrix[0].size()-1; // variable to iterate through cols
        int l = matrix[0][0];          // begin left at smallest value
        int r = matrix[rows][cols];    // begin right at largest value

        while(l < r){
            int m = l+(r-l) / 2; // set midpoint each loop
            int count = 0;       // start count at 0 each loop to keep track of all elements less than midpoint
            int j = cols;        // start from the top-right corner
            for(int i=0;i<=rows;++i){ // loop through rows
                while(j>=0 && matrix[i][j]>m){ // if the highest value in ith row is greater than midpoint decrement through cols
                    --j;
                }
                count += (j+1); // increment count by jth column plus 1
            }
            if(count < k){ // if count is less than k it means the numbers we counted are less than the midpoint so set left to midpoint plus 1
                l = m+1;
            } 
            else{ // otherwise the numbers we counted are greater than the midpoint so set right to midpoint
                r = m;
            }
        }
        return l; // once the left is equal to the right we have found kth smallest element
    }
};

// Driver program
int main(){
    // initialize matrix and kth variables
    std::vector<std::vector<int>> matrix = {
        {3, 4, 5, 6, 7},
        {10, 12, 12, 12, 21},
        {22, 23, 30, 32, 33},
        {35, 40, 45, 50, 55},
        {60, 70, 80, 90, 100}
    };
    int k1 = 10;
    int k2 = 12;

    // solution class instance
    Solution Solution;

    // output
    std::cout<<"The "<<k1<<"th smallest element in the matrix is: "<<Solution.kthSmallest(matrix, k1)<<'\n';
    std::cout<<"The "<<k2<<"th smallest element in the matrix is: "<<Solution.kthSmallest(matrix, k2)<<'\n';

    return 0;
}