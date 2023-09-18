#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int matrixSum(std::vector<std::vector<int>>& nums){
        int score = 0; // set score to zero to initialize
        for(int r=0;r<nums.size();++r){ // loop through columns to sort them 
            std::sort(nums[r].begin(), nums[r].end(), std::greater<int>());
        }
        for(int c=0;c<nums[0].size();++c){ // go column by column to find max's in all columns
            int max = 0; // set max to zero initially to keep track of max's
            for(int r=0;r<nums.size();++r){
                max = std::max(max, nums[r][c]); // compare current max to index in matrix and set new max to the greater of the two
            }
            score += max; // add max's to scores
        }
        return score;
    }
};

// Driver Program
int main(){
    // initialize matrix
    std::vector<std::vector<int>> matrix = {
        {5,6,3},
        {9,2,1},
        {0,3,8},
        {6,4,2}
    };

    // create solution class instance

    return 0;
}