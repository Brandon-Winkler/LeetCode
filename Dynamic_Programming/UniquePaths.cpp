#include<vector>
#include<iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1)); // initialize 2d array and fill with ones
        
        // loop through matrix but begin at (1, 1) since the first row and col have already been initialized         
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){ 
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // to find unique paths sum the numbers in the indices above and to the left of the current index
            }
        }
        return dp[m-1][n-1]; // return the final sum in the last row and last col index
    }
};

// driver program
int main(){
    // intialize rows and cols
    int rows = 5;
    int cols = 6;
    int r = 15;
    int c = 20;

    std::cout<<"The number of unique paths for the first matrix is "<<;
    return 0;
}