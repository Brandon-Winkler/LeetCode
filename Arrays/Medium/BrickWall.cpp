#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

class Solution {
public:
    int leastBricks(std::vector<std::vector<int>>& wall) {
        std::map<int, int> map;                    // create frequency map to track sum occurences
        int rows = 0;                              // initialize a variable to keep track of greatest occurences of sums

        for(int r=0;r<wall.size();++r){
            int sum = 0;                           // create sum variable to sum numbers in each row
            for(int c=0;c<wall[r].size()-1;++c){
                sum += wall[r][c];                 // accumulate each sum one by one at each value in the row
                rows = std::max(rows, ++map[sum]); // simultaneously compare the current number of rows and the frequency of the latest sum and store the greater of the two into rows variable
            }
        }
        return wall.size() - rows;                 // the greatest frequency in the sum frequency map will be the the number of rows to subtract
    }
};

// driver program
int main(){
    // initialize walls
    std::vector<std::vector<int>> w1 = {
        {5,2},
        {3,1,2,1},
        {1,3,1,2},
        {2,3,2},
        {5,2},
        {3,4},
        {1,1,1,4},
        {7},
        {2,3,2},
        {1,1,1,1,1,1,1}
    };
    std::vector<std::vector<int>> w2 = {
        {4,3},
        {2,2,3},
        {1,1,3,2},
        {3,4},
        {4,3},
        {2,5}
    };

    // create solution class instance
    Solution Solution;

    // output
    std::cout<<"The minimum number of bricks crossed in wall one is: "<<Solution.leastBricks(w1)<<'\n';
    std::cout<<"The minimum number of bricks crossed in wall two is: "<<Solution.leastBricks(w2)<<'\n';
    
    return 0;
}