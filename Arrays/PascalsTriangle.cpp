#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans; // initialize output vector

        for(int i=0;i<numRows;++i){ // loop through number of rows to add vectors
            std::vector<int> row(i+1, 1); // initialize a row with a capacity of the current row plus one and fill it with 1's
            for(int j=1;j<i;++j){ // loop through previous rows
                row[j] = ans[i-1][j] + ans[i-1][j-1]; // add previous rows values and put them at the jth index
            }
            ans.push_back(row); // push current row to output vector
        }
        return ans;
    }
};

// Utility vector
void printVectorOfVectors(const std::vector<std::vector<int>>& vec) {
    for(const std::vector<int>& innerVec : vec){
        for(int num : innerVec){
            std::cout<<num<<" ";
        }
        std::cout << std::endl;
    }
}

// Driver program
int main(){
    // solution class instance
    Solution Solution;

    // store answers in solution vectors
    std::vector<std::vector<int>> six = Solution.generate(6);
    std::vector<std::vector<int>> ten = Solution.generate(10);

    // output
    std::cout<<"Pascals triangle with six rows: "<<'\n';
    printVectorOfVectors(six);
    std::cout<<'\n';
    std::cout<<"Pascals triangle with ten rows: "<<'\n';
    printVectorOfVectors(ten);

    return 0;
}